from flask import Flask, request, jsonify, render_template
import tempfile
import os
import shutil
from pathlib import Path
import lizard
import logging
from datetime import datetime

from core import compile_source, get_run_cmd, run_with_memory, MemoryLimitPlugin, CpuUsagePlugin

# 로깅 설정
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

app = Flask(__name__)
app.config['MAX_CONTENT_LENGTH'] = 16 * 1024 * 1024  # 16MB 파일 크기 제한

# 지원하는 파일 확장자
ALLOWED_EXTENSIONS = {'.c', '.cpp', '.cc', '.cxx', '.java', '.py'}

def allowed_file(filename):
    """파일 확장자 검증"""
    return Path(filename).suffix.lower() in ALLOWED_EXTENSIONS

def cleanup_directory(directory):
    """디렉토리 안전하게 삭제"""
    try:
        shutil.rmtree(directory)
    except Exception as e:
        logger.error(f"Failed to cleanup directory {directory}: {e}")

@app.route("/")
def index():
    """메인 페이지"""
    return render_template("index.html")

@app.route("/run_single", methods=["POST"])
def run_single():
    """단일 실행 - 에디터의 코드를 stdin과 함께 실행"""
    tmpdir = None
    try:
        # 요청 데이터 검증
        code = request.form.get("code")
        if not code:
            return jsonify({"error": "No code provided"}), 400
            
        filename = request.form.get("filename", "temp.cpp")
        if not allowed_file(filename):
            return jsonify({"error": "Invalid file type"}), 400
            
        language = request.form.get("language", "cpp")
        stdin_data = request.form.get("stdin", "")
        
        # 임시 디렉토리 생성
        tmpdir = tempfile.mkdtemp(prefix="submission_")
        filepath = os.path.join(tmpdir, filename)
        
        # 코드를 파일로 저장
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(code)
        
        logger.info(f"Running single execution for {filename}")
        
        # 컴파일
        lang, run_target, workdir = compile_source(filepath)
        cmd = get_run_cmd(lang, run_target)
        
        # 실행 (stdin 데이터 포함)
        exit_code, stdout, stderr, elapsed, metrics = run_with_memory(
            cmd,
            stdin_data=stdin_data,
            cwd=workdir,
            timeout=10,  # 10초로 증가
            plugins=[
                MemoryLimitPlugin(limit_bytes=256 * 1024 * 1024),  # 256MB
                CpuUsagePlugin(),
            ],
        )
        
        return jsonify({
            "success": True,
            "lang": lang,
            "exit_code": exit_code,
            "stdout": stdout,
            "stderr": stderr,
            "elapsed_sec": elapsed,
            "metrics": metrics,
            "timestamp": datetime.now().isoformat()
        })
        
    except Exception as e:
        logger.error(f"Error in run_single: {str(e)}")
        return jsonify({"success": False, "error": str(e)}), 500
        
    finally:
        if tmpdir:
            cleanup_directory(tmpdir)

@app.route("/run_batch", methods=["POST"])
def run_batch():
    """배치 실행 - 지정된 폴더의 .in과 기대 출력(.out/.ans 등) 비교"""
    import difflib, re

    def normalize(text: str, mode: str = "trim") -> str:
        text = text.replace("\r\n", "\n").replace("\r", "\n")
        if mode == "exact":
            return text
        if mode == "trim":
            return "\n".join(line.rstrip() for line in text.strip().splitlines())
        if mode in ("ignore-ws", "ws"):
            import re as _re
            return "\n".join(_re.sub(r"\s+", " ", line).strip() for line in text.splitlines()).strip()
        return text

    def find_expected(in_file: Path, cand_exts: list[str], expected_prefix: str | None):
        """
        기대 출력 후보를 순서대로 탐색:
          1) 동일 stem + .out/.ans
          2) 숫자만 + .out/.ans (input1.in -> 1.out)
          3) expected_prefix + 숫자 + .out/.ans (요청 파라미터나 추론된 'output')
          4) 'input{num}' 패턴이면 'output{num}'도 시도
          5) 하위 폴더 out/, output/, answers/에서도 1~4 반복
        """
        def try_paths(dirpath: Path, stems: list[str]) -> tuple[bool, str, Path | None]:
            for stem in stems:
                for ext in cand_exts:
                    ext = ext if ext.startswith(".") else "." + ext
                    cand = dirpath / f"{stem}{ext}"
                    if cand.exists():
                        try:
                            return True, cand.read_text(encoding="utf-8", errors="ignore"), cand
                        except Exception:
                            return True, "", cand
            return False, "", None

        stem = in_file.stem  # e.g. input1
        # 기본 후보 stem들
        candidates = [stem]
        # 숫자 추출
        m = re.match(r"^(.*?)(\d+)$", stem)
        base, num = (m.group(1), m.group(2)) if m else (stem, None)
        if num:
            candidates.append(num)  # 1.out

        # 요청에서 expected_prefix를 받았다면 우선 사용
        if expected_prefix and num:
            candidates.append(f"{expected_prefix}{num}")

        # input{num} -> output{num} 자동 매핑 지원
        if num and (base.lower().endswith("input") or base.lower().startswith("input")):
            candidates.append(f"output{num}")

        # 중복 제거 순서 유지
        seen = set()
        candidates = [s for s in candidates if not (s in seen or seen.add(s))]

        # 1차: 같은 폴더에서 탐색
        ok, content, path = try_paths(in_file.parent, candidates)
        if ok:
            return ok, content, path

        # 2차: 하위 폴더(out/, output/, answers/)에서 탐색
        for sub in ("out", "output", "answers"):
            subdir = in_file.parent / sub
            if subdir.is_dir():
                ok, content, path = try_paths(subdir, candidates)
                if ok:
                    return ok, content, path

        return False, "", None

    tmpdir = None
    try:
        code = request.form.get("code")
        if not code:
            return jsonify({"error": "No code provided"}), 400

        filename = request.form.get("filename", "temp.cpp")
        if not allowed_file(filename):
            return jsonify({"error": "Invalid file type"}), 400

        batch_folder = (request.form.get("folder") or "").strip()
        if not batch_folder or not os.path.isdir(batch_folder):
            return jsonify({"error": "Invalid or missing batch folder"}), 400

        compare_mode = (request.form.get("compare") or "trim").strip()
        expected_exts = request.form.get("expected_exts", ".out,.ans")
        expected_ext_list = [e.strip() for e in expected_exts.split(",") if e.strip()]
        expected_prefix = (request.form.get("expected_prefix") or "").strip()  # 예: 'output'

        # 코드 저장/컴파일
        tmpdir = tempfile.mkdtemp(prefix="submission_")
        filepath = os.path.join(tmpdir, filename)
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(code)
        lang, run_target, workdir = compile_source(filepath)
        cmd = get_run_cmd(lang, run_target)

        in_files = sorted(Path(batch_folder).glob("*.in"))
        results = []
        passed_tests = 0
        failed_tests = 0
        missing_expected = 0

        for in_file in in_files:
            expected_exists, expected_output, expected_path = find_expected(
                in_file, expected_ext_list, expected_prefix
            )

            try:
                stdin_data = in_file.read_text(encoding="utf-8", errors="ignore")
            except Exception:
                stdin_data = ""

            exit_code, stdout, stderr, elapsed, metrics = run_with_memory(
                cmd,
                stdin_data=stdin_data,
                cwd=workdir,
                timeout=5,
                plugins=[MemoryLimitPlugin(limit_bytes=256 * 1024 * 1024), CpuUsagePlugin()],
            )

            if expected_exists:
                norm_stdout = normalize(stdout, compare_mode)
                norm_expected = normalize(expected_output, compare_mode)
                passed = norm_stdout == norm_expected
                if passed:
                    passed_tests += 1
                    diff_preview = ""
                else:
                    failed_tests += 1
                    diff_lines = list(difflib.unified_diff(
                        norm_expected.splitlines(),
                        norm_stdout.splitlines(),
                        fromfile=f"{expected_path.name}(expected)",
                        tofile=f"{in_file.name}(actual)",
                        lineterm=""
                    ))
                    diff_preview = "\n".join(diff_lines[:200])
            else:
                passed = None
                diff_preview = ""
                missing_expected += 1

            results.append({
                "test_case": in_file.name,
                "passed": passed,  # True/False/None
                "expected_exists": expected_exists,
                "expected_path": str(expected_path) if expected_path else "",
                "compare_mode": compare_mode,
                "exit_code": exit_code,
                "elapsed_sec": elapsed,
                "metrics": metrics,
                "stderr": stderr,
                "stdout": stdout,
                "expected": expected_output if expected_exists else "",
                "diff": diff_preview
            })

        return jsonify({
            "success": True,
            "results": results,
            "total_tests": len(results),
            "passed_tests": passed_tests,
            "failed_tests": failed_tests,
            "missing_expected": missing_expected,
            "timestamp": datetime.now().isoformat()
        })

    except Exception as e:
        logger.error(f"Error in run_batch: {str(e)}")
        return jsonify({"success": False, "error": str(e)}), 500
    finally:
        if tmpdir:
            cleanup_directory(tmpdir)

@app.route("/reload", methods=["POST"])
def reload_source():
    """소스 파일 다시 불러오기"""
    try:
        if "file" not in request.files:
            return jsonify({"error": "No file uploaded"}), 400
            
        file = request.files["file"]
        if not allowed_file(file.filename):
            return jsonify({"error": "Invalid file type"}), 400
        
        # Totally... BULLSHIT...
        with tempfile.NamedTemporaryFile(delete=False) as tmp:
            file.save(tmp)
            tmp_path = tmp.name # FUCK YOU
        
        with open(tmp_path, "r", encoding="utf-8") as f:
            content = f.read()
        
        return jsonify({
            "success": True,
            "filename": file.filename,
            "content": content,
            "language": Path(file.filename).suffix.lower()[1:]  # 확장자에서 언어 추출
        })
        
    except Exception as e:
        logger.error(f"Error in reload_source: {str(e)}")
        return jsonify({"success": False, "error": str(e)}), 500

@app.route("/analyze", methods=["POST"])
def analyze_code():
    """Lizard를 사용한 코드 복잡도 분석 (버전 안전)"""
    temp_path = None
    try:
        code = request.form.get("code")
        if not code:
            return jsonify({"error": "No code provided"}), 400

        filename = request.form.get("filename", "temp.cpp")
        suffix = Path(filename).suffix or ".txt"  # temp 파일의 확장자만 사용

        # 임시 파일 생성
        with tempfile.NamedTemporaryFile(mode='w', suffix=suffix, delete=False, encoding='utf-8') as f:
            f.write(code)
            temp_path = f.name

        # Lizard 분석
        analysis = lizard.analyze_file(temp_path)
        funcs = analysis.function_list or []

        functions = []
        total_complexity = 0
        total_tokens = 0
        total_loc = 0

        for func in funcs:
            complexity = getattr(func, "cyclomatic_complexity", 0) or 0
            loc = getattr(func, "nloc", 0) or 0
            tokens = getattr(func, "token_count", 0) or 0
            params = getattr(func, "parameter_count", 0) or 0

            total_complexity += complexity
            total_tokens += tokens
            total_loc += loc

            functions.append({
                "name": getattr(func, "long_name", None) or getattr(func, "name", "<unknown>"),
                "complexity": complexity,
                "loc": loc,
                "tokens": tokens,
                "params": params,
                "start_line": getattr(func, "start_line", None),
                "end_line": getattr(func, "end_line", None),
            })

        fn_count = len(funcs)
        # 평균값은 lizard가 제공하면 사용하고, 없으면 우리가 계산
        avg_cc_from_lizard = getattr(analysis, "average_cyclomatic_complexity", None)
        avg_nloc_from_lizard = getattr(analysis, "average_nloc", None)

        average_complexity = round(avg_cc_from_lizard if avg_cc_from_lizard is not None
                                   else (total_complexity / fn_count if fn_count else 0), 2)
        average_nloc = round(avg_nloc_from_lizard if avg_nloc_from_lizard is not None
                             else (total_loc / fn_count if fn_count else 0), 2)
        average_token = round((total_tokens / fn_count) if fn_count else 0, 2)

        result = {
            "success": True,
            "file_stats": {
                "filename": filename,
                "nloc": getattr(analysis, "nloc", total_loc),
                "average_complexity": average_complexity,
                "average_nloc": average_nloc,
                "average_token": average_token,  # 우리가 계산한 값
                "total_functions": fn_count,
                "total_complexity": total_complexity,
            },
            "functions": sorted(functions, key=lambda x: x["complexity"], reverse=True),
            "timestamp": datetime.now().isoformat()
        }

        return jsonify(result)

    except Exception as e:
        app.logger.error(f"Error in analyze_code: {e}")
        return jsonify({"success": False, "error": str(e)}), 500

    finally:
        if temp_path and os.path.exists(temp_path):
            try:
                os.unlink(temp_path)
            except Exception:
                pass

@app.route("/health")
def health():
    """헬스 체크 엔드포인트"""
    return jsonify({
        "status": "ok",
        "timestamp": datetime.now().isoformat(),
        "version": "1.0.0"
    })

@app.errorhandler(413)
def request_entity_too_large(error):
    """파일 크기 초과 에러 핸들러"""
    return jsonify({"error": "File too large. Maximum size is 16MB"}), 413

@app.errorhandler(500)
def internal_error(error):
    """내부 서버 에러 핸들러"""
    logger.error(f"Internal server error: {error}")
    return jsonify({"error": "Internal server error"}), 500

if __name__ == "__main__":
    # 개발 서버 실행
    app.run(port=5000, debug=True)