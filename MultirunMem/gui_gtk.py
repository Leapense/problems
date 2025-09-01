#!/usr/bin/env python3
# gui_gtk.py – Gtk 포팅판 (mac-like 헤더 + 단일/배치 테스트 + 결과 비교)
# 2025-09: UI 재디자인
# - 좌/우 Split(에디터 | 결과 탭) 기본, 가로/세로 토글 가능
# - 상단 컨트롤 스트립(소스/배치 경로 + 실행/리로드 + Split 토글/리셋)
# - 드래그&드롭으로 소스/폴더 채우기
# - 실행 중 스피너 + 상태바 유지
# - 기존 기능(메뉴/설정/복잡도 분석/비교) 그대로 동작

import importlib
import json
import shutil
import tempfile
import gi
gi.require_version('Gtk', '3.0')
gi.require_version('GtkSource', '4')
gi.require_version('WebKit2', '4.1')
from gi.repository import Gtk, Gdk, GdkPixbuf, GLib, GtkSource, Pango, WebKit2

try:
    from jinja2 import Environment, FileSystemLoader, select_autoescape
except ImportError:
    Environment = None  # 나중에 설치 유도

import os, sys, pathlib, subprocess, threading, glob, time, re, difflib, itertools, math, html
from functools import partial

# ─── core 모듈 (컴파일·실행·메트릭) ────────────────────────────────
from core import (
    compile_source, get_run_cmd, run_with_memory,
    MemoryLimitPlugin, CpuUsagePlugin
)

# ─── 비교 로직 헬퍼 ────────────────────────────────────────────────
_token_pat = re.compile(r'\{([^{}]+?)\}')

# ── 임계치 설정 ──────────────────────────────────────────────────
CCN_RED   = 15    # CCN 경고선
NLOC_RED  = 200   # 함수 길이 경고선
JSON_FILE = "lizard.json"
OUTPUT    = "report_custom.html"

def run_lizard_json(paths):
    cmd = ["lizard", "-j"] + list(paths)
    data = subprocess.check_output(cmd, text=True)
    return json.loads(data)

# ── JSON → 템플릿 데이터 변환 ───────────────────────────────────
def load_data(json_path):
    data = json.loads(pathlib.Path(json_path).read_text(encoding="utf-8"))

    files, total, ccn_sum = [], {
        "files":0, "funcs":0, "nloc":0,
        "avg_ccn":0.0, "max_ccn":0, "warnings":0
    }, 0

    for f in data:
        fi = {
            "filename": f["filename"],
            "nloc": f.get("nloc",0),
            "token_count": f.get("token_count",0),
            "function_list":[]
        }
        total["files"] += 1
        total["nloc"]  += fi["nloc"]

        for fn in f.get("functions",[]):
            ccn   = fn.get("cyclomatic_complexity", fn.get("ccn",0))
            nloc  = fn.get("length", fn.get("nloc",0))
            warn  = (ccn>=CCN_RED) or (nloc and nloc>=NLOC_RED)

            fi["function_list"].append({
                "name":fn["name"],
                "long_name":fn.get("long_name",fn["name"]),
                "parameters":fn.get("parameters",[]),
                "ccn":ccn,
                "nloc":nloc,
                "start_line":fn.get("start_line"),
                "warn":warn
            })

            total["funcs"] += 1
            total["max_ccn"]=max(total["max_ccn"], ccn)
            total["warnings"]+=warn
            ccn_sum += ccn

        fi["function_list"].sort(key=lambda x:(x["ccn"],x["nloc"]),reverse=True)
        files.append(fi)

    total["avg_ccn"]=round(ccn_sum/total["funcs"],2) if total["funcs"] else 0.0
    return files,total,dict(CCN_RED=CCN_RED,NLOC_RED=NLOC_RED)

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

# ─── 테스트 케이스 검색 ───────────────────────────────────────────
def _find_test_cases(folder: str):
    cases = []
    for in_file in sorted(glob.glob(os.path.join(folder, 'input*.in'))):
        base = pathlib.Path(in_file).name
        out_file = pathlib.Path(folder) / base.replace('input', 'output', 1).replace('.in', '.out')
        if out_file.exists():
            cases.append((in_file, str(out_file)))
    return cases

# ─── 메인 윈도우 ─────────────────────────────────────────────────
class MainWindow(Gtk.Window):
    def __init__(self):
        super().__init__(title='백준 문제 테스트 프로그램')
        self.app_cfg = {
            'base_font'   : 'SF Pro Display',
            'mono_font'   : 'SF Mono',
            'font_size'   : 10,
            'style_scheme': 'vsdark',   # GtkSourceView
            'timeout'     : 10,
            'mem_limit_mb': 0
        }
        self.mem_limit_bytes = self.app_cfg['mem_limit_mb'] * 1024**2
        self.timeout_sec     = self.app_cfg['timeout']
        settings = Gtk.Settings.get_default()
        settings.set_property('gtk-application-prefer-dark-theme', True)
        self.set_default_size(1400, 740)
        self.set_resizable(True)
        self.set_decorated(False)                # 네이티브 프레임 숨김
        self.connect('destroy', Gtk.main_quit)

        self.set_app_paintable(True)
        screen = self.get_screen()
        visual = screen.get_rgba_visual()
        if visual and self.is_composited():
            self.set_visual(visual)

        self.connect('screen-changed', self._on_screen_changed)

        self._build_ui_with_overlay()
        self._apply_css()

    def _on_screen_changed(self, *_):
        screen = self.get_screen()
        visual = screen.get_rgba_visual()
        if visual and self.is_composited():
            self.set_visual(visual)

    def apply_settings(self, new_cfg: dict):
        # 설정 갱신
        self.app_cfg.update(new_cfg)
        self.timeout_sec     = self.app_cfg['timeout']
        self.mem_limit_bytes = self.app_cfg['mem_limit_mb'] * 1024**2

        # 폰트
        base_desc = f"{self.app_cfg['base_font']} {self.app_cfg['font_size']}"
        mono_desc = f"{self.app_cfg['mono_font']} {self.app_cfg['font_size']}"
        try:
            self.override_font(Pango.FontDescription(base_desc))
        except Exception:
            pass
        try:
            self.source_view.override_font(Pango.FontDescription(mono_desc))
        except Exception:
            pass

        # GtkSource style
        scheme_mgr = GtkSource.StyleSchemeManager()
        scheme = scheme_mgr.get_scheme(self.app_cfg['style_scheme'])
        if scheme:
            self.source_buf.set_style_scheme(scheme)
            self.out_buf.set_style_scheme(scheme)
            self.err_buf.set_style_scheme(scheme)
            self.compare_buf.set_style_scheme(scheme)
        self._toast('Prefs', 'Settings applied.', 'info')

    # ─────────────────────────────────────────────────────────────
    # UI: Overlay + Header(가짜 타이틀바) + 컨텐츠(vbox)
    # 컨텐츠: 메뉴바 → 컨트롤 스트립 → Paned(좌: Source / 우: Notebook[Output, Error, Compare, Analysis]) → 상태바
    # 상단 컨트롤: 경로(Entry + …), Run/Batch/Reload, Split토글, 레이아웃 리셋, 스피너
    # ─────────────────────────────────────────────────────────────
    def _build_ui_with_overlay(self):
        surface = Gtk.EventBox()
        surface.get_style_context().add_class('chrome')
        surface.set_margin_top(6)
        surface.set_margin_bottom(6)
        surface.set_margin_start(6)
        surface.set_margin_end(6)
        self.add(surface)

        overlay = Gtk.Overlay()
        surface.add(overlay)

        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=8)
        self.content_box = vbox
        vbox.set_margin_top(44)
        vbox.set_margin_bottom(12)
        vbox.set_margin_start(12)
        vbox.set_margin_end(12)
        overlay.add(vbox)

        # 메뉴바
        self._build_menubar(vbox)

        # ── 컨트롤 스트립(툴바 느낌) ───────────────────────────
        ctrl = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
        ctrl.get_style_context().add_class('control-strip')
        vbox.pack_start(ctrl, False, False, 0)

        # 좌측: 소스/배치 경로
        grid = Gtk.Grid(column_spacing=6, row_spacing=6)
        ctrl.pack_start(grid, True, True, 0)

        self.src_entry = Gtk.Entry()
        self.src_entry.set_placeholder_text('Select source file… (drop here)')
        self.batch_entry = Gtk.Entry()
        self.batch_entry.set_placeholder_text('Select batch folder… (drop here)')

        grid.attach(Gtk.Label(label='Source:'), 0, 0, 1, 1)
        grid.attach(self.src_entry,              1, 0, 1, 1)
        btn_src = Gtk.Button(label='…')
        btn_src.connect('clicked', self.on_pick_src)
        grid.attach(btn_src,                     2, 0, 1, 1)

        grid.attach(Gtk.Label(label='Batch:'),   0, 1, 1, 1)
        grid.attach(self.batch_entry,            1, 1, 1, 1)
        btn_batch = Gtk.Button(label='…')
        btn_batch.connect('clicked', self.on_pick_batch)
        grid.attach(btn_batch,                   2, 1, 1, 1)

        # 우측: 실행/레이아웃 버튼들
        btn_box = Gtk.Box(spacing=6)
        ctrl.pack_end(btn_box, False, False, 0)

        self.run_btn = Gtk.Button(label='▶ Run Single')
        self.run_btn.connect('clicked', self.on_run_single)
        self.batch_btn = Gtk.Button(label='▶ Run Batch')
        self.batch_btn.connect('clicked', self.on_run_batch)
        self.reload_btn = Gtk.Button(label='⟳ Reload')
        self.reload_btn.connect('clicked', self.on_reload_code)

        # Split/Toggles
        self.split_toggle = Gtk.ToggleButton(label='⇆ Split H')
        self.split_toggle.set_tooltip_text('Toggle split orientation (H/V)')
        self.split_toggle.connect('toggled', self._toggle_split)

        self.reset_layout_btn = Gtk.Button(label='↔ Reset Split')
        self.reset_layout_btn.set_tooltip_text('Reset split position to 50/50')
        self.reset_layout_btn.connect('clicked', self._reset_layout)

        # 실행중 스피너
        self.spinner = Gtk.Spinner()
        self.spinner.set_size_request(18, 18)

        for b in (self.run_btn, self.batch_btn, self.reload_btn, self.split_toggle, self.reset_layout_btn):
            btn_box.pack_start(b, False, False, 0)
        btn_box.pack_start(self.spinner, False, False, 0)

        # ── 메인 영역: 좌/우 Paned ────────────────────────────
        self.main_paned = Gtk.Paned(orientation=Gtk.Orientation.HORIZONTAL)
        vbox.pack_start(self.main_paned, True, True, 0)

        # 좌: Source editor (GtkSourceView)
        self.out_buf = GtkSource.Buffer()
        self.err_buf = GtkSource.Buffer()
        self.compare_buf = GtkSource.Buffer()

        self.source_buf = GtkSource.Buffer()
        self.source_view = GtkSource.View(buffer=self.source_buf, monospace=True)
        self.source_view.set_show_line_numbers(True)
        self.source_view.set_highlight_current_line(True)
        self.source_view.set_wrap_mode(Gtk.WrapMode.NONE)
        self.source_scrolled_win = Gtk.ScrolledWindow()
        self.source_scrolled_win.set_hexpand(True)
        self.source_scrolled_win.set_vexpand(True)
        self.source_scrolled_win.add(self.source_view)
        self.main_paned.add1(self.source_scrolled_win)

        # 우: 결과 노트북(Output/Error/Compare/Analysis)
        self.nb = Gtk.Notebook()  # 기존 코드와 호환을 위해 self.nb 유지
        self.nb.set_scrollable(True)
        self.main_paned.add2(self.nb)

        out_view = GtkSource.View(buffer=self.out_buf, monospace=True)
        self.out_scrolled_win = Gtk.ScrolledWindow(); self.out_scrolled_win.add(out_view)

        err_view = GtkSource.View(buffer=self.err_buf, monospace=True)
        self.err_scrolled_win = Gtk.ScrolledWindow(); self.err_scrolled_win.add(err_view)

        cmp_view = GtkSource.View(buffer=self.compare_buf, monospace=True)
        self.cmp_scrolled_win = Gtk.ScrolledWindow(); self.cmp_scrolled_win.add(cmp_view)

        # 스타일 스킴(다크 우선)
        scheme_manager = GtkSource.StyleSchemeManager.get_default()
        scheme = scheme_manager.get_scheme('vsdark')
        if not scheme:
            dark_schemes = [s for s in scheme_manager.get_scheme_ids() if any(k in s for k in ('dark', 'oblivion', 'solarized-dark', 'darcula'))]
            scheme = scheme_manager.get_scheme(dark_schemes[0]) if dark_schemes else scheme_manager.get_scheme('classic')
        if scheme:
            self.source_buf.set_style_scheme(scheme)
            self.out_buf.set_style_scheme(scheme)
            self.err_buf.set_style_scheme(scheme)
            self.compare_buf.set_style_scheme(scheme)

        self.analysis_box = Gtk.Box()
        self.nb.append_page(self.out_scrolled_win, Gtk.Label(label='Output'))
        self.nb.append_page(self.err_scrolled_win, Gtk.Label(label='Error'))
        self.nb.append_page(self.cmp_scrolled_win, Gtk.Label(label='Compare'))
        self.nb.append_page(self.analysis_box, Gtk.Label(label='Analysis'))

        # 상태바
        status_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
        vbox.pack_end(status_box, False, False, 0)
        self.status_lbl = Gtk.Label(label='Ready')
        self.status_lbl.get_style_context().add_class('secondary')
        status_box.pack_start(self.status_lbl, False, False, 0)

        # ── 헤더(가짜 타이틀바) 맥 라이크 ───────────────────────
        header = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=8)
        header.set_size_request(-1, 32)
        header.get_style_context().add_class('titlebar')
        header.set_halign(Gtk.Align.FILL)
        header.set_valign(Gtk.Align.START)
        header.set_hexpand(True)

        lights = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
        header.pack_start(lights, False, False, 12)
        self._make_light(lights, 'red', self.close)
        self._make_light(lights, 'yellow', self.iconify)
        self._make_light(lights, 'green', self._toggle_max)

        titlename = Gtk.Label(label="백준 문제 테스트 프로그램")
        header.pack_start(titlename, False, False, 12)

        # EventBox로 헤더 드래그 이동/더블클릭 최대화
        header_event_box = Gtk.EventBox()
        header_event_box.set_halign(Gtk.Align.FILL)
        header_event_box.set_valign(Gtk.Align.START)
        header_event_box.set_hexpand(True)
        header_event_box.add_events(Gdk.EventMask.BUTTON_PRESS_MASK)
        header_event_box.connect('button-press-event', self._on_header_button)
        header_event_box.add(header)
        overlay.add_overlay(header_event_box)

        def _sync_margin(_w, alloc):
            try:
                top = max(alloc.height, 32) + 12
                self.content_box.set_margin_top(top)
            except Exception:
                pass
        header_event_box.connect('size-allocate', _sync_margin)

        # 초기 Split 50/50
        GLib.idle_add(self._reset_layout)

        # 드래그&드롭(파일/폴더)
        self._enable_dnd()

    # ── Split 토글/리셋/스피너 상태 ─────────────────────────────
    def _toggle_split(self, btn: Gtk.ToggleButton):
        # H <-> V 전환
        cur = self.main_paned.get_orientation()
        if cur == Gtk.Orientation.HORIZONTAL:
            self.main_paned.set_orientation(Gtk.Orientation.VERTICAL)
            btn.set_label('⇅ Split V')
        else:
            self.main_paned.set_orientation(Gtk.Orientation.HORIZONTAL)
            btn.set_label('⇆ Split H')
        GLib.idle_add(self._reset_layout)  # 전환 후 균등 분할

    def _reset_layout(self, *_args):
        alloc = self.main_paned.get_allocation()
        if self.main_paned.get_orientation() == Gtk.Orientation.HORIZONTAL:
            pos = max(200, alloc.width // 2)
        else:
            pos = max(200, alloc.height // 2)
        self.main_paned.set_position(pos)
        return False

    def _set_running(self, running: bool):
        # 실행 중/대기 상태 전환 (버튼/스피너/상태문구)
        if running:
            self.spinner.start()
            self.run_btn.set_sensitive(False)
            self.batch_btn.set_sensitive(False)
            self.reload_btn.set_sensitive(False)
        else:
            self.spinner.stop()
            self.run_btn.set_sensitive(True)
            self.batch_btn.set_sensitive(True)
            self.reload_btn.set_sensitive(True)

    # ── 헤더 조작 ────────────────────────────────────────────────
    def _on_header_button(self, _w, event):
        if event.type == Gdk.EventType._2BUTTON_PRESS and event.button == Gdk.BUTTON_PRIMARY:
            self._toggle_max()
            return True
        if event.type == Gdk.EventType.BUTTON_PRESS and event.button == Gdk.BUTTON_PRIMARY:
            self.begin_move_drag(event.button, int(event.x_root), int(event.y_root), event.time)
            return True
        return False

    def _make_light(self, parent, color: str, cb):
        ev = Gtk.EventBox()
        ev.set_size_request(14, 14)
        ev.set_margin_top(9)
        ev.set_margin_bottom(9)
        ev.connect('button-press-event', lambda *_: cb())
        ev.connect('enter-notify-event', lambda w, e: w.get_style_context().add_class('hover'))
        ev.connect('leave-notify-event', lambda w, e: w.get_style_context().remove_class('hover'))
        style_context = ev.get_style_context()
        style_context.add_class('traffic-light')
        style_context.add_class(color)
        parent.pack_start(ev, False, False, 0)

    def _toggle_max(self, *_):
        if self.is_maximized():
            self.unmaximize()
        else:
            self.maximize()

    def _ensure_jinja2(self) -> bool:
        if Environment is not None:
            return True
        ask = Gtk.MessageDialog(
            self, 0, Gtk.MessageType.QUESTION, Gtk.ButtonsType.YES_NO,
            '“jinja2” package not found.\nInstall it now?'
        )
        resp = ask.run(); ask.destroy()
        if resp != Gtk.ResponseType.YES:
            return False
        try:
            subprocess.check_call([sys.executable, '-m', 'pip', 'install', '--user', 'jinja2'])
            return True
        except subprocess.CalledProcessError as e:
            self._toast('pip error', str(e), 'danger')
            return False

    def _collect_lizard_data(self, paths):
        """
        1) lizard CLI의 -j 시도 → 실패하면
        2) Python API(lizard.analyze)로 동일 구조를 만들어 반환
        반환값: list[dict]  (load_data()가 기대하는 JSON과 동일한 형태)
        """
        # 1) CLI 경로 시도
        lizard_exe = shutil.which('lizard')
        if lizard_exe:
            try:
                out = subprocess.check_output([lizard_exe, '-j'] + list(paths), text=True, stderr=subprocess.STDOUT)
                return json.loads(out)
            except subprocess.CalledProcessError as e:
                # -j 미지원이면 여기서 튕김 → API 폴백
                pass
            except json.JSONDecodeError:
                pass

        # 2) Python API 폴백
        try:
            import lizard as _lz
        except Exception as e:
            raise RuntimeError(f"lizard import failed: {e}")

        result = []
        # _lz.analyze 는 경로 리스트를 받음 (버전별 시그니처 차이 최소화)
        for file_info in _lz.analyze(paths):
            fi = {
                "filename": getattr(file_info, "filename", ""),
                "nloc": getattr(file_info, "nloc", 0),
                "token_count": getattr(file_info, "token_count", 0),
                "functions": []
            }
            for fn in getattr(file_info, "function_list", []):
                fi["functions"].append({
                    "name": fn.name,
                    "long_name": getattr(fn, "long_name", fn.name),
                    "parameters": getattr(fn, "parameters", []),
                    # load_data()가 cyclomatic_complexity 또는 ccn 둘 중 하나를 참조하므로 둘 다 맞춰둠
                    "cyclomatic_complexity": getattr(fn, "cyclomatic_complexity", getattr(fn, "ccn", 0)),
                    "ccn": getattr(fn, "cyclomatic_complexity", getattr(fn, "ccn", 0)),
                    "nloc": getattr(fn, "nloc", getattr(fn, "length", 0)),
                    "length": getattr(fn, "nloc", getattr(fn, "length", 0)),
                    "start_line": getattr(fn, "start_line", None),
                })
            result.append(fi)
        return result

    def _render_with_template(self, template_path: str, files, total, thresholds) -> str:
        """
        report_template.html을 Jinja2로 렌더해서 HTML 문자열을 반환.
        (템플릿은 {{ total.* }}, {{ thresholds.* }}, {{ files }} 구조를 기대)
        """
        tpl_path = pathlib.Path(template_path)
        if not tpl_path.exists():
            raise FileNotFoundError(f"Template not found: {template_path}")

        env = Environment(
            loader=FileSystemLoader(str(tpl_path.parent)),
            autoescape=select_autoescape(['html'])
        )
        tpl = env.get_template(tpl_path.name)
        html_str = tpl.render(files=files, total=total, thresholds=thresholds)

        # 템플릿이 report.css 같은 상대 경로를 쓸 때를 대비해 <base> 주입
        base_uri = tpl_path.parent.as_uri() + '/'
        if '<head' in html_str:
            html_str = html_str.replace('<head', f'<head><base href="{base_uri}">', 1)
        return html_str


    # ── 복잡도 분석(기존 유지) ───────────────────────────────────
    def run_complexity_analysis(self, *_):
        src = self.src_entry.get_text().strip()
        if not src or not pathlib.Path(src).is_file():
            self._toast('Source?', 'Choose a source file first.', 'warning')
            return

        # lizard 확인/설치
        if importlib.util.find_spec("lizard") is None:
            ask = Gtk.MessageDialog(self, 0, Gtk.MessageType.QUESTION, Gtk.ButtonsType.YES_NO,
                                    '“lizard” package not found.\nInstall it now?')
            if ask.run() != Gtk.ResponseType.YES:
                ask.destroy(); return
            ask.destroy()
            try:
                subprocess.check_call([sys.executable, '-m', 'pip', 'install', '--user', 'lizard'])
            except subprocess.CalledProcessError as e:
                self._toast('pip error', str(e), 'danger'); return

        # 1) 데이터 수집: CLI -j 시도 → 실패 시 API 폴백
        try:
            raw = self._collect_lizard_data([src])
        except Exception as e:
            self._toast('Analysis failed', str(e), 'danger'); return

        # 2) load_data()는 파일 경로를 받으니, 임시 JSON으로 한번 저장해서 재사용
        tmp_json = tempfile.NamedTemporaryFile(delete=False, suffix='.json'); tmp_json.close()
        pathlib.Path(tmp_json.name).write_text(json.dumps(raw), encoding='utf-8')

        # 2) JSON → 데이터
        try:
            files, total, th = load_data(tmp_json.name)
        except Exception as e:
            self._toast('Parse error', f'Invalid lizard JSON: {e}', 'danger')
            return
        finally:
            try: os.unlink(tmp_json.name)
            except Exception: pass

        # ── 여기서부터 템플릿 렌더 ─────────────────────────────
        # 템플릿 경로(원하면 Preferences에서 바인딩 가능)
        tpl_guess = pathlib.Path(__file__).parent / "report_template.html"
        template_path = str(tpl_guess)

        try:
            if not self._ensure_jinja2():
                return
            html_str = self._render_with_template(template_path, files, total, th)
        except FileNotFoundError:
            # 폴백: 인라인 Liquid Glass(이전 제공 코드의 _render_liquid_glass_report가 있다면 사용)
            try:
                html_str = self._render_liquid_glass_report(files, total, th)
            except Exception as e:
                self._toast('Template missing', f'report_template.html not found.\n{e}', 'danger')
                return
        except Exception as e:
            self._toast('Template error', str(e), 'danger')
            return

        # 3) WebKit에 로드
        for child in self.analysis_box.get_children():
            self.analysis_box.remove(child)

        tmp_html = tempfile.NamedTemporaryFile(delete=False, suffix='.html'); tmp_html.close()
        html_str = html_str.replace(">>", "/>")
        pathlib.Path(tmp_html.name).write_text(html_str, encoding='utf-8')
        self._last_lizard_html = tmp_html.name

        if WebKit2:
            web = WebKit2.WebView()
            self.analysis_box.pack_start(web, True, True, 0)
            web.load_uri(pathlib.Path(tmp_html.name).as_uri())
        else:
            buf = Gtk.TextBuffer()
            view = Gtk.TextView(buffer=buf, monospace=True); view.set_wrap_mode(Gtk.WrapMode.NONE)
            self.analysis_box.pack_start(view, True, True, 0)
            buf.set_text(html_str)

        self.analysis_box.show_all()
        self.nb.set_current_page(self.nb.page_num(self.analysis_box))
        self._toast('Done', 'Custom template report ready.', 'info')

    # ── 메뉴바(기존 유지) ────────────────────────────────────────
    def _build_menubar(self, parent_box: Gtk.Box):
        accel = Gtk.AccelGroup()
        self.add_accel_group(accel)

        menubar = Gtk.MenuBar()
        menubar.set_hexpand(True)
        menubar.get_style_context().add_class('menubar')

        def _add(mi, key, mod=Gdk.ModifierType.CONTROL_MASK):
            keyval = Gdk.keyval_from_name(key)
            mi.add_accelerator('activate', accel, keyval, mod, Gtk.AccelFlags.VISIBLE)

        # File
        file_menu   = Gtk.Menu()
        mi_file     = Gtk.MenuItem(label='File'); mi_file.set_submenu(file_menu)
        mi_open_src = Gtk.MenuItem(label='Open Source…'); mi_open_src.connect('activate', lambda *_: self.on_pick_src(None)); _add(mi_open_src, 'o'); file_menu.append(mi_open_src)
        mi_open_fold= Gtk.MenuItem(label='Open Batch Folder…'); mi_open_fold.connect('activate', lambda *_: self.on_pick_batch(None)); _add(mi_open_fold, 'b'); file_menu.append(mi_open_fold)
        file_menu.append(Gtk.SeparatorMenuItem())
        mi_exit = Gtk.MenuItem(label='Exit'); mi_exit.connect('activate', lambda *_: self.close()); _add(mi_exit, 'q'); file_menu.append(mi_exit)

        # Settings
        set_menu   = Gtk.Menu()
        mi_set     = Gtk.MenuItem(label='Settings'); mi_set.set_submenu(set_menu)
        mi_pref = Gtk.MenuItem(label='Preferences…'); mi_pref.connect('activate', lambda *_: self.open_preferences()); _add(mi_pref, 'comma'); set_menu.append(mi_pref)

        # Tools
        tools_menu = Gtk.Menu()
        mi_tools = Gtk.MenuItem(label='Tools'); mi_tools.set_submenu(tools_menu)
        mi_analyze = Gtk.MenuItem(label='Complexity Analysis'); mi_analyze.connect('activate', self.run_complexity_analysis); _add(mi_analyze, 'l'); tools_menu.append(mi_analyze)

        # Help
        help_menu = Gtk.Menu()
        mi_help   = Gtk.MenuItem(label='Help'); mi_help.set_submenu(help_menu)
        mi_about = Gtk.MenuItem(label='About'); mi_about.connect('activate', lambda *_: self._toast('About', '백준 문제 테스트 프로그램\n© 2025')); help_menu.append(mi_about)

        menubar.append(mi_file); menubar.append(mi_set); menubar.append(mi_tools); menubar.append(mi_help)
        parent_box.pack_start(menubar, False, False, 0)

    def open_preferences(self):
        dlg = PreferencesDialog(self, self.app_cfg)
        if dlg.run() == Gtk.ResponseType.OK:
            new_cfg = dlg.get_result()
            dlg.destroy()
            self.apply_settings(new_cfg)
        else:
            dlg.destroy()

    # ── 파일 선택 ────────────────────────────────────────────────
    def on_pick_src(self, _btn):
        dlg = Gtk.FileChooserNative(title='Select source', action=Gtk.FileChooserAction.OPEN)
        filt = Gtk.FileFilter();  filt.set_name('Source')
        for p in ('*.c','*.cpp','*.cc','*.cxx','*.java','*.py'): filt.add_pattern(p)
        dlg.add_filter(filt)
        if dlg.run() == Gtk.ResponseType.ACCEPT:
            self.src_entry.set_text(dlg.get_filename())
            self._load_source_preview(dlg.get_filename())
        dlg.destroy()

    def on_pick_batch(self, _btn):
        dlg = Gtk.FileChooserNative(title='Select folder', action=Gtk.FileChooserAction.SELECT_FOLDER)
        if dlg.run() == Gtk.ResponseType.ACCEPT:
            self.batch_entry.set_text(dlg.get_filename())
        dlg.destroy()

    def on_reload_code(self, _btn):
        path = self.src_entry.get_text().strip()
        if path:
            self._load_source_preview(path)

    def _load_source_preview(self, path:str):
        try:
            with open(path, 'r', encoding='utf-8', errors='replace') as f:
                code = f.read()
            self.source_buf.set_text(code)
            ext = pathlib.Path(path).suffix.lower()
            lang_id = {
                '.c': 'c', '.cpp': 'cpp', '.cc': 'cpp', '.cxx': 'cpp',
                '.java': 'java', '.py': 'python',
            }.get(ext)
            if lang_id:
                lm = GtkSource.LanguageManager()
                language = lm.get_language(lang_id)
                if language:
                    self.source_buf.set_language(language)
        except Exception as e:
            self._toast('Error', f"Cannot load source:\n{e}", 'danger')

    # ── 단일·배치 실행 핸들러 ─────────────────────────────────
    def on_run_single(self, _btn):
        src = self.src_entry.get_text().strip()
        if not src:
            self._toast('Warning', 'Select a source file first.'); return
        stdin = self._ask_stdin()
        self._set_running(True)
        threading.Thread(target=self._run_single_case, args=(src, stdin, '', False), daemon=True).start()

    def on_run_batch(self, _btn):
        folder = self.batch_entry.get_text().strip()
        src = self.src_entry.get_text().strip()
        if not (folder and pathlib.Path(folder).is_dir() and src):
            self._toast('Warning', 'Select source *and* batch folder.'); return
        cases = _find_test_cases(folder)
        if not cases:
            self._toast('Info', 'No input/output pairs found.'); return

        self._set_running(True)
        self.status_lbl.set_text(f'Batch 0/{len(cases)} running…')
        threading.Thread(target=self._batch_worker, args=(src, cases), daemon=True).start()

    # ── 실제 실행 + 결과 비교 ─────────────────────────────────
    def _run_single_case(self, src_path: str, stdin_text: str,
                         expected_path: str, is_batch: bool) -> tuple[bool, str]:
        try:
            lang, target, cwd = compile_source(src_path)
            cmd = get_run_cmd(lang, target)
            plugins = [MemoryLimitPlugin(self.mem_limit_bytes), CpuUsagePlugin()]
            code, out, err, elapsed, metrics = run_with_memory(
                cmd, stdin_text, cwd=cwd, timeout=self.timeout_sec, plugins=plugins)
            # 실행 후, prog_ 로 시작하는 임시 파일 삭제
            for tmp in glob.glob(os.path.join(cwd, 'prog_*')):
                try:
                    os.remove(tmp)
                except OSError:
                    pass
        except Exception as e:
            err_msg = str(e)
            def ui_err():
                self.err_buf.set_text(err_msg)
                self._set_running(False)
            GLib.idle_add(ui_err)
            return False, f"Compile/Runtime Error:\n{err_msg}"

        def ui():
            self.out_buf.set_text(out)
            self.err_buf.set_text(err)
            self.status_lbl.set_text(f"Exit {code} | {elapsed*1000:.1f} ms")
            if not is_batch:
                self._set_running(False)
            return False
        GLib.idle_add(ui)

        if not expected_path:
            return True, ""
        ok, compare_text = self.compare_output(expected_path, out)
        if not is_batch:
            def ui_update_compare():
                self.compare_buf.set_text(compare_text)
                if not ok:
                    self.nb.set_current_page(self.nb.page_num(self.cmp_scrolled_win))
                return False
            GLib.idle_add(ui_update_compare)
        return ok, compare_text

    # ── 배치 워커 ───────────────────────────────────────────
    def _batch_worker(self, src_path: str, cases: list[tuple[str, str]]):
        total = len(cases); passed = 0
        first_fail_info = None
        for idx, (in_path, out_path) in enumerate(cases, 1):
            with open(in_path, 'r', encoding='utf-8') as f:
                stdin = f.read()
            ok, compare_text = self._run_single_case(src_path, stdin, out_path, True)
            if ok:
                passed += 1
            elif first_fail_info is None:
                case_num = pathlib.Path(in_path).name
                first_fail_info = f"First failure on: {case_num}\n\n{compare_text}"
            GLib.idle_add(self.status_lbl.set_text, f'Batch {idx}/{total} - Passed {passed}')
        GLib.idle_add(self._batch_finished, passed, total, first_fail_info)

    def _batch_finished(self, passed: int, total: int, first_fail_info: str | None):
        self._toast('Done', f'Batch finished: {passed}/{total} passed.',
                    'success' if passed == total else 'warning')
        if first_fail_info:
            self.compare_buf.set_text(first_fail_info)
            self.nb.set_current_page(self.nb.page_num(self.cmp_scrolled_win))
        else:
            self.compare_buf.set_text(f"✅ All {total} test cases passed!")
        self.status_lbl.set_text('Ready')
        self._set_running(False)

    # ── 결과 비교 ────────────────────────────────────────────
    def compare_output(self, expected_path: str, actual: str) -> tuple[bool, str]:
        try:
            with open(expected_path, 'r', encoding='utf-8') as f:
                expected = [ln.rstrip('\n\r') for ln in f.readlines()]
        except Exception as e:
            GLib.idle_add(self._toast, 'Error', f'Cannot read expected file: {e}', 'danger')
            return False, f"Error reading expected file: {e}"

        actual_lines = [ln.rstrip('\n\r') for ln in actual.splitlines()]
        diff_info = None
        ok = True
        for idx, (e_line, a_line) in enumerate(itertools.zip_longest(expected, actual_lines), 1):
            if e_line is None:
                ok = False; diff_info = ('Actual longer than expected.', expected, actual_lines, idx); break
            if a_line is None:
                ok = False; diff_info = ('Actual shorter than expected.', expected, actual_lines, idx); break
            if not _line_to_regex(_normalize(e_line)).fullmatch(_normalize(a_line)):
                ok = False; diff_info = ('Content mismatch.', expected, actual_lines, idx); break

        if ok:
            return True, '✅ PASS – output matches expected.'
        else:
            message = self._build_diff_text(diff_info)
            return False, message

    def _build_diff_text(self, diff_info):
        why, exp, act, line_no = diff_info
        diff = '\n'.join(difflib.unified_diff(exp, act, fromfile='Expected', tofile='Actual', lineterm=''))
        return f'❌ FAIL (line {line_no}): {why}\n\n{diff}'

    # ── 단순 입력 팝업 ─────────────────────────────────────────
    def _ask_stdin(self) -> str:
        dlg = Gtk.MessageDialog(
            parent=self,
            flags=0,
            message_type=Gtk.MessageType.QUESTION,
            buttons=Gtk.ButtonsType.OK_CANCEL,
            text='Manual stdin (leave empty to skip)'
        )
        entry = Gtk.Entry(); entry.set_activates_default(True)
        dlg.get_content_area().pack_end(entry, False, False, 0); dlg.show_all()
        resp = dlg.run()
        text = entry.get_text()
        dlg.destroy()
        return text if resp == Gtk.ResponseType.OK else ''

    # ── 토스트/알림 ───────────────────────────────────────────
    def _toast(self, title: str, msg: str = '', style: str = 'info'):
        dlg_type = Gtk.MessageType.INFO if style == 'info' else Gtk.MessageType.WARNING if style == 'warning' else Gtk.MessageType.ERROR
        dlg = Gtk.MessageDialog(parent=self, flags=0, message_type=dlg_type, buttons=Gtk.ButtonsType.OK, text=title)
        if msg: dlg.format_secondary_text(msg)
        dlg.run(); dlg.destroy()

    # ── CSS (dark, mac-like) ──────────────────────────────────
    def _apply_css(self):
        css = b"""
            @define-color mac-bg-solid #202020;
            @define-color mac-fg #f2f2f7;
            @define-color mac-fg-sec #d1d1d6;
            @define-color mac-border #3a3a3c;
            @define-color mac-accent #0a84ff;
            window {
                background-color: transparent;
                color: @mac-fg;
                font-family: "SF Pro Display", Cantarell, sans-serif;
                font-size: 13px;
            }
            .chrome {
                background-color: @mac-bg-solid;
                border: 1px solid @mac-border;
                border-radius: 22px;
            }
            .titlebar { background-color: @mac-bg-solid; border: none; }
            .traffic-light {
                border-radius: 7px; background-clip: padding-box; transition: all 120ms ease-in-out;
                box-shadow: 0 0 0 1px rgba(0,0,0,0.25);
            }
            .traffic-light.red    { background-color: #ff5f57; }
            .traffic-light.yellow { background-color: #ffbd2e; }
            .traffic-light.green  { background-color: #28c840; }
            .traffic-light.hover  { box-shadow: inset 0 0 3px rgba(0,0,0,0.7); }

            .control-strip {
                background: shade(@mac-bg-solid, 1.08);
                border: 1px solid @mac-border;
                border-radius: 8px;
                padding: 8px;
            }
            notebook header.top {
                background-color: shade(@mac-bg-solid, 1.12);
                border-bottom: 1px solid @mac-border;
            }
            notebook tab {
                padding: 6px 14px;
                color: @mac-fg-sec;
                background-color: transparent;
                border-radius: 6px;
                border: none;
                border-bottom: 2px solid transparent;
                transition: all 120ms ease-in-out;
                margin-left: 6px;
            }
            notebook tab:hover { color: @mac-fg; background-color: shade(@mac-bg-solid, 1.25); }
            notebook tab:checked { color: @mac-fg; background-color: @mac-bg-solid; border-bottom-color: @mac-accent; }

            button, .button {
                background-color: @mac-border; border-radius: 6px; border: none; color: @mac-fg;
                padding: 5px 12px; transition: background-color 100ms ease-out;
            }
            button:hover, .button:hover  { background-color: shade(@mac-border, 1.15); }
            button:active, .button:active { background-color: shade(@mac-border, 0.85); }
            entry, textview {
                background-color: @mac-bg-solid; color: @mac-fg;
                border: 1px solid @mac-border; border-radius: 6px; padding: 5px 8px;
            }
            textview { padding: 6px; }
            entry:focus, textview:focus { border-color: @mac-accent; }

            scrollbar slider {
                min-width: 12px; min-height: 12px; border-radius: 6px; background-color: alpha(@mac-fg, 0.25);
            }
            scrollbar slider:hover   { background-color: alpha(@mac-fg, 0.40); }
            scrollbar slider:active  { background-color: alpha(@mac-fg, 0.55); }
            label { color: @mac-fg; }
            .secondary { color: @mac-fg-sec; }
            .menubar { background: @mac-bg-solid; padding: 2px 4px; }
            .menubar menuitem { color: @mac-fg-sec; padding: 4px 8px; }
            .menubar menuitem:hover { background: shade(@mac-bg-solid,1.25); color:@mac-fg; }
        """
        prov = Gtk.CssProvider(); prov.load_from_data(css)
        Gtk.StyleContext.add_provider_for_screen(Gdk.Screen.get_default(), prov, Gtk.STYLE_PROVIDER_PRIORITY_APPLICATION)

    # ── 드래그&드롭: Entry에 파일/폴더 투하 ─────────────────────
    def _enable_dnd(self):
        target = [Gtk.TargetEntry.new('text/uri-list', 0, 0)]
        for entry, want_dir in ((self.src_entry, False), (self.batch_entry, True)):
            entry.drag_dest_set(Gtk.DestDefaults.ALL, target, Gdk.DragAction.COPY)
            entry.connect('drag-data-received', self._on_drag_data_received, want_dir)

    def _on_drag_data_received(self, widget, drag_context, x, y, data, info, time_, want_dir: bool):
        try:
            uris = data.get_uris() if hasattr(data, 'get_uris') else []
            if not uris:
                text = data.get_text() or ''
                uris = [t.strip() for t in text.split()] if text else []
            if not uris:
                drag_context.finish(False, False, time_); return
            filename, _host = GLib.filename_from_uri(uris[0])
            if want_dir:
                # 폴더가 아니면 그 상위 폴더를 사용
                path = filename if os.path.isdir(filename) else os.path.dirname(filename)
                self.batch_entry.set_text(path)
            else:
                if os.path.isdir(filename):
                    # 폴더를 던졌다면 무시
                    drag_context.finish(False, False, time_); return
                self.src_entry.set_text(filename)
                self._load_source_preview(filename)
            drag_context.finish(True, False, time_)
        except Exception:
            drag_context.finish(False, False, time_)

class PreferencesDialog(Gtk.Dialog):
    def __init__(self, parent, cfg):
        super().__init__(title='Preferences', transient_for=parent, flags=0)
        self.set_modal(True)
        self.add_buttons(Gtk.STOCK_CANCEL, Gtk.ResponseType.CANCEL,
                         Gtk.STOCK_OK,     Gtk.ResponseType.OK)

        self.set_default_size(420, 300)
        self.cfg = cfg.copy()
        box = self.get_content_area()

        notebook = Gtk.Notebook(); box.add(notebook)

        # --- Appearance 탭 ----------------------------
        appearance = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
        appearance.set_border_width(12)
        notebook.append_page(appearance, Gtk.Label(label='Appearance'))

        font_store = Gtk.ListStore(str)
        context = self.get_pango_context()
        families = context.list_families() if context else []
        for fam in sorted(families, key=lambda f: f.get_name()):
            font_store.append([fam.get_name()])

        def font_combo(active_name):
            combo = Gtk.ComboBox.new_with_model(font_store)
            renderer = Gtk.CellRendererText(); combo.pack_start(renderer, True)
            combo.add_attribute(renderer, "text", 0)
            for i, row in enumerate(font_store):
                if row[0] == active_name:
                    combo.set_active(i); break
            return combo

        grid = Gtk.Grid(column_spacing=8, row_spacing=8)
        appearance.pack_start(grid, False, False, 0)

        grid.attach(Gtk.Label(label='Base font:'), 0, 0, 1, 1)
        self.cmb_base = font_combo(cfg['base_font']); grid.attach(self.cmb_base, 1, 0, 1, 1)

        grid.attach(Gtk.Label(label='Monospace font:'), 0, 1, 1, 1)
        self.cmb_mono = font_combo(cfg['mono_font']); grid.attach(self.cmb_mono, 1, 1, 1, 1)

        grid.attach(Gtk.Label(label='Font size:'), 0, 2, 1, 1)
        self.spin_size = Gtk.SpinButton.new_with_range(8, 32, 1)
        self.spin_size.set_value(cfg['font_size'])
        grid.attach(self.spin_size, 1, 2, 1, 1)

        # GtkSourceView Style Scheme
        scheme_mgr = GtkSource.StyleSchemeManager()
        schemes = sorted(scheme_mgr.get_scheme_ids())
        self.cmb_scheme = Gtk.ComboBoxText()
        for sid in schemes: self.cmb_scheme.append_text(sid)
        self.cmb_scheme.set_active(schemes.index(cfg['style_scheme'])
                                   if cfg['style_scheme'] in schemes else 0)
        grid.attach(Gtk.Label(label='Syntax theme:'), 0, 3, 1, 1)
        grid.attach(self.cmb_scheme, 1, 3, 1, 1)

        # --- Execution 탭 -----------------------------
        execbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
        execbox.set_border_width(12)
        notebook.append_page(execbox, Gtk.Label(label='Execution'))

        g2 = Gtk.Grid(column_spacing=8, row_spacing=8)
        execbox.pack_start(g2, False, False, 0)

        g2.attach(Gtk.Label(label='Timeout (sec):'), 0, 0, 1, 1)
        self.spin_timeout = Gtk.SpinButton.new_with_range(1, 300, 1)
        self.spin_timeout.set_value(cfg['timeout'])
        g2.attach(self.spin_timeout, 1, 0, 1, 1)

        g2.attach(Gtk.Label(label='Memory limit (MB, 0 = ∞):'), 0, 1, 1, 1)
        self.spin_mem = Gtk.SpinButton.new_with_range(0, 16384, 16)
        self.spin_mem.set_value(cfg['mem_limit_mb'])
        g2.attach(self.spin_mem, 1, 1, 1, 1)

        self.show_all()

    def get_result(self):
        base_font = self.cmb_base.get_active_iter()
        mono_font = self.cmb_mono.get_active_iter()
        scheme    = self.cmb_scheme.get_active_text()
        sf = self.cmb_base.get_model()[base_font][0] if base_font else self.cfg['base_font']
        sm = self.cmb_mono.get_model()[mono_font][0] if mono_font else self.cfg['mono_font']
        return {
            'base_font'   : sf,
            'mono_font'   : sm,
            'font_size'   : self.spin_size.get_value_as_int(),
            'style_scheme': scheme,
            'timeout'     : self.spin_timeout.get_value_as_int(),
            'mem_limit_mb': self.spin_mem.get_value_as_int()
        }

# ─── 실행 ───────────────────────────────────────────────────────
if __name__ == '__main__':
    win = MainWindow(); win.show_all(); Gtk.main()
