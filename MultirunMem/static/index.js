// 언어 매핑 테이블
const extensionToLang = {
    "c": "c",
    "cpp": "cpp",
    "cc": "cpp",
    "cxx": "cpp",
    "java": "java",
    "py": "python"
};

// Monaco Editor가 로드될 때까지 기다리는 함수
function waitForEditor() {
    return new Promise((resolve) => {
        const checkInterval = setInterval(() => {
            if (window.editor) {
                clearInterval(checkInterval);
                resolve();
            }
        }, 100);
    });
}

// 파일 업로드 설정
function setupFileUpload() {
    const fileInput = document.getElementById("file");
    if (!fileInput) return;

    fileInput.addEventListener("change", async (event) => {
        const file = event.target.files[0];
        if (!file) return;

        const ext = file.name.split(".").pop().toLowerCase();
        const lang = extensionToLang[ext] || "plaintext";

        try {
            const text = await file.text();
            await waitForEditor();

            window.editor.setValue(text);
            monaco.editor.setModelLanguage(window.editor.getModel(), lang);
        } catch (error) {
            console.error("파일 읽기 오류:", error);
            alert("파일을 읽는 중 오류가 발생했습니다.");
        }
    });
}

// 실행 결과를 탭에 표시하는 함수
function displayExecutionResults(result) {
    const outputContent = document.getElementById('outputContent');
    outputContent.textContent = result.stdout || '(출력 없음)';

    const errorContent = document.getElementById('errorContent');
    if (result.stderr || result.exit_code !== 0) {
        errorContent.textContent = result.stderr || `프로그램이 종료 코드 ${result.exit_code}로 종료되었습니다.`;
    } else {
        errorContent.textContent = '에러 없음';
    }

    if (result.elapsed_sec && result.metrics) {
        const executionInfo = `\n\n--- 실행 정보 ---\n` +
            `실행 시간: ${result.elapsed_sec.toFixed(3)}초\n` +
            `메모리 사용량: ${result.metrics['Peak RSS'] || 'N/A'}\n` +
            `CPU 사용률: ${result.metrics['CPU Avg'] || 'N/A'}`;
        outputContent.textContent += executionInfo;
    }
}

// 분석 결과 표시 함수
function displayAnalysis(data) {
    const content = `
        <h6>🦎 Lizard Code Analysis</h6>
        <div class="mb-3">
            <strong>File Overview</strong>
            <table class="table table-sm">
                <tr><td>Total Lines</td><td>${data.file_stats.nloc}</td></tr>
                <tr><td>Average Complexity</td><td>${data.file_stats.average_complexity.toFixed(2)}</td></tr>
                <tr><td>Total Functions</td><td>${data.file_stats.total_functions}</td></tr>
            </table>
        </div>
        <div>
            <strong>Function Details</strong>
            <table class="table table-sm table-hover">
                <thead>
                    <tr>
                        <th>Function</th>
                        <th>Complexity</th>
                        <th>Lines</th>
                        <th>Location</th>
                    </tr>
                </thead>
                <tbody>
                    ${data.functions.map(f => `
                        <tr class="${f.complexity > 10 ? 'table-warning' : ''}">
                            <td>${f.name}</td>
                            <td>${f.complexity}</td>
                            <td>${f.loc}</td>
                            <td>L${f.start_line}-${f.end_line}</td>
                        </tr>
                    `).join('')}
                </tbody>
            </table>
        </div>
    `;
    document.getElementById("analysisContent").innerHTML = content;
}

// Run Single 실행 함수
async function runSingleExecution() {
    if (!window.editor) {
        alert("에디터가 준비되지 않았습니다.");
        return;
    }

    const code = window.editor.getValue();
    const language = window.editor.getModel().getLanguageId();
    const stdin = document.getElementById("stdinInput").value;

    const extensions = {
        'c': '.c',
        'cpp': '.cpp',
        'java': '.java',
        'python': '.py'
    };

    const filename = `temp_code${extensions[language] || '.txt'}`;

    try {
        const runBtn = document.getElementById('runSingleBtn');
        const originalText = runBtn.textContent;
        runBtn.disabled = true;
        runBtn.innerHTML = '<span class="spinner-border spinner-border-sm me-2"></span>실행 중...';

        const formData = new FormData();
        formData.append('code', code);
        formData.append('filename', filename);
        formData.append('language', language);
        formData.append('stdin', stdin);

        const response = await fetch('/run_single', {
            method: 'POST',
            body: formData
        });

        const result = await response.json();

        if (response.ok) {
            displayExecutionResults(result);

            const modal = bootstrap.Modal.getInstance(document.getElementById('stdinModal'));
            modal.hide();

            const outputTab = new bootstrap.Tab(document.getElementById('output-tab'));
            outputTab.show();
        } else {
            alert('실행 중 오류 발생: ' + (result.error || '알 수 없는 오류'));
        }

    } catch (error) {
        console.error('Execution error:', error);
        alert('실행 요청 중 오류가 발생했습니다.');
    } finally {
        const runBtn = document.getElementById('runSingleBtn');
        runBtn.disabled = false;
        runBtn.textContent = '실행';
    }
}

// 코드 분석 함수
async function analyzeCode() {
    if (!window.editor) {
        alert("에디터가 준비되지 않았습니다.");
        return;
    }

    const code = window.editor.getValue();
    const language = window.editor.getModel().getLanguageId();

    const extensions = {
        'c': '.c',
        'cpp': '.cpp',
        'java': '.java',
        'python': '.py'
    };

    const filename = `temp_analysis${extensions[language] || '.txt'}`;

    try {
        const analysisBtn = document.getElementById('analysisBtn');
        analysisBtn.disabled = true;
        analysisBtn.innerHTML = '<span class="spinner-border spinner-border-sm me-2"></span>분석 중...';

        const formData = new FormData();
        formData.append('code', code);
        formData.append('filename', filename);
        formData.append('language', language);

        const response = await fetch('/analyze', {
            method: 'POST',
            body: formData
        });

        const data = await response.json();

        if (response.ok) {
            displayAnalysis(data);
            const analysisTab = new bootstrap.Tab(document.getElementById('analysis-tab'));
            analysisTab.show();
        } else {
            alert('분석 중 오류 발생: ' + data.error);
        }
    } catch (error) {
        console.error("Analysis error:", error);
        alert('분석 요청 중 오류가 발생했습니다.');
    } finally {
        const analysisBtn = document.getElementById('analysisBtn');
        analysisBtn.disabled = false;
        analysisBtn.textContent = 'Analysis Source Code';
    }
}

const langIdToExt = {
    c: '.c',
    cpp: '.cpp',
    java: '.java',
    python: '.py'
};

function displayBatchResults(data) {
    const outputPre = document.getElementById('outputContent');
    const expectedPre = document.getElementById('expectedOutput');
    const actualPre = document.getElementById('actualOutput');

    if (!data || !Array.isArray(data.results) || data.results.length === 0) {
        outputPre.textContent = '테스트 케이스(.in)를 찾지 못했습니다. 폴더 경로와 파일을 확인하세요.';
        return;
    }

    const lines = [];
    lines.push(`[Batch Result] ${data.passed_tests}/${data.total_tests} passed`);
    lines.push('');

    data.results.forEach((r, idx) => {
        const status = r.passed === true ? 'PASS' : (r.passed === false ? 'FAIL' : 'N/A');
        const time = typeof r.elapsed_sec === 'number' ? r.elapsed_sec.toFixed(3) : '-';
        lines.push(`${idx + 1}. ${r.test_case} - ${status} - exit:${r.exit_code} - ${time}s`);
        if (r.passed === false) {
            const exp = (r.expected || '').trim().split('\n').slice(0, 3).join('\n');
            const act = (r.stdout || '').trim().split('\n').slice(0, 3).join('\n');
            lines.push(`   expected: ${exp}${(r.expected || '').split('\n').length > 3 ? '...' : ''}`);
            lines.push(`   actual:   ${act}${(r.stdout || '').split('\n').length > 3 ? '...' : ''}`);
        }
    });

    outputPre.textContent = lines.join('\n');

    const target = data.results.find(r => r.passed === false) || data.results[0];
    if (target) {
        expectedPre.textContent = target.expected || '(예상 출력 없음)';
        actualPre.textContent = target.stdout || '(실제 출력 없음)';
        if (target.passed === false) {
            new bootstrap.Tab(document.getElementById('compare-tab')).show();
        } else {
            new bootstrap.Tab(document.getElementById('output-tab')).show();
        }
    }
}
class Squircle {
  static createPath(width, height, cornerRadius, offsetX = 0, offsetY = 0) {
    // 안전 클램프
    const w = Math.max(0, width);
    const h = Math.max(0, height);
    const r = Math.max(0, Math.min(cornerRadius, Math.min(w, h) / 2));

    // iOS Continuous Corner의 근사치가 아니라 원형 베지어 근사 매직넘버
    const c = r * 0.552284749831;

    const x0 = offsetX;
    const y0 = offsetY;

    return `
      M ${x0 + r}, ${y0}
      H ${x0 + w - r}
      C ${x0 + w - r + c}, ${y0}, ${x0 + w}, ${y0 + c}, ${x0 + w}, ${y0 + r}
      V ${y0 + h - r}
      C ${x0 + w}, ${y0 + h - r + c}, ${x0 + w - c}, ${y0 + h}, ${x0 + w - r}, ${y0 + h}
      H ${x0 + r}
      C ${x0 + r - c}, ${y0 + h}, ${x0}, ${y0 + h - c}, ${x0}, ${y0 + h - r}
      V ${y0 + r}
      C ${x0}, ${y0 + r - c}, ${x0 + c}, ${y0}, ${x0 + r}, ${y0}
      Z
    `;
  }

  // 안쪽(borderWidth만큼 안으로 들어간) 링 path 생성
  static createRingPath(width, height, radius, borderWidth) {
    const bw = Math.max(0, borderWidth);

    // 바깥 squircle
    const outer = this.createPath(width, height, radius);

    // 안쪽 squircle (크기 줄이고, bw 만큼 평행이동)
    const innerW = Math.max(0, width - 2 * bw);
    const innerH = Math.max(0, height - 2 * bw);
    const innerR = Math.max(0, radius - bw);
    const inner = this.createPath(innerW, innerH, innerR, bw, bw);

    // evenodd로 outer - inner = 링
    return `${outer} ${inner}`;
  }

  static createMaskSvg(width, height, radius) {
    return `
      <svg width="${width}" height="${height}" viewBox="0 0 ${width} ${height}" xmlns="http://www.w3.org/2000/svg">
        <path d="${this.createPath(width, height, radius)}" fill="black"/>
      </svg>
    `;
  }

  static createBorderSvg(width, height, radius, borderWidth, color) {
    return `
      <svg width="${width}" height="${height}" viewBox="0 0 ${width} ${height}" xmlns="http://www.w3.org/2000/svg" shape-rendering="geometricPrecision">
        <path d="${this.createRingPath(width, height, radius, borderWidth)}"
              fill="${color}" fill-rule="evenodd"/>
      </svg>
    `;
  }

  static apply(element, radius = 40, border) {
    const width = element.offsetWidth;
    const height = element.offsetHeight;

    // 1) 마스크 적용 (모양 만들기)
    const svgMask = this.createMaskSvg(width, height, radius);
    const maskUri = `data:image/svg+xml;utf8,${encodeURIComponent(svgMask)}`;

    element.style.webkitMaskImage = `url("${maskUri}")`;
    element.style.maskImage = `url("${maskUri}")`;
    element.style.webkitMaskSize = '100% 100%';
    element.style.maskSize = '100% 100%';

    // 2) 테두리(안쪽) 오버레이
    // border: { width: number, color: string }
    const hasBorder = border && border.width > 0;
    if (hasBorder) {
      element.style.position = element.style.position || 'fixed';

      let overlay = element.querySelector(':scope > .squircle-border');
      if (!overlay) {
        overlay = document.createElement('div');
        overlay.className = 'squircle-border';
        overlay.style.position = 'absolute';
        overlay.style.inset = '0';
        overlay.style.pointerEvents = 'none';
        overlay.style.zIndex = '1';
        element.appendChild(overlay);
      }

      const svgBorder = this.createBorderSvg(
        width,
        height,
        radius,
        border.width,
        border.color || 'rgba(0,0,0,0.2)'
      );
      const borderUri = `data:image/svg+xml;utf8,${encodeURIComponent(svgBorder)}`;

      overlay.style.backgroundImage = `url("${borderUri}")`;
      overlay.style.backgroundRepeat = 'no-repeat';
      overlay.style.backgroundSize = '100% 100%';
      overlay.style.backgroundPosition = '0 0';
    } else {
      const overlay = element.querySelector(':scope > .squircle-border');
      if (overlay) overlay.remove();
    }
  }
}
// DOM이 로드되면 실행
document.addEventListener("DOMContentLoaded", () => {
    console.log("index.js loaded!");

    // 파일 업로드 설정
    setupFileUpload();
    const prefersDark = window.matchMedia("(prefers-color-scheme: dark)").matches;
    document.querySelectorAll('.theme-toggle').forEach(el => {
        Squircle.apply(el, 16, {width: 2.5, color: prefersDark ? 'rgba(255,255,255,0.18)' : 'rgba(255,255,255,0.58)'});
    });

    // Run Single 버튼 이벤트
    const runSingleBtn = document.getElementById('runSingleBtn');
    if (runSingleBtn) {
        runSingleBtn.addEventListener('click', runSingleExecution);
    }

    // Analysis 버튼 이벤트
    const analysisBtn = document.getElementById('analysisBtn');
    if (analysisBtn) {
        analysisBtn.addEventListener('click', analyzeCode);
    }

    // Run Batch 버튼 이벤트 (TODO)
    const runBatchBtn = document.getElementById('runBatchBtn');
    if (runBatchBtn) {
        runBatchBtn.addEventListener('click', async () => {
            try {
                await waitForEditor();

                const folder = (document.getElementById('folder')?.value || '').trim();
                if (!folder) {
                    alert('배치 실행할 폴더 경로를 입력하세요.');
                    return;
                }

                const language = window.editor.getModel().getLanguageId();
                const code = window.editor.getValue();
                const filename = `temp_batch${langIdToExt[language] || '.txt'}`;

                runBatchBtn.disabled = true;
                const originalText = runBatchBtn.textContent;
                runBatchBtn.innerHTML = '<span class="spinner-border spinner-border-sm me-2"></span>실행 중...';

                const formData = new FormData();
                formData.append('code', code);
                formData.append('filename', filename);
                formData.append('language', language);
                formData.append('folder', folder);

                const res = await fetch('/run_batch', { method: 'POST', body: formData });
                const data = await res.json();

                if (!res.ok) {
                    throw new Error(data.error || '배치 실행 오류');
                }

                displayBatchResults(data);
            } catch (err) {
                console.error('Run batch error: ', err);
                alert(`Run Batch 중 오류: ${err.message}`);
            } finally {
                runBatchBtn.disabled = false;
                runBatchBtn.textContent = 'Run Batch';
            }
        });
    }

    // Reload Source Code 버튼 이벤트 (TODO)
    const reloadBtn = document.getElementById('reloadBtn');
    if (reloadBtn) {
        reloadBtn.addEventListener('click', async () => {
            const fileInput = document.getElementById("file");
            fileInput.value = ""; // BRUH
            fileInput.click();
        });
    }
});