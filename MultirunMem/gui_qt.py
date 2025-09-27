#!/usr/bin/env python3
# gui_qt.py — PySide6/KDE 친화 포팅 (백준 문제 테스트 프로그램)
# - Qt6 + PySide6 기반, KDE(Breeze) 테마와 잘 어울림
# - 좌/우 Split(에디터 | 결과 탭), 가로/세로 토글/리셋
# - 단일/배치 실행, 출력/에러/비교, 간단한 복잡도 분석(옵션)
# - core.py(컴파일/실행/메트릭)는 그대로 재사용
#
# 필수: PySide6, psutil
# 선택: lizard, Jinja2, PySide6-QtWebEngine(또는 시스템 Qt WebEngine)
# Fedora(KDE) 예:
#   sudo dnf install python3-pyside6 python3-psutil python3-lizard python3-jinja2 qt6-qtwebengine
# 또는 pip:
#   pip install --user PySide6 psutil lizard Jinja2

from __future__ import annotations
import sys, os, pathlib, json, glob, re, itertools, tempfile, shutil, subprocess, difflib, time
from typing import List, Tuple

from PySide6 import QtCore, QtGui, QtWidgets

# WebEngine(선택)
try:
    from PySide6.QtWebEngineWidgets import QWebEngineView
except Exception:
    QWebEngineView = None

# Jinja2 (optional custom template rendering)
try:
    from jinja2 import Environment, FileSystemLoader, select_autoescape
except Exception:
    Environment = None

# core.py 재사용
from core import (
    compile_source, get_run_cmd, run_with_memory,
    MemoryLimitPlugin, CpuUsagePlugin
)

# ────────────────────────────────────────────────────────────
# 유틸(Compare 규칙: gui_gtk.py의 로직 포팅)
# ────────────────────────────────────────────────────────────
_token_pat = re.compile(r"\{([^{}]+?)\}")


def _line_to_regex(exp_line: str) -> re.Pattern:
    if exp_line.startswith('re:'):
        return re.compile(exp_line[3:])
    parts, pos = [], 0
    for m in _token_pat.finditer(exp_line):
        parts.append(re.escape(exp_line[pos:m.start()]))
        alts = [re.escape(s) for s in m.group(1).split('|')]
        parts.append('(?:' + '|'.join(alts) + ')')
        pos = m.end()
    parts.append(re.escape(exp_line[pos:]))
    return re.compile('^' + ''.join(parts) + '$')


def _normalize(line: str) -> str:
    return re.sub(r'\s+', ' ', line.rstrip())


# ────────────────────────────────────────────────────────────
# Lizard 복잡도 분석(선택)
# ────────────────────────────────────────────────────────────
CCN_RED = 15
NLOC_RED = 200


def collect_lizard_data(paths: List[str]):
    """CLI -j 우선, 실패 시 Python API 폴백"""
    exe = shutil.which('lizard')
    if exe:
        try:
            out = subprocess.check_output([exe, '-j'] + list(paths), text=True, stderr=subprocess.STDOUT)
            return json.loads(out)
        except Exception:
            pass
    try:
        import lizard as _lz
    except Exception as e:
        raise RuntimeError(f"lizard import failed: {e}")

    result = []
    for file_info in _lz.analyze(paths):
        fi = {
            "filename": getattr(file_info, "filename", ""),
            "nloc": getattr(file_info, "nloc", 0),
            "token_count": getattr(file_info, "token_count", 0),
            "functions": []
        }
        for fn in getattr(file_info, "function_list", []):
            ccn = getattr(fn, "cyclomatic_complexity", getattr(fn, "ccn", 0))
            nloc = getattr(fn, "nloc", getattr(fn, "length", 0))
            fi["functions"].append({
                "name": fn.name,
                "long_name": getattr(fn, "long_name", fn.name),
                "parameters": getattr(fn, "parameters", []),
                "cyclomatic_complexity": ccn,
                "ccn": ccn,
                "nloc": nloc,
                "length": nloc,
                "start_line": getattr(fn, "start_line", None)
            })
        result.append(fi)
    return result


def summarize_lizard(raw):
    files = []
    total = {"files": 0, "funcs": 0, "nloc": 0, "avg_ccn": 0.0, "max_ccn": 0, "warnings": 0}
    ccn_sum = 0
    for f in raw:
        fi = {
            "filename": f.get("filename", ""),
            "nloc": f.get("nloc", 0),
            "token_count": f.get("token_count", 0),
            "function_list": []
        }
        total["files"] += 1
        total["nloc"] += fi["nloc"]
        for fn in f.get("functions", []):
            ccn = fn.get("cyclomatic_complexity", fn.get("ccn", 0))
            nloc = fn.get("length", fn.get("nloc", 0))
            warn = (ccn >= CCN_RED) or (nloc and nloc >= NLOC_RED)
            fi["function_list"].append({
                "name": fn["name"],
                "long_name": fn.get("long_name", fn["name"]),
                "parameters": fn.get("parameters", []),
                "ccn": ccn,
                "nloc": nloc,
                "start_line": fn.get("start_line"),
                "warn": warn,
            })
            total["funcs"] += 1
            total["max_ccn"] = max(total["max_ccn"], ccn)
            total["warnings"] += int(warn)
            ccn_sum += ccn
        fi["function_list"].sort(key=lambda x: (x["ccn"], x["nloc"]), reverse=True)
        files.append(fi)
    total["avg_ccn"] = round(ccn_sum / total["funcs"], 2) if total["funcs"] else 0.0
    return files, total


def render_simple_report(files, total) -> str:
    rows = []
    for f in files:
        for fn in f["function_list"]:
            rows.append(
                f"<tr><td>{QtGui.QXmlStreamWriter().writeCharacters if False else ''}{f['filename']}</td>"
                f"<td>{fn['long_name']}</td><td>{fn['ccn']}</td><td>{fn['nloc']}</td>"
                f"<td>{'⚠️' if fn.get('warn') else ''}</td></tr>"
            )
    html = f"""
    <html><head><meta charset='utf-8'></head>
    <body>
      <h2>Complexity Report</h2>
      <p>Files: {total['files']} | Funcs: {total['funcs']} | Avg CCN: {total['avg_ccn']} | Max CCN: {total['max_ccn']} | Warnings: {total['warnings']}</p>
      <table>
        <tr><th>File</th><th>Function</th><th>CCN</th><th>NLOC</th><th>Warn</th></tr>
        {''.join(rows)}
      </table>
    </body></html>
    """
    return html


def render_with_template(template_path: str, files, total, thresholds) -> str:
    """Render analysis report using a Jinja2 HTML template.
    The template can reference {{ files }}, {{ total.* }}, {{ thresholds.* }},
    and also globals CCN_RED / NLOC_RED.
    """
    tpl_path = pathlib.Path(template_path)
    if not tpl_path.exists():
        raise FileNotFoundError(f"Template not found: {template_path}")
    if Environment is None:
        raise RuntimeError("Jinja2 is not installed. Install it with: pip install Jinja2")

    env = Environment(
        loader=FileSystemLoader(str(tpl_path.parent)),
        autoescape=select_autoescape(['html'])
    )
    tpl = env.get_template(tpl_path.name)
    html_str = tpl.render(
        files=files,
        total=total,
        thresholds=thresholds,
        CCN_RED=CCN_RED,
        NLOC_RED=NLOC_RED
    )

    # Ensure relative assets like report.css resolve correctly
    base_uri = tpl_path.parent.as_uri() + '/'
    if '<head' in html_str and '<base' not in html_str:
        html_str = html_str.replace('<head', f'<head><base href="{base_uri}">', 1)
    return html_str


# ────────────────────────────────────────────────────────────
# 워커(실행/배치)
# ────────────────────────────────────────────────────────────
class RunWorker(QtCore.QThread):
    doneSingle = QtCore.Signal(int, str, str, float)
    doneCompare = QtCore.Signal(bool, str)

    def __init__(self, src_path: str, stdin_text: str = '', expected_path: str = ''):
        super().__init__()
        self.src_path = src_path
        self.stdin_text = stdin_text
        self.expected_path = expected_path

    def compare_output(self, expected_path: str, actual: str) -> Tuple[bool, str]:
        try:
            with open(expected_path, 'r', encoding='utf-8') as f:
                expected = [ln.rstrip('\n\r') for ln in f.readlines()]
        except Exception as e:
            return False, f"Error reading expected file: {e}"

        actual_lines = [ln.rstrip('\n\r') for ln in actual.splitlines()]
        for idx, (e_line, a_line) in enumerate(itertools.zip_longest(expected, actual_lines), 1):
            if e_line is None:
                why = 'Actual longer than expected.'
                diff = '\n'.join(difflib.unified_diff(expected, actual_lines, fromfile='Expected', tofile='Actual', lineterm=''))
                return False, f'❌ FAIL (line {idx}): {why}\n\n{diff}'
            if a_line is None:
                why = 'Actual shorter than expected.'
                diff = '\n'.join(difflib.unified_diff(expected, actual_lines, fromfile='Expected', tofile='Actual', lineterm=''))
                return False, f'❌ FAIL (line {idx}): {why}\n\n{diff}'
            if not _line_to_regex(_normalize(e_line)).fullmatch(_normalize(a_line)):
                why = 'Content mismatch.'
                diff = '\n'.join(difflib.unified_diff(expected, actual_lines, fromfile='Expected', tofile='Actual', lineterm=''))
                return False, f'❌ FAIL (line {idx}): {why}\n\n{diff}'
        return True, '✅ PASS – output matches expected.'

    def run(self):
        try:
            lang, target, cwd = compile_source(self.src_path)
            cmd = get_run_cmd(lang, target)
            plugins = [MemoryLimitPlugin(0), CpuUsagePlugin()]
            code, out, err, elapsed, _ = run_with_memory(cmd, self.stdin_text, cwd=cwd, timeout=10, plugins=plugins)
        except Exception as e:
            self.doneSingle.emit(-1, '', str(e), 0.0)
            return
        self.doneSingle.emit(code, out, err, elapsed)
        if self.expected_path:
            ok, msg = self.compare_output(self.expected_path, out)
            self.doneCompare.emit(ok, msg)


# ────────────────────────────────────────────────────────────
# 메인 윈도우
# ────────────────────────────────────────────────────────────
class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('백준 문제 테스트 프로그램 — Qt6 (KDE)')
        self.resize(1400, 800)
        self._build_ui()
        # Template defaults
        try:
            _guess = pathlib.Path(__file__).parent / 'report_template.html'
            self.template_path = str(_guess) if _guess.exists() else ''
        except Exception:
            self.template_path = ''
        self.open_report_external = False

    # UI 구성
    def _build_ui(self):
        central = QtWidgets.QWidget()
        vbox = QtWidgets.QVBoxLayout(central)
        self.setCentralWidget(central)

        # 메뉴바
        mb = self.menuBar()
        fileM = mb.addMenu('&File')
        actOpen = fileM.addAction('Open Source…')
        actOpen.setShortcut('Ctrl+O')
        actOpen.triggered.connect(self.pick_src)
        actFolder = fileM.addAction('Open Batch Folder…')
        actFolder.setShortcut('Ctrl+B')
        actFolder.triggered.connect(self.pick_batch)
        fileM.addSeparator()
        actExit = fileM.addAction('Exit')
        actExit.setShortcut('Ctrl+Q')
        actExit.triggered.connect(self.close)

        toolsM = mb.addMenu('&Tools')
        actAnalyze = toolsM.addAction('Complexity Analysis')
        actAnalyze.setShortcut('Ctrl+L')
        actAnalyze.triggered.connect(self.run_analysis2)

        toolsM.addSeparator()
        self.actTpl = toolsM.addAction('Set Report Template…')
        self.actTpl.triggered.connect(self.pick_template)
        self.actOpenExtern = toolsM.addAction('Open Report in Browser')
        self.actOpenExtern.setCheckable(True)
        self.actOpenExtern.setChecked(False)
        self.actOpenExtern.toggled.connect(self.on_toggle_external)

        helpM = mb.addMenu('&Help')
        actAbout = helpM.addAction('About')
        actAbout.triggered.connect(lambda: QtWidgets.QMessageBox.information(self, 'About', '백준 문제 테스트 프로그램\nQt6 포팅 — © 2025'))

        # 컨트롤 스트립
        strip = QtWidgets.QHBoxLayout()
        vbox.addLayout(strip)

        grid = QtWidgets.QGridLayout()
        strip.addLayout(grid, 1)

        grid.addWidget(QtWidgets.QLabel('Source:'), 0, 0)
        self.src_edit = QtWidgets.QLineEdit()
        self.src_edit.setPlaceholderText('Select source file…')
        grid.addWidget(self.src_edit, 0, 1)
        btn_src = QtWidgets.QPushButton('…')
        btn_src.clicked.connect(self.pick_src)
        grid.addWidget(btn_src, 0, 2)

        grid.addWidget(QtWidgets.QLabel('Batch:'), 1, 0)
        self.batch_edit = QtWidgets.QLineEdit()
        self.batch_edit.setPlaceholderText('Select batch folder…')
        grid.addWidget(self.batch_edit, 1, 1)
        btn_batch = QtWidgets.QPushButton('…')
        btn_batch.clicked.connect(self.pick_batch)
        grid.addWidget(btn_batch, 1, 2)

        btns = QtWidgets.QHBoxLayout()
        strip.addLayout(btns)
        self.btn_run = QtWidgets.QPushButton('▶ Run Single')
        self.btn_run.clicked.connect(self.on_run_single)
        btns.addWidget(self.btn_run)
        self.btn_batch = QtWidgets.QPushButton('▶ Run Batch')
        self.btn_batch.clicked.connect(self.on_run_batch)
        btns.addWidget(self.btn_batch)
        self.btn_reload = QtWidgets.QPushButton('⟳ Reload')
        self.btn_reload.clicked.connect(self.reload_source)
        btns.addWidget(self.btn_reload)

        self.btn_split = QtWidgets.QPushButton('⇆ Split H')
        self.btn_split.clicked.connect(self.toggle_split)
        btns.addWidget(self.btn_split)
        self.btn_reset = QtWidgets.QPushButton('↔ Reset Split')
        self.btn_reset.clicked.connect(self.reset_split)
        btns.addWidget(self.btn_reset)

        self.spinner = QtWidgets.QProgressBar()
        self.spinner.setRange(0, 0)
        self.spinner.setFixedWidth(120)
        self.spinner.setVisible(False)
        btns.addWidget(self.spinner)

        # Split
        self.splitter = QtWidgets.QSplitter(QtCore.Qt.Orientation.Horizontal)
        vbox.addWidget(self.splitter, 1)

        # Left: editor
        left = QtWidgets.QWidget(); left_v = QtWidgets.QVBoxLayout(left)
        self.editor = QtWidgets.QPlainTextEdit()
        self.editor.setLineWrapMode(QtWidgets.QPlainTextEdit.NoWrap)
        font = self.editor.font(); font.setFamily('Source Code Pro'); font.setPointSize(11)
        self.editor.setFont(font)
        left_v.addWidget(self.editor, 1)
        self.splitter.addWidget(left)

        # Right: tabs
        right = QtWidgets.QTabWidget()
        self.txt_out = QtWidgets.QPlainTextEdit(); self.txt_out.setReadOnly(True)
        self.txt_err = QtWidgets.QPlainTextEdit(); self.txt_err.setReadOnly(True)
        self.txt_cmp = QtWidgets.QPlainTextEdit(); self.txt_cmp.setReadOnly(True)
        right.addTab(self.txt_out, 'Output')
        right.addTab(self.txt_err, 'Error')
        right.addTab(self.txt_cmp, 'Compare')
        # Analysis 탭(HTML)
        if QWebEngineView:
            self.web = QWebEngineView()
            right.addTab(self.web, 'Analysis')
        else:
            self.txt_analysis = QtWidgets.QPlainTextEdit(); self.txt_analysis.setReadOnly(True)
            right.addTab(self.txt_analysis, 'Analysis')
        self.splitter.addWidget(right)
        self.reset_split()

        # 상태바
        self.status = self.statusBar()
        self.status.showMessage('Ready')

        # 드래그&드롭
        self.setAcceptDrops(True)

    # DnD
    def dragEnterEvent(self, e: QtGui.QDragEnterEvent):
        if e.mimeData().hasUrls():
            e.acceptProposedAction()

    def dropEvent(self, e: QtGui.QDropEvent):
        urls = e.mimeData().urls()
        if not urls:
            return
        path = urls[0].toLocalFile()
        if os.path.isdir(path):
            self.batch_edit.setText(path)
        else:
            self.src_edit.setText(path)
            self.load_source_preview(path)

    # Pickers
    def pick_src(self):
        fn, _ = QtWidgets.QFileDialog.getOpenFileName(self, 'Select source', '', 'Source (*.c *.cpp *.cc *.cxx *.java *.py)')
        if fn:
            self.src_edit.setText(fn)
            self.load_source_preview(fn)

    def pick_batch(self):
        fn = QtWidgets.QFileDialog.getExistingDirectory(self, 'Select batch folder')
        if fn:
            self.batch_edit.setText(fn)

    # Actions
    def reload_source(self):
        path = self.src_edit.text().strip()
        if path:
            self.load_source_preview(path)

    def load_source_preview(self, path: str):
        try:
            code = pathlib.Path(path).read_text(encoding='utf-8', errors='replace')
            self.editor.setPlainText(code)
        except Exception as e:
            QtWidgets.QMessageBox.critical(self, 'Error', f'Cannot load source:\n{e}')

    def toggle_split(self):
        ori = self.splitter.orientation()
        if ori == QtCore.Qt.Orientation.Horizontal:
            self.splitter.setOrientation(QtCore.Qt.Orientation.Vertical)
            self.btn_split.setText('⇅ Split V')
        else:
            self.splitter.setOrientation(QtCore.Qt.Orientation.Horizontal)
            self.btn_split.setText('⇆ Split H')
        QtCore.QTimer.singleShot(0, self.reset_split)

    def reset_split(self):
        # 균등 분할
        if self.splitter.count() == 2:
            total = self.splitter.size().width() if self.splitter.orientation() == QtCore.Qt.Orientation.Horizontal else self.splitter.size().height()
            half = max(200, total // 2) if total else 600
            self.splitter.setSizes([half, half])

    def set_running(self, running: bool):
        self.spinner.setVisible(running)
        self.btn_run.setEnabled(not running)
        self.btn_batch.setEnabled(not running)
        self.btn_reload.setEnabled(not running)

    # Run single
    def on_run_single(self):
        src = self.src_edit.text().strip()
        if not src:
            QtWidgets.QMessageBox.warning(self, 'Warning', 'Select a source file first.')
            return
        stdin, ok = QtWidgets.QInputDialog.getMultiLineText(self, 'Manual stdin', 'Leave empty to skip', '')
        if not ok:
            return
        self.run_single(src, stdin, expected_path='')

    def run_single(self, src: str, stdin: str, expected_path: str):
        self.set_running(True)
        self.status.showMessage('Running…')
        self.worker = RunWorker(src, stdin, expected_path)
        self.worker.doneSingle.connect(self.on_single_done)
        self.worker.doneCompare.connect(self.on_compare_done)
        self.worker.finished.connect(lambda: self.set_running(False))
        self.worker.start()

    def on_single_done(self, code: int, out: str, err: str, elapsed: float):
        self.txt_out.setPlainText(out)
        self.txt_err.setPlainText(err)
        self.status.showMessage(f'Exit {code} | {elapsed*1000:.1f} ms')

    def on_compare_done(self, ok: bool, msg: str):
        self.txt_cmp.setPlainText(msg)
        if not ok:
            self.findChild(QtWidgets.QTabWidget).setCurrentIndex(2)

    # Run batch
    def on_run_batch(self):
        folder = self.batch_edit.text().strip()
        src = self.src_edit.text().strip()
        if not (folder and os.path.isdir(folder) and src):
            QtWidgets.QMessageBox.warning(self, 'Warning', 'Select source *and* batch folder.')
            return
        cases = self._find_test_cases(folder)
        if not cases:
            QtWidgets.QMessageBox.information(self, 'Info', 'No input/output pairs found.')
            return
        passed = 0
        first_fail = None
        for idx, (in_path, out_path) in enumerate(cases, 1):
            stdin = pathlib.Path(in_path).read_text(encoding='utf-8', errors='replace')
            # 동기 실행(간단): UI freeze 방지 위해 QCoreApplication.processEvents()
            QtWidgets.QApplication.setOverrideCursor(QtCore.Qt.CursorShape.BusyCursor)
            self.status.showMessage(f'Batch {idx}/{len(cases)}…')
            QtWidgets.QApplication.processEvents()
            try:
                lang, target, cwd = compile_source(src)
                cmd = get_run_cmd(lang, target)
                plugins = [MemoryLimitPlugin(0), CpuUsagePlugin()]
                code, out, err, elapsed, _ = run_with_memory(cmd, stdin, cwd=cwd, timeout=10, plugins=plugins)
            except Exception as e:
                self.txt_err.setPlainText(str(e))
                QtWidgets.QApplication.restoreOverrideCursor()
                return
            self.txt_out.setPlainText(out)
            self.txt_err.setPlainText(err)
            ok, compare_text = RunWorker(src).compare_output(out_path, out)
            if ok:
                passed += 1
            elif first_fail is None:
                first_fail = f"First failure on: {os.path.basename(in_path)}\n\n{compare_text}"
            self.status.showMessage(f'Batch {idx}/{len(cases)} - Passed {passed}')
            QtWidgets.QApplication.processEvents()
        QtWidgets.QApplication.restoreOverrideCursor()
        if first_fail:
            self.txt_cmp.setPlainText(first_fail)
            self.findChild(QtWidgets.QTabWidget).setCurrentIndex(2)
        else:
            self.txt_cmp.setPlainText(f"✅ All {len(cases)} test cases passed!")
        self.status.showMessage('Ready')

    def pick_template(self):
        fn, _ = QtWidgets.QFileDialog.getOpenFileName(self, 'Select report_template.html', '', 'HTML (*.html)')
        if fn:
            self.template_path = fn
            self.status.showMessage(f'Selected template: {os.path.basename(fn)}', 5000)

    def on_toggle_external(self, v: bool):
        self.open_report_external = v
        self.status.showMessage('Open in external browser: ' + ('ON' if v else 'OFF'), 3000)

    def run_analysis2(self):
        src = self.src_edit.text().strip()
        if not src or not os.path.isfile(src):
            QtWidgets.QMessageBox.warning(self, 'Source?', 'Choose a source file first.')
            return
        try:
            raw = collect_lizard_data([src])
            files, total = summarize_lizard(raw)
            thresholds = {'CCN_RED': CCN_RED, 'NLOC_RED': NLOC_RED, 'ccn': CCN_RED, 'nloc': NLOC_RED}
            html = None
            base_dir = None
            tpl = self.template_path
            if tpl and os.path.exists(tpl):
                try:
                    html = render_with_template(tpl, files, total, thresholds)
                    base_dir = pathlib.Path(tpl).parent
                except Exception as te:
                    QtWidgets.QMessageBox.warning(self, 'Template error', str(te))
            if html is None:
                html = render_simple_report(files, total)
                base_dir = pathlib.Path.cwd()
        except Exception as e:
            QtWidgets.QMessageBox.critical(self, 'Analysis failed', str(e))
            return

        # External browser option
        if self.open_report_external:
            try:
                tmp_html = tempfile.NamedTemporaryFile(delete=False, suffix='.html'); tmp_html.close()
                pathlib.Path(tmp_html.name).write_text(html, encoding='utf-8')
                url = QtCore.QUrl.fromLocalFile(tmp_html.name)
                QtGui.QDesktopServices.openUrl(url)
                info = QtWidgets.QLabel('Report opened in your default browser.')
                info.setAlignment(QtCore.Qt.AlignLeft)
                self.findChild(QtWidgets.QTabWidget).setCurrentIndex(3)
                self.status.showMessage('Opened report in browser')
                return
            except Exception as e:
                QtWidgets.QMessageBox.warning(self, 'Browser launch failed', str(e))

        # In-app view
        if QWebEngineView:
            base_url = QtCore.QUrl.fromLocalFile(str(base_dir) + '/') if base_dir else QtCore.QUrl()
            self.web.setHtml(html, base_url)
            self.findChild(QtWidgets.QTabWidget).setCurrentIndex(3)
        else:
            self.txt_analysis.setPlainText(html)
            self.findChild(QtWidgets.QTabWidget).setCurrentIndex(3)

    def _find_test_cases(self, folder: str):
        cases = []
        for in_file in sorted(glob.glob(os.path.join(folder, 'input*.in'))):
            base = os.path.basename(in_file)
            out_file = os.path.join(folder, base.replace('input', 'output', 1).replace('.in', '.out'))
            if os.path.exists(out_file):
                cases.append((in_file, out_file))
        return cases

    # Analysis
    def run_analysis(self):
        src = self.src_edit.text().strip()
        if not src or not os.path.isfile(src):
            QtWidgets.QMessageBox.warning(self, 'Source?', 'Choose a source file first.')
            return
        try:
            raw = collect_lizard_data([src])
            files, total = summarize_lizard(raw)
            html = render_simple_report(files, total)
        except Exception as e:
            QtWidgets.QMessageBox.critical(self, 'Analysis failed', str(e))
            return
        if QWebEngineView:
            self.web.setHtml(html)
            self.findChild(QtWidgets.QTabWidget).setCurrentIndex(3)
        else:
            self.txt_analysis.setPlainText(html)
            self.findChild(QtWidgets.QTabWidget).setCurrentIndex(3)


def main():
    app = QtWidgets.QApplication(sys.argv)
    # KDE 쪽 기본 테마 사용
    app.setStyle('breeze') if 'breeze' in QtWidgets.QStyleFactory.keys() else None
    w = MainWindow(); w.show()
    sys.exit(app.exec())


if __name__ == '__main__':
    main()
