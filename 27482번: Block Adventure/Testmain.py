from pathlib import Path
import importlib.util
import sys, io

MODULE_FILE = "Block Adventure.py"

def load_user_module(file_name: str):
    file_path = Path(__file__).with_name(file_name).resolve()
    if not file_path.exists():
        raise FileNotFoundError(file_path)
    spec = importlib.util.spec_from_file_location("user_solution", file_path)
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module

# test_solution.py 중 run_io() 부분만 수정
def run_io(inp: str, file_name: str = MODULE_FILE) -> str:
    mod = load_user_module(file_name)          # ← 공백 포함 파일 로드
    stdin_orig, stdout_orig = sys.stdin, sys.stdout

    # ① 바이트 기반 버퍼
    bytes_io = io.BytesIO(inp.encode())
    # ② TextIOWrapper → .buffer 속성이 bytes_io이므로 solution.py와 호환
    sys.stdin = io.TextIOWrapper(bytes_io, encoding="utf-8")
    sys.stdout = io.StringIO()

    try:
        mod.main()                             # 사용자가 작성한 main 실행
        return sys.stdout.getvalue()
    finally:
        sys.stdin, sys.stdout = stdin_orig, stdout_orig


def test_sample():
    inp = """\
5
3 0 1
4 3 5
3 1 2
1 4 7
4 10 0
10 20 10 20
2 5 5
0 11
1 9 9
99
"""
    exp = """\
YES
NO
YES
NO
YES"""
    assert run_io(inp) == exp