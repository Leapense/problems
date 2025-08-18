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

// DOM이 로드되면 실행
document.addEventListener("DOMContentLoaded", () => {
    console.log("index.js loaded!");

    // 파일 업로드 설정
    setupFileUpload();

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
            try {
                const fileInput = document.getElementById('file');
                const file = fileInput?.files?.[0];
                if (!file) {
                    alert('먼저 파일을 선택하세요.');
                    return;
                }

                reloadBtn.disabled = true;
                const originalText = reloadBtn.textContent;
                reloadBtn.innerHTML = '<span class="spinner-border spinner-border-sm me-2"></span>불러오는 중...';

                const formData = new FormData();
                formData.append('file', file);
                const res = await fetch('/reload', { method: 'POST', body: formData });
                const data = await res.json();

                if (!res.ok) {
                    throw new Error(data.error || '파일 다시 불러오기 오류');
                }

                const ext = (data.language || '').toLowerCase();
                const monacoLang = extensionToLang[ext] || 'plaintext';

                await waitForEditor();
                window.editor.setValue(data.content || '');
                monaco.editor.setModelLanguage(window.editor.getModel, monacoLang);

                const outputPre = document.getElementById('outputContent');
                outputPre.textContent = `Reloaded: ${data.filename}\nLanguage: ${monacoLang}\n\n` +
                    (data.content ? data.content.slice(0, 500) : '(빈 파일)');
                new bootstrap.Tab(document.getElementById('output-tab')).show();
            } catch (err) {
                console.error('Reload error: ', err);
                alert(`Reload 중 오류: ${err.message}`);
            } finally {
                reloadBtn.disabled = false;
                reloadBtn.textContent = 'Reload Source Code';
            }
        });
    }
});