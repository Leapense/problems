#!/usr/bin/env python3
# multi_run_mem_gui.py  –  ttkbootstrap(darkly) + 정확한 RSS + Java cwd fix

import importlib
from itertools import zip_longest
import re
import shutil
import os, sys, time, threading, subprocess, tempfile, platform, resource, json
import webbrowser
import psutil                                       # pip install psutil
import shlex
import fnmatch
from functools import partial
import pathlib
import datetime
import matplotlib
import pyperclip
matplotlib.use('TkAgg')
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
from typing import Optional, Callable
from difflib import unified_diff

# ─── GUI 라이브러리 ───────────────────────────────────────────────
import ttkbootstrap as tb                           # pip install ttkbootstrap
from ttkbootstrap import ttk
from ttkbootstrap.scrolled import ScrolledText
from tkinter import filedialog
import tkinter.messagebox as msgbox
import tkinter.font as tkfont
import tkinter as tk
from ttkbootstrap.toast import ToastNotification
from tkinter import PhotoImage

# ─── 언어 판별 & 컴파일 ──────────────────────────────────────────
def detect_lang(path: str) -> str | None:
    return {
        '.c': 'c', '.cpp': 'cpp', '.cc': 'cpp', '.cxx': 'cpp',
        '.java': 'java', '.py': 'python'
    }.get(os.path.splitext(path)[1].lower())

def compile_source(src: str):
    """
    compile → (lang, 실행경로(또는 클래스), 작업폴더) 반환
    """
    lang = detect_lang(src)
    if lang is None:
        raise RuntimeError('지원하지 않는 확장자')

    workdir = os.path.dirname(os.path.abspath(src))

    if lang in ('c', 'cpp'):
        exe = tempfile.mktemp(prefix='prog_', dir=workdir)
        # C++26, C23은 아직 일부 컴파일러에서 완전 지원되지 않으므로 안정적인 버전으로 조정
        cmd = ['gcc' if lang == 'c' else 'g++', src,
               '-O2', '-std=c17' if lang == 'c' else '-std=c++20',
               '-Wall', '-pipe', '-o', exe]
        res = subprocess.run(cmd, capture_output=True, text=True)
        if res.returncode != 0:
            raise RuntimeError(f"gcc/g++ compile error\n\n"
                               f"$ {' '.join(map(shlex.quote, cmd))}\n"
                               f"{res.stderr.strip()}")
        return lang, exe, workdir

    if lang == 'java':
        res = subprocess.run(['javac', '-d', workdir, src], capture_output=True, text=True)
        if res.returncode != 0:
            raise RuntimeError(f"javac error\n\n{res.stderr.strip()}")
        main_class = os.path.splitext(os.path.basename(src))[0]
        return lang, main_class, workdir

    # python – 컴파일 과정 없음
    return lang, src, workdir

# ─── Linux 전용: /proc 으로 최대 RSS 확보 ────────────────────────
def _linux_rss_fallback(pid: int) -> int:
    try:
        with open(f"/proc/{pid}/status") as f:
            for line in f:
                if line.startswith("VmHWM:"):
                    kb = int(line.split()[1])
                    return kb * 1024
    except FileNotFoundError:
        pass
    return 0

# ─── 실행 + 메모리 측정 ──────────────────────────────────────────
def run_with_memory(cmd: list, stdin_data: str = '',
                    cwd: str | None = None, timeout: int = 10,
                    plugins: list['PluginBase'] = None):
    """
    returns (exit_code, stdout, stderr, elapsed_sec, plugin_results)
    """
    plugins = plugins or []
    start_time = time.time()
    proc = None
    
    try:
        proc = subprocess.Popen(cmd, cwd=cwd, text=True,
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)
        
        ps_proc = psutil.Process(proc.pid)

        for p in plugins:
            p.on_start(ps_proc)

        def monitor():
            try:
                while proc.poll() is None:
                    for p in plugins:
                        p.on_sample()
                    time.sleep(0.05)
            except psutil.Error:
                pass
        
        monitor_thread = threading.Thread(target=monitor, daemon=True)
        monitor_thread.start()

        out, err = proc.communicate(input=stdin_data, timeout=timeout)
        
    except subprocess.TimeoutExpired:
        if proc:
            proc.kill()
            out, err = proc.communicate()
        err += f"\n\n--- Timeout ({timeout}s) Expired ---"
    except Exception as e:
        return -1, "", str(e), time.time() - start_time, {}

    elapsed = time.time() - start_time
    
    plugin_results = {}
    for p in plugins:
        plugin_results.update(p.on_finish())

    return proc.returncode, out, err, elapsed, plugin_results


# ... (PathBar, CustomFileDialog, SettingsDialog, Plugins 등 나머지 클래스는 변경 없이 그대로 유지) ...
# 여기에 기존 코드의 PathBar, CustomFileDialog, SettingsDialog, PluginBase, 
# MemoryLimitPlugin, CpuUsagePlugin 클래스를 그대로 붙여넣으세요.
# (너무 길어서 생략합니다)
class PathBar(ttk.Frame): # ttk.Frame을 사용 (ttkbootstrap의 Frame)
    def __init__(self, parent, path, callback, style="flatly"): # style 매개변수 추가 및 기본값 설정
        super().__init__(parent)
        self.callback = callback
        self.sep = " > "
        self.max_parts = 5
        self.style_name = style # self.style_name 인스턴스 변수 설정

        

        # 기본 폰트 및 밑줄 폰트 설정
        default_font_str = None
        # self.winfo_toplevel()이 tb.Window (ttkbootstrap.Window) 인스턴스인지 확인
        if isinstance(self.winfo_toplevel(), tb.Window):
            s = tb.Style.get_instance() # ttkbootstrap의 Style 객체 가져오기
            # bootstyle에 해당하는 Label 스타일에서 폰트를 가져오려고 시도
            # (예: "primary.TLabel"). 없을 경우 기본 "TLabel" 폰트 사용.
            # ttkbootstrap 테마가 {color}.TLabel 형태의 스타일을 항상 제공하지는 않음.
            # 그래서 먼저 시도하고, 없으면 기본 TLabel 폰트를 사용.
            # 또는, 항상 s.lookup("TLabel", "font")를 사용하고 bootstyle은 색상만 변경하도록 할 수도 있음.
            # 여기서는 기존 로직을 최대한 살리되, self.style_name이 정의되도록 함.
            if self.style_name: # style_name이 제공된 경우
                default_font_str = s.lookup(f"{self.style_name}.TLabel", "font")

            if not default_font_str: # 특정 스타일 폰트가 없거나 style_name이 없는 경우
                 default_font_str = s.lookup("TLabel", "font") # 테마의 기본 Label 폰트
        
        if not default_font_str: # ttkbootstrap에서 폰트를 못 찾았거나, 일반 tkinter 환경일 경우
            # 일반 tkinter 환경이거나, 위에서 폰트를 못찾은 경우 ttk.Style() 사용
            # (from ttkbootstrap import ttk를 사용했으므로, ttk.Style()은 ttkbootstrap.Style()임)
            # 순수 tkinter/ttk 환경을 고려한다면, 별도의 ttk.Style()이 필요할 수 있으나,
            # 현재 코드는 ttkbootstrap 기반이므로 tb.Style()로 통일 가능.
            # 위 if문에서 tb.Window가 아니면 이쪽으로 올 수 없음.
            # 따라서 이 else 블록은 사실상 위 if문에서 default_font_str을 못찾은 경우의 fallback.
            # 만약 순수 ttk를 위한 분기를 원한다면 isinstance 체크를 더 명확히 해야함.
            # 여기서는 ttkbootstrap 환경을 가정하고, 위에서 못찾은 경우의 fallback으로 처리.
            if not isinstance(self.winfo_toplevel(), tb.Window): # 순수 ttk 환경 대비 (이론상)
                s_std_ttk = tk.ttk.Style() # 표준 tkinter.ttk.Style
                default_font_str = s_std_ttk.lookup("TLabel", "font")

        if not default_font_str: # 모든 시도 후에도 폰트를 못 찾으면 Tkinter 기본값
            default_font_str = "TkDefaultFont"


        self.base_font = tkfont.nametofont(default_font_str)
        self.underline_font = tkfont.Font(**self.base_font.actual())
        self.underline_font.configure(underline=True)

        self.canvas = tk.Canvas(self, highlightthickness=0, height=self.base_font.metrics("linespace") + 4)
        self.hsb = ttk.Scrollbar(self, orient='horizontal', command=self.canvas.xview)
        self.canvas.configure(xscrollcommand=self.hsb.set)
        self.canvas.pack(fill='x', side='top', expand=True)
        self._hsb_visible = False

        self.inner = ttk.Frame(self.canvas)
        self._window = self.canvas.create_window((0,0), window=self.inner, anchor='nw')

        self.set_path(path)

        self.inner.bind("<Configure>", self._on_frame_configure)
        self.canvas.bind("<Configure>", self._on_canvas_configure)

    def _on_frame_configure(self, event):
        # inner frame 의 너비가 변경되면 canvas scrollregion 갱신
        self.canvas.configure(scrollregion=self.canvas.bbox("all"))
        inner_w = self.canvas.bbox("all")[2] if self.canvas.bbox("all") else 0
        canvas_w = self.canvas.winfo_width()
        if inner_w > canvas_w and not self._hsb_visible:
            self.hsb.pack(fill='x', side='bottom')
            self._hsb_visible = True
        elif inner_w <= canvas_w and self._hsb_visible:
            self.hsb.pack_forget()
            self._hsb_visible = False

    def _on_canvas_configure(self, event):
        # canvas 가 리사이즈 되면 inner frame 너비를 최소 canvas 와 같게
        canvas_w = event.width
        self.canvas.itemconfig(self._window, width=canvas_w)

    def set_path(self, path:str):
        # 이전 라벨들 제거
        for w in self.inner.winfo_children():
            w.destroy()

        # 파트 분리
        p = pathlib.Path(os.path.normpath(path))
        parts = p.parts or (path,)

        # 너무 많은 파트를 중간 “…” 로 생략
        if len(parts) > self.max_parts:
            visible = [parts[0], '…'] + list(parts[-(self.max_parts-1):])
        else:
            visible = parts

        # 라벨 생성
        for i, text in enumerate(visible):
            # ellipsis (“…”) 클릭 시 전체 메뉴 노출
            if text == "…":
                lbl = ttk.Label(self.inner, text=text, font=self.base_font, bootstyle=self.style_name)
                lbl.bind("<Button-1>", self._show_full_menu)
            else:
                # 정상 경로 파트
                lbl = ttk.Label(self.inner, text=text, font=self.base_font, bootstyle=self.style_name)
                # 마우스 오버 시 밑줄, 클릭 가능한 커서
                lbl.bind("<Enter>",  lambda e, l=lbl: l.configure(font=self.underline_font, cursor="hand2"))
                lbl.bind("<Leave>",  lambda e, l=lbl: l.configure(font=self.base_font,      cursor=""))
                # 클릭시 해당 경로로 이동
                # 실제 경로 조합
                full_path = os.path.join(*parts[: parts.index(text)+1 ])
                lbl.bind("<Button-1>", partial(self._on_label_click, full_path))

            lbl.pack(side='left', padx=(2,0))
            # 뒤에 구분자
            if i < len(visible)-1:
                sep_lbl = ttk.Label(self.inner, text=self.sep, font=self.base_font, bootstyle=self.style_name)
                sep_lbl.pack(side='left', padx=0)

    def _show_full_menu(self, event):
        """… 라벨 클릭 시 전체 경로 파트를 메뉴로 보여줌"""
        menu = tk.Menu(self, tearoff=0)
        p = pathlib.Path(self.callback.__self__.current_dir)  # 현재 경로
        all_parts = p.parts
        for idx, part in enumerate(all_parts):
            full_p = os.path.join(*all_parts[:idx+1])
            menu.add_command(label=full_p, command=partial(self._on_label_click, full_p))
        # 마우스 우클릭 위치에 메뉴 띄우기
        menu.tk_popup(event.x_root, event.y_root)

    def _on_label_click(self, path, event=None):
        self.callback(path)

# File Picker 팝업 (재디자인 버전)
class CustomFileDialog(tb.Toplevel):
    _col_caption = {
        "name": "Name",
        "date": "Date modified",
        "type": "Type",
        "size": "Size"
    }
    PLACEHOLDER = "Search current directory..."
    EXT_COLORS = {
        '.py': '#B0F7B4',
        '.cpp': '#B0D0F7',
        '.c': '#B0D0F7',
        '.java': '#f2b468',
        '.md': '#9468f2',
    }
    CFG_PATH = pathlib.Path.home() / ".custom_file_dialog.json"

    def __init__(self, parent, title="Select File", initialdir=None, filetypes=None, callback=None, copy_cfg=None):
        super().__init__(parent)
        self.title(title)
        self.resizable(True, True)
        self.grab_set()
        self.geometry("1000x650")
        self.minsize(600, 400)

        self.callback = callback
        self.filetypes = filetypes or [("All files", "*.*")]
        self.selected_file = tb.StringVar()

        # --- 상태 및 데이터 로드 ---
        state = self._load_state()
        self.history = state.get("history", [])
        self._last_child = state.get("last_child", {})
        self.bookmarks = state.get("bookmarks", [])

        self.current_dir = os.path.abspath(initialdir or state.get("last_dir", os.getcwd()))
        if not os.path.isdir(self.current_dir):
            self.current_dir = os.getcwd()

        if not self.history:
            self.history = [self.current_dir]
        self.history_index = len(self.history) - 1
        
        # --- 메인 레이아웃 (PanedWindow) ---
        main_pane = ttk.PanedWindow(self, orient='horizontal')
        main_pane.pack(fill='both', expand=True, padx=10, pady=5)

        # --- 1. 왼쪽 패널 (북마크) ---
        left_pane = self._setup_left_pane(main_pane)
        main_pane.add(left_pane, weight=1)

        # --- 2. 오른쪽 패널 (파일 목록) ---
        right_pane = ttk.Frame(main_pane)
        main_pane.add(right_pane, weight=4)

        self._setup_toolbar(right_pane)
        self._setup_treeview(right_pane)
        self._setup_bottom_bar(right_pane)

        # --- 초기화 ---
        self._current_sort = ("name", False)
        self._populate_bookmarks()
        self.populate()
        self._restore_selection()
        self.update_nav_buttons()

    def _setup_left_pane(self, parent):
        """북마크 및 시스템 폴더를 표시하는 왼쪽 패널 구성"""
        frame = ttk.Labelframe(parent, text="Places", padding=5)
        
        # 북마크 Treeview
        self.bookmark_tree = ttk.Treeview(frame, show="tree", selectmode="browse")
        self.bookmark_tree.pack(fill='both', expand=True)
        self.bookmark_tree.bind("<<TreeviewSelect>>", self._on_bm_select)

        # 북마크 관리 버튼
        btn_fr = ttk.Frame(frame)
        btn_fr.pack(fill='x', pady=(5, 0))
        ttk.Button(btn_fr, text="+", width=2, command=self._add_bookmark, bootstyle='secondary-link').pack(side='left', padx=2)
        ttk.Button(btn_fr, text="-", width=2, command=self._remove_bookmark, bootstyle='secondary-link').pack(side='left', padx=2)
        
        return frame

    def _setup_toolbar(self, parent):
        """상단 툴바 구성 (네비게이션, 경로, 검색)"""
        toolbar = ttk.Frame(parent)
        toolbar.pack(fill='x', pady=(0, 5))
        toolbar.columnconfigure(1, weight=1)

        nav_frame = ttk.Frame(toolbar)
        nav_frame.grid(row=0, column=0, padx=(0, 5))
        self.prev_btn = ttk.Button(nav_frame, text="<", width=3, command=self.go_prev, bootstyle='secondary-link')
        self.prev_btn.pack(side='left')
        self.next_btn = ttk.Button(nav_frame, text=">", width=3, command=self.go_next, bootstyle='secondary-link')
        self.next_btn.pack(side='left')
        ttk.Button(nav_frame, text="↑", width=3, command=self.go_up, bootstyle='secondary-link').pack(side='left')
        ttk.Button(nav_frame, text="↻", width=3, command=self.refresh, bootstyle='secondary-link').pack(side='left')

        self.pathbar = PathBar(toolbar, self.current_dir, self.change_dir)
        self.pathbar.grid(row=0, column=1, sticky='ew')

        self.search_var = tb.StringVar()
        search_frame = ttk.Frame(toolbar)
        search_frame.grid(row=0, column=2, padx=5)
        self.search_entry = ttk.Entry(search_frame, textvariable=self.search_var, width=25)
        self.search_entry.pack(side='left')
        self.search_entry.insert(0, self.PLACEHOLDER)
        self.search_entry.bind("<FocusIn>", self._clear_placeholder)
        self.search_entry.bind("<FocusOut>", self._add_placeholder)
        self.search_entry.bind("<KeyRelease>", lambda e: self.populate())
        ttk.Label(search_frame, text="🔍").pack(side='left', padx=(0, 5))

    def _setup_treeview(self, parent):
        """파일/폴더 목록을 표시하는 Treeview 구성"""
        tree_frame = ttk.Frame(parent)
        tree_frame.pack(fill='both', expand=True)
        tree_frame.rowconfigure(0, weight=1)
        tree_frame.columnconfigure(0, weight=1)

        columns = ("name", "date", "type", "size")
        self.tree = ttk.Treeview(tree_frame, columns=columns, show="headings", selectmode="browse")
        
        # 아이콘 태그
        self.tree.tag_configure('folder')
        self.tree.tag_configure('file')
        for ext, clr in self.EXT_COLORS.items():
            self.tree.tag_configure(f"ext_{ext}", foreground=clr)

        vsb = ttk.Scrollbar(tree_frame, orient="vertical", command=self.tree.yview)
        hsb = ttk.Scrollbar(tree_frame, orient="horizontal", command=self.tree.xview)
        self.tree.configure(yscrollcommand=vsb.set, xscrollcommand=hsb.set)

        self.tree.grid(row=0, column=0, sticky='nsew')
        vsb.grid(row=0, column=1, sticky='ns')
        hsb.grid(row=1, column=0, sticky='ew')

        for col in columns:
            self.tree.heading(col, text=self._col_caption[col], command=lambda c=col: self._sort_by_column(c))
        
        self.tree.column("name", width=350, stretch=True)
        self.tree.column("date", width=150, stretch=False)
        self.tree.column("type", width=120, stretch=False)
        self.tree.column("size", width=100, anchor='e', stretch=False)

        self.tree.bind("<Double-1>", self.on_double_click)
        self.tree.bind("<<TreeviewSelect>>", self.on_select)

    def _setup_bottom_bar(self, parent):
        """하단 파일 이름 입력 및 버튼 영역 구성"""
        bottom_frame = ttk.Frame(parent)
        bottom_frame.pack(fill='x', pady=(5, 0))
        bottom_frame.columnconfigure(1, weight=1)

        ttk.Label(bottom_frame, text="File name:").grid(row=0, column=0, padx=(0, 5), pady=5)
        ttk.Entry(bottom_frame, textvariable=self.selected_file).grid(row=0, column=1, sticky='ew', pady=5)
        
        btn_frame = ttk.Frame(bottom_frame)
        btn_frame.grid(row=0, column=2, padx=(10, 0))
        ttk.Button(btn_frame, text="OK", command=self.on_ok, bootstyle='primary').pack(side='left')
        ttk.Button(btn_frame, text="Cancel", command=self.destroy, bootstyle='secondary').pack(side='left', padx=5)

    # --- 북마크 관련 메서드 ---
    def _populate_bookmarks(self):
        self.bookmark_tree.delete(*self.bookmark_tree.get_children())
        
        # 시스템 기본 폴더 추가
        places = {
            "Home": pathlib.Path.home(),
            "Documents": pathlib.Path.home() / "Documents",
            "Downloads": pathlib.Path.home() / "Downloads",
            "Desktop": pathlib.Path.home() / "Desktop"
        }
        sys_node = self.bookmark_tree.insert("", "end", text=" Quick Access", open=True)
        for name, path in places.items():
            if path.exists():
                self.bookmark_tree.insert(sys_node, "end", text=f" {name}", values=[str(path)])

        # 사용자 지정 북마크 추가
        if self.bookmarks:
            bm_node = self.bookmark_tree.insert("", "end", text=" Bookmarks", open=True)
            for path_str in self.bookmarks:
                path = pathlib.Path(path_str)
                if path.exists():
                    self.bookmark_tree.insert(bm_node, "end", text=f" {path.name}", values=[str(path)])

    def _add_bookmark(self):
        p = self.current_dir
        if p not in self.bookmarks:
            self.bookmarks.append(p)
            self._populate_bookmarks()

    def _remove_bookmark(self):
        sel_id = self.bookmark_tree.selection()
        if not sel_id: return
        
        # 시스템 폴더는 삭제 불가
        if self.bookmark_tree.parent(sel_id[0]) == "": return

        path_to_remove = self.bookmark_tree.item(sel_id[0], "values")[0]
        if path_to_remove in self.bookmarks:
            self.bookmarks.remove(path_to_remove)
            self._populate_bookmarks()

    def _on_bm_select(self, event):
        sel_id = self.bookmark_tree.selection()
        if not sel_id: return
        
        values = self.bookmark_tree.item(sel_id[0], "values")
        if values:
            self.change_dir(values[0])

    # --- 파일 목록 채우기 및 정렬 ---
    def populate(self):
        self.tree.delete(*self.tree.get_children())
        search_term = self.search_var.get().strip().lower()
        if search_term == self.PLACEHOLDER.lower():
            search_term = ""

        try:
            entries = sorted(os.listdir(self.current_dir), key=str.lower)
        except OSError:
            entries = []
        
        dirs, files = [], []
        for name in entries:
            if search_term and search_term not in name.lower():
                continue
            
            full_path = os.path.join(self.current_dir, name)
            try:
                if os.path.isdir(full_path):
                    dirs.append(name)
                elif self._match_filetypes(name):
                    files.append(name)
            except OSError:
                continue

        for d in dirs:
            path = os.path.join(self.current_dir, d)
            mtime = self._format_time(os.path.getmtime(path))
            self.tree.insert("", "end", values=(f" {d}", mtime, "Folder", ""), tags=('folder',))
        
        for f in files:
            path = os.path.join(self.current_dir, f)
            size = os.path.getsize(path)
            mtime = self._format_time(os.path.getmtime(path))
            ext = os.path.splitext(f)[1].lower()
            ftype = self._file_type(ext)
            
            tags = ['file']
            if ext in self.EXT_COLORS:
                tags.append(f"ext_{ext}")
            
            self.tree.insert("", "end", values=(f" {f}", mtime, ftype, self._format_size(size)), tags=tuple(tags))

        col, rev = self._current_sort
        self._sort_by_column(col, keep_direction=True)

    # ... (기존 _sort_by_column, _str_size_to_int, _file_type, _format_time, _match_filetypes, _format_size 메서드는 그대로 유지) ...
    def _sort_by_column(self, col, keep_direction=False):
        if keep_direction:
            reverse = self._current_sort[1]
        else:
            reverse = not self._current_sort[1] if self._current_sort[0] == col else False
        self._current_sort = (col, reverse)

        # 데이터 가져오기 (이름 앞 공백 제거)
        items = [(self.tree.set(k, col).strip(), k) for k in self.tree.get_children('')]

        # 정렬 키 함수
        def sort_key(item):
            value = item[0]
            if col == "size":
                return self._str_size_to_int(value)
            if col == "date":
                try:
                    return datetime.datetime.strptime(value, "%Y-%m-%d %H:%M")
                except ValueError:
                    return datetime.datetime.min
            # 폴더/파일 구분 정렬: 폴더가 항상 위로 오도록
            is_folder = self.tree.set(item[1], "type") == "Folder"
            return (not is_folder, value.lower())

        items.sort(key=sort_key, reverse=reverse)

        for i, (val, k) in enumerate(items):
            self.tree.move(k, '', i)

        # 헤더에 정렬 방향 표시
        for c in self.tree["columns"]:
            text = self._col_caption[c]
            if c == col:
                text += " ▲" if not reverse else " ▼"
            self.tree.heading(c, text=text, command=lambda c=c: self._sort_by_column(c))

    @staticmethod
    def _str_size_to_int(txt):
        if not txt:
            return 0
        try:
            num, unit = txt.split()
            num = float(num)
            unit = unit.upper()
            factor = {"B":1, "KB":1024, "MB":1024**2, "GB":1024**3, "TB":1024**4}
            return int(num * factor.get(unit, 1))
        except (ValueError, IndexError):
            return 0

    def _file_type(self, ext):
        if ext in (".md",):
            return "MD file"
        elif ext in (".py", ".c", ".cpp", ".java"):
            return "Source file"
        elif ext:
            return f"{ext[1:].upper()} file"
        else:
            return "File"

    def _format_time(self, t):
        return time.strftime("%Y-%m-%d %H:%M", time.localtime(t))

    def _match_filetypes(self, filename):
        if self.filetypes[0][1] == "*.*": return True
        for desc, patterns in self.filetypes:
            for pat in patterns.split():
                if fnmatch.fnmatch(filename, pat):
                    return True
        return False

    def _format_size(self, size):
        if size is None: return ""
        for unit in ['B','KB','MB','GB']:
            if size < 1024.0:
                return f"{size:.0f} {unit}"
            size /= 1024.0
        return f"{size:.1f} TB"

    # --- 이벤트 핸들러 및 네비게이션 ---
    def on_double_click(self, event):
        item_id = self.tree.focus()
        if not item_id: return
        
        values = self.tree.item(item_id, "values")
        name = values[0].strip()
        
        if values[2] == "Folder":
            self._enter_directory(name)
        else:
            self.selected_file.set(name)
            self.on_ok()

    def on_select(self, event):
        item_id = self.tree.focus()
        if not item_id: return
        
        values = self.tree.item(item_id, "values")
        name = values[0].strip()
        
        if values[2] != "Folder":
            self.selected_file.set(name)
        else:
            self.selected_file.set("")

    def on_ok(self):
        file_name = self.selected_file.get().strip()
        if not file_name:
            msgbox.showwarning("No file selected", "Please select a file from the list.", parent=self)
            return
            
        full_path = os.path.join(self.current_dir, file_name)
        if os.path.isfile(full_path):
            if self.callback:
                self.callback(full_path)
            self.destroy()
        else:
            msgbox.showerror("Invalid File", f"The file '{file_name}' does not exist.", parent=self)

    def go_up(self):
        new_dir = os.path.dirname(self.current_dir)
        if new_dir != self.current_dir:
            self.change_dir(new_dir)
    
    # ... (기존 change_dir, _save_state, _load_state, go_prev, go_next, refresh, update_nav_buttons, destroy 등은 유지) ...
    # 단, _save_state에 bookmarks와 last_dir 저장 로직 추가
    def change_dir(self, new_dir):
        new_dir = os.path.abspath(new_dir)
        if not os.path.isdir(new_dir): return
        
        if new_dir != self.current_dir:
            if self.history_index < len(self.history) - 1:
                self.history = self.history[:self.history_index+1]
            self.history.append(new_dir)
            self.history_index += 1
            
            self.current_dir = new_dir
            self.pathbar.set_path(self.current_dir)
            self.populate()
            self._restore_selection()
            self.update_nav_buttons()

    def _save_state(self):
        try:
            with self.CFG_PATH.open("w", encoding="utf-8") as fp:
                json.dump({
                    "history": self.history[-100:],
                    "last_child": self._last_child,
                    "bookmarks": self.bookmarks,
                    "last_dir": self.current_dir
                }, fp, indent=2)
        except Exception as e:
            print("Dialog state 저장 실패:", e)

    def _load_state(self):
        if self.CFG_PATH.exists():
            try:
                with self.CFG_PATH.open("r", encoding="utf-8") as fp:
                    return json.load(fp)
            except Exception:
                return {}
        return {}
    
    def go_prev(self):
        if self.history_index > 0:
            self.history_index -= 1
            self.current_dir = self.history[self.history_index]
            self.pathbar.set_path(self.current_dir)
            self.populate()
            self._restore_selection()
            self.update_nav_buttons()

    def go_next(self):
        if self.history_index < len(self.history) - 1:
            self.history_index += 1
            self.current_dir = self.history[self.history_index]
            self.pathbar.set_path(self.current_dir)
            self.populate()
            self._restore_selection()
            self.update_nav_buttons()

    def refresh(self):
        self.populate()

    def update_nav_buttons(self):
        self.prev_btn['state'] = 'normal' if self.history_index > 0 else 'disabled'
        self.next_btn['state'] = 'normal' if self.history_index < len(self.history) - 1 else 'disabled'
    
    def destroy(self):
        self._save_state()
        super().destroy()

    # --- 나머지 헬퍼 메서드 ---
    def _enter_directory(self, child_name):
        self._last_child[self.current_dir] = child_name
        new_path = os.path.join(self.current_dir, child_name)
        self.change_dir(new_path)

    def _clear_placeholder(self, event):
        if self.search_var.get() == self.PLACEHOLDER:
            self.search_entry.delete(0, 'end')
            self.search_entry.config(bootstyle='')

    def _add_placeholder(self, event):
        if not self.search_var.get().strip():
            self.search_entry.delete(0, 'end')
            self.search_entry.insert(0, self.PLACEHOLDER)
            self.search_entry.config(bootstyle='secondary')

    def _restore_selection(self):
        last_child = self._last_child.get(self.current_dir)
        if not last_child: return
        
        for iid in self.tree.get_children():
            if self.tree.set(iid, "name").strip() == last_child:
                self.tree.selection_set(iid)
                self.tree.focus(iid)
                self.tree.see(iid)
                break
    

# Settings 팝업
class SettingsDialog(tb.Toplevel):
    def __init__(self, parent, cfg: dict, theme_names: list[str], callback):
        super().__init__(parent)
        self.title("Preferences")
        self.resizable(False, False)
        self.grab_set()
        self.callback = callback
        self.cfg_copy = cfg.copy()

        ttk.Label(self, text="Theme:", font="BaseFont").grid(row=0, column=0, sticky='e', padx=6, pady=6)
        self.theme_var = tb.StringVar(value=cfg['theme'])
        ttk.Combobox(self, textvariable=self.theme_var, values=theme_names, state='readonly', width=18).grid(row=0, column=1, padx=6, pady=6)

        ttk.Label(self, text="Base font size:", font="BaseFont").grid(row=1, column=0, sticky='e', padx=6, pady=6)
        self.font_var = tb.IntVar(value=cfg['font_size'])
        ttk.Spinbox(self, from_=8, to=24, textvariable=self.font_var, width=6).grid(row=1, column=1, sticky='w', padx=6, pady=6)

        ttk.Label(self, text="Timeout (sec):", font="BaseFont").grid(row=2, column=0, sticky='e', padx=6, pady=6)
        self.to_var = tb.IntVar(value=cfg['timeout'])
        ttk.Spinbox(self, from_=1, to=60, textvariable=self.to_var, width=6).grid(row=2, column=1, sticky='w', padx=6, pady=6)

        familes = sorted(tkfont.families())

        ttk.Label(self, text="Base font:", font="BaseFont").grid(row=3, column=0, sticky='e', padx=6, pady=6)
        self.base_var = tb.StringVar(value=cfg['base_font'])
        ttk.Combobox(self, textvariable=self.base_var, values=familes, state='readonly', width=22).grid(row=3, column=1, padx=6, pady=6)

        ttk.Label(self, text="Mono font:", font="BaseFont").grid(row=4, column=0, sticky='e', padx=6, pady=6)
        self.mono_var = tb.StringVar(value=cfg['mono_font'])
        ttk.Combobox(self, textvariable=self.mono_var, values=familes, state='readonly', width=22).grid(row=4, column=1, padx=6, pady=6)

        ttk.Label(self, text="Memory Limit (MB):", font="BaseFont").grid(row=5, column=0, sticky='e', padx=6, pady=6)
        self.mem_var = tb.IntVar(value=cfg.get('mem_limit_mb', 0))
        ttk.Spinbox(self, from_=0, to=10240, textvariable=self.mem_var, width=6).grid(row=5, column=1, sticky='w', padx=6, pady=6)



        btn_fr = ttk.Frame(self); btn_fr.grid(columnspan=2, pady=8)
        ttk.Button(btn_fr, text="Cancel", command=self.destroy, bootstyle='secondary').pack(side='right', padx=4)
        ttk.Button(btn_fr, text="OK", command=self._ok, bootstyle='primary').pack(side='right')

        self.columnconfigure(1, weight=1)
        self.bind('<Return>', lambda *_: self._ok())

    def _ok(self):
        self.cfg_copy.update({
            'theme' : self.theme_var.get(),
            'font_size' : self.font_var.get(),
            'timeout' : self.to_var.get(),
            'base_font' : self.base_var.get(),
            'mono_font' : self.mono_var.get(),
            'mem_limit_mb': self.mem_var.get()
        })
        self.callback(self.cfg_copy)
        self.destroy()

class PluginBase:
    def on_start(self, proc: psutil.Process):
        pass

    def on_sample(self):
        pass

    def on_finish(self) -> dict:
        return {}
    
class MemoryLimitPlugin(PluginBase):
    def __init__(self, limit_bytes: int, parent_window):
        self.limit = limit_bytes
        self.parent = parent_window
        self.peak_rss_sampled_bytes = 0
        self.peak_vmhwm_bytes = 0
        self.proc: Optional[psutil.Process] = None
        self.is_linux = (os.name == 'posix')

    def _get_vmhwm(self, pid: int) -> Optional[int]:
        if not self.is_linux:
            return None
        try:
            with open(f"/proc/{pid}/status", 'r') as f:
                for line in f:
                    if line.startswith("VmHWM:"):
                        match = re.search(r'(\d+)\s*kB', line)
                        if match:
                            return int(match.group(1)) * 1024
            return None
        except (FileNotFoundError, IOError, ValueError, AttributeError):
            return None

    def on_start(self, proc: psutil.Process):
        self.proc = proc
        self.peak_rss_sampled_bytes = 0
        self.peak_vmhwm_bytes = 0
        try:
            rss_now = self.proc.memory_info().rss
            self.peak_rss_sampled_bytes = rss_now

            vmhwm_now = self._get_vmhwm(self.proc.pid)
            if vmhwm_now is not None:
                self.peak_vmhwm_bytes = vmhwm_now
        except psutil.Error:
            pass

    def on_sample(self):
        if not self.proc or not self.proc.is_running():
            return
        
        current_peak_for_limit_check = 0
        peak_metric_name = "Peak RSS (sampled)"

        try:
            rss_now = self.proc.memory_info().rss
            if rss_now > self.peak_rss_sampled_bytes:
                self.peak_rss_sampled_bytes = rss_now
            
            current_peak_for_limit_check = self.peak_rss_sampled_bytes

            vmhwm_now = self._get_vmhwm(self.proc.pid)
            if vmhwm_now is not None:
                self.peak_vmhwm_bytes = max(self.peak_vmhwm_bytes, vmhwm_now)
                current_peak_for_limit_check = self.peak_vmhwm_bytes
                peak_metric_name = "VmHWM"

            if self.limit > 0 and current_peak_for_limit_check > self.limit:
                self.proc.kill()
                ToastNotification(
                    title="Memory Limit Exceeded",
                    message=(
                        f"{peak_metric_name} {current_peak_for_limit_check / (1024**2):.2f} MB > "
                        f"Limit {self.limit / (1024**2):.2f} MB"
                    ),
                    duration=3000,
                    alert=True,
                    bootstyle='danger'
                ).show_toast()
        except psutil.Error:
            self.proc = None
        except Exception:
            pass

    def on_finish(self):
        if self.proc and self.proc.is_running():
            try:
                rss_final = self.proc.memory_info().rss
                if rss_final > self.peak_rss_sampled_bytes:
                    self.peak_rss_sampled_bytes = rss_final
                vmhwm_final = self._get_vmhwm(self.proc.pid)
                if vmhwm_final is not None and vmhwm_final > self.peak_vmhwm_bytes:
                    self.peak_vmhwm_bytes = vmhwm_final
            except psutil.Error:
                pass

        results = {
            "Peak RSS": f"{self.peak_rss_sampled_bytes / (1024 ** 2):.2f} MB"
        }
        if self.is_linux and self.peak_vmhwm_bytes > 0:
            results["Peak VmHWM"] = f"{self.peak_vmhwm_bytes / (1024 ** 2):.2f} MB"
        
        return results
    

class CpuUsagePlugin(PluginBase):
    """CPU 평균/최대 사용률 측정"""
    def __init__(self):
        self.proc = None
        self.max_pct = 0.0
        self.start_cpu_time = 0.0
        self.start_wall = 0.0

    def on_start(self, proc: psutil.Process):
        self.proc = proc
        try:
            times = proc.cpu_times()
            self.start_cpu_time = times.user + times.system
            self.start_wall = time.time()
            proc.cpu_percent(interval=None)
        except psutil.Error:
            self.proc = None

    def on_sample(self):
        if not self.proc or not self.proc.is_running():
            return
        try:
            pct = self.proc.cpu_percent(interval=None)
            if pct > self.max_pct:
                self.max_pct = pct
        except psutil.Error:
            pass

    def on_finish(self):
        if not self.proc:
            return {}
        end_wall = time.time()
        elapsed = end_wall - self.start_wall
        try:
            times = self.proc.cpu_times()
            total_cpu = (times.user + times.system) - self.start_cpu_time
            avg_pct = (total_cpu / elapsed * 100) if elapsed > 0 else 0.0
        except psutil.Error:
            avg_pct = 0.0
            
        return {
            "CPU Avg": f"{avg_pct:.1f}%",
            "CPU Max": f"{self.max_pct:.1f}%"
        }

# ─── GUI 클래스 (리디자인) ─────────────────────────────────────────
class App(tb.Window):
    def __init__(self):
        # --- 기본 설정 및 초기화 ---
        self.app_cfg = {'theme':'darkly', 'font_size':11, 'timeout':10, 
                        'base_font':'Apple SD Gothic Neo', 'mono_font':'SF Mono', 
                        'mem_limit_mb': 0}
        
        super().__init__(themename=self.app_cfg['theme'], title='MultiRunMem GUI',
                         size=(1000, 850), minsize=(700, 550))

        self._setup_fonts()
        self._setup_icons()
        self._setup_style()
        
        # --- 변수 선언 ---
        self.src_var = tb.StringVar()
        self.in_var = tb.StringVar()
        self.expected_var = tb.StringVar()
        self.last_dir = os.getcwd()
        self._current_proc = None
        self._file_dialog = None

        # --- UI 구성 ---
        self._setup_menubar()
        self._setup_layout() # 이제 이 함수가 모든 것을 처리합니다.
        self._setup_bindings()
        
        self.status.config(text='Ready')

    # ... (_setup_fonts, _setup_icons, _setup_style, _setup_menubar 메서드는 이전과 동일) ...
    def _setup_fonts(self):
        # 시스템 기본 폰트가 없을 경우 대비
        default_base = 'Segoe UI' if os.name == 'nt' else 'SF Pro' if sys.platform == 'darwin' else 'Noto Sans'
        default_mono = 'Consolas' if os.name == 'nt' else 'SF Mono' if sys.platform == 'darwin' else 'Noto Sans Mono'
        
        self.app_cfg['base_font'] = self.app_cfg.get('base_font', default_base)
        self.app_cfg['mono_font'] = self.app_cfg.get('mono_font', default_mono)

        self.base_font = tkfont.Font(name='BaseFont', family=self.app_cfg['base_font'], size=self.app_cfg['font_size'])
        self.code_font = tkfont.Font(name='CodeFont', family=self.app_cfg['mono_font'], size=self.app_cfg['font_size']-1)
        
        # ttkbootstrap 기본 폰트 재정의
        tkfont.nametofont('TkDefaultFont').config(family=self.app_cfg['base_font'], size=self.app_cfg['font_size'])
        tkfont.nametofont('TkTextFont').config(family=self.app_cfg['base_font'], size=self.app_cfg['font_size'])
        tkfont.nametofont('TkFixedFont').config(family=self.app_cfg['mono_font'], size=self.app_cfg['font_size']-1)

    def _setup_icons(self):
        # 아이콘 파일이 없을 경우를 대비한 예외 처리
        try:
            assets = pathlib.Path(__file__).parent / 'MultiMemGUI_icon'
            self._icon_dark  = tk.PhotoImage(file=str(assets/'dark-icon.png'))
            self._icon_light = tk.PhotoImage(file=str(assets/'light-icon.png'))
            self.iconphoto(True, self._icon_dark if 'dark' in self.app_cfg['theme'] else self._icon_light)
        except tk.TclError:
            print("Warning: Icon files not found. Skipping icon setup.")
            self._icon_dark = self._icon_light = None

    def _setup_style(self):
        style = tb.Style.get_instance()
        # Notebook 탭 높이 조정
        style.configure('TNotebook.Tab', padding=[10, 4], font='BaseFont')
        # Labelframe 제목 폰트 조정
        style.configure('TLabelframe.Label', font=self.base_font)

    def _setup_menubar(self):
        menubar = tb.Menu(self)
        self.config(menu=menubar)

        file_m = tb.Menu(menubar, tearoff=0)
        file_m.add_command(label='Open Source...', accelerator='Ctrl+O', command=lambda: self._pick_file(self.src_var, "Choose source file", [('Source', '*.c *.cpp *.java *.py'), ('All', '*.*')]))
        file_m.add_command(label='Open Input...', accelerator='Ctrl+I', command=lambda: self._pick_file(self.in_var, "Choose input file"))
        file_m.add_command(label='Open Expected Out...', command=lambda: self._pick_file(self.expected_var, "Choose expected output file"))
        file_m.add_separator()
        file_m.add_command(label='Exit', accelerator='Ctrl+Q', command=self.quit)
        menubar.add_cascade(label='File', menu=file_m)

        set_m = tb.Menu(menubar, tearoff=0)
        set_m.add_command(label='Preferences...', command=self.open_settings)
        menubar.add_cascade(label='Settings', menu=set_m)
        
        help_m = tb.Menu(menubar, tearoff=0)
        help_m.add_command(label='About', command=lambda:msgbox.showinfo('About', 'MultiRunMem GUI\nⓒ 2024. All rights reserved.'))
        menubar.add_cascade(label='Help', menu=help_m)

    def _setup_layout(self):
        # --- 메인 PanedWindow (상하 분할) ---
        main_pane_v = ttk.PanedWindow(self, orient='vertical')
        main_pane_v.pack(fill='both', expand=True, padx=10, pady=(5,0))

        # --- 1. 상단 패널 ---
        config_frame = ttk.Frame(main_pane_v)
        main_pane_v.add(config_frame, weight=1)

        # 상단 패널을 다시 좌우로 분할
        main_pane_h = ttk.PanedWindow(config_frame, orient='horizontal')
        main_pane_h.pack(fill='both', expand=True)

        # 1a. 왼쪽 패널 (파일 선택, 수동 입력)
        left_pane = ttk.Frame(main_pane_h, padding=5)
        main_pane_h.add(left_pane, weight=3)

        file_selection_lf = ttk.Labelframe(left_pane, text="File Selection", padding=(10, 5))
        file_selection_lf.pack(fill='x', pady=(0, 5))
        self._create_file_selection_widgets(file_selection_lf)
        
        stdin_lf = ttk.Labelframe(left_pane, text="Manual Stdin (if no input file)", padding=(10, 5))
        stdin_lf.pack(fill='both', expand=True)
        self._create_stdin_widgets(stdin_lf)

        # 1b. 오른쪽 패널 (실행 버튼)
        right_pane = ttk.Frame(main_pane_h, padding=5)
        main_pane_h.add(right_pane, weight=1)
        
        action_lf = ttk.Labelframe(right_pane, text="Actions", padding=(10, 5))
        action_lf.pack(fill='both', expand=True)
        self._create_action_buttons(action_lf)

        # --- 2. 하단 패널 (결과) ---
        results_frame = ttk.Frame(main_pane_v)
        main_pane_v.add(results_frame, weight=2)
        self._setup_results_ui(results_frame)
        
        # --- 3. 상태바 ---
        self._setup_statusbar()

    def _create_file_selection_widgets(self, parent):
        parent.columnconfigure(1, weight=1)
        ttk.Label(parent, text='Source:').grid(row=0, column=0, sticky='w', padx=5, pady=3)
        ttk.Entry(parent, textvariable=self.src_var).grid(row=0, column=1, sticky='ew', padx=5, pady=3)
        ttk.Button(parent, text='...', width=3, bootstyle='secondary', command=lambda: self._pick_file(self.src_var, "Choose source file", [('Source', '*.c *.cpp *.java *.py'), ('All', '*.*')])).grid(row=0, column=2, padx=(0,5), pady=3)
        
        ttk.Label(parent, text='Input:').grid(row=1, column=0, sticky='w', padx=5, pady=3)
        ttk.Entry(parent, textvariable=self.in_var).grid(row=1, column=1, sticky='ew', padx=5, pady=3)
        ttk.Button(parent, text='...', width=3, bootstyle='secondary', command=lambda: self._pick_file(self.in_var, "Choose input file")).grid(row=1, column=2, padx=(0,5), pady=3)
        
        ttk.Label(parent, text='Expected:').grid(row=2, column=0, sticky='w', padx=5, pady=3)
        ttk.Entry(parent, textvariable=self.expected_var).grid(row=2, column=1, sticky='ew', padx=5, pady=3)
        ttk.Button(parent, text='...', width=3, bootstyle='secondary', command=lambda: self._pick_file(self.expected_var, "Choose expected output file")).grid(row=2, column=2, padx=(0,5), pady=3)

    def _create_stdin_widgets(self, parent):
        self.stdin_box = ScrolledText(parent, height=5, font='CodeFont', wrap='word')
        self.stdin_box.pack(fill='both', expand=True)

    def _create_action_buttons(self, parent):
        self.run_btn = ttk.Button(parent, text='▶ RUN', bootstyle='success', command=self.run_clicked)
        self.run_btn.pack(side='top', fill='x', pady=5, ipady=5)
        
        self.clear_btn = ttk.Button(parent, text='Clear Stdin', bootstyle='secondary-outline', command=self.clean_clicked)
        self.clear_btn.pack(side='top', fill='x', pady=5)
        
        self.analyze_btn = ttk.Button(parent, text='Analyze Code', bootstyle='info-outline', command=self.analysis_clicked)
        self.analyze_btn.pack(side='top', fill='x', pady=5)
    
    def _setup_bindings(self):
        self.bind_all('<Control-o>', lambda e: self._pick_file(self.src_var, "Choose source file", [('Source', '*.c *.cpp *.java *.py'), ('All', '*.*')]))
        self.bind_all('<Control-i>', lambda e: self._pick_file(self.in_var, "Choose input file"))
        self.bind_all('<Control-r>', lambda e: self.run_clicked())
        self.bind_all('<Control-q>', lambda e: self.quit())

    # ... (나머지 모든 메서드는 이전과 동일하게 유지) ...
    def _setup_results_ui(self, parent):
        self.nb = ttk.Notebook(parent)
        self.nb.pack(fill='both', expand=True, pady=(3,0))

        self.out_box = self._create_scrolled_text_tab('Output', 'primary')
        self.err_box = self._create_scrolled_text_tab('Error', 'danger')
        self.compare_box = self._create_scrolled_text_tab('Compare', 'warning')
        self.log_box = self._create_scrolled_text_tab('Log', 'info')

    def _create_scrolled_text_tab(self, title: str, bootstyle: str) -> ScrolledText:
        frame = ttk.Frame(self.nb, padding=0)
        box = ScrolledText(frame, font='CodeFont', wrap='none', bootstyle=bootstyle)
        box.pack(fill='both', expand=True)
        self.nb.add(frame, text=title)
        return box

    def _setup_statusbar(self):
        status_frame = ttk.Frame(self, padding=(5, 2))
        status_frame.pack(side='bottom', fill='x')
        
        self.status = ttk.Label(status_frame, text='Initializing...', anchor='w')
        self.status.pack(side='left', fill='x', expand=True, padx=5)
        
        self.progressbar = ttk.Progressbar(status_frame, mode='indeterminate', length=150)
        self.progressbar.pack(side='right', padx=5)

    def _pick_file(self, target_var: tb.StringVar, title: str, filetypes: Optional[list] = None):
        """파일 선택 다이얼로그를 열고 결과를 변수에 저장하는 헬퍼 함수"""
        filetypes = filetypes or [('All files', '*.*')]
        
        def on_file_selected(path):
            if path:
                target_var.set(path)
                self.last_dir = os.path.dirname(path)
            self._file_dialog = None

        # 다이얼로그가 이미 열려있으면 새로 열지 않음
        if self._file_dialog and self._file_dialog.winfo_exists():
            self._file_dialog.lift()
            return

        self._file_dialog = CustomFileDialog(
            self,
            title=title,
            initialdir=self.last_dir,
            filetypes=filetypes,
            callback=on_file_selected
        )

    def open_settings(self):
        SettingsDialog(self, self.app_cfg.copy(),
                       theme_names=tb.Style().theme_names(),
                       callback=self.apply_settings)

    def apply_settings(self, new_cfg: dict):
        """SettingsDialog에서 OK를 눌렀을 때 호출됨"""
        if new_cfg['theme'] != self.app_cfg['theme']:
            tb.Style().theme_use(new_cfg['theme'])
            if self._icon_dark and self._icon_light:
                self.iconphoto(True, self._icon_dark if 'dark' in new_cfg['theme'] else self._icon_light)

        self.app_cfg.update(new_cfg)
        self._setup_fonts() # 폰트 설정을 다시 적용
        self._log('Settings updated.')

    def run_clicked(self):
        src = self.src_var.get().strip()
        if not src:
            msgbox.showwarning('Warning', '소스 파일을 선택하세요', parent=self)
            return

        stdin_data = (open(self.in_var.get(), 'r', encoding='utf-8').read()
                      if self.in_var.get() and os.path.exists(self.in_var.get())
                      else self.stdin_box.get('1.0', 'end-1c'))

        self._set_busy(True)
        self._clear_io()
        self._log('Execution started...')

        threading.Thread(target=self._worker,
                         args=(src, stdin_data),
                         daemon=True).start()

    def _worker(self, src, stdin_data):
        try:
            self._log(f'Compiling {os.path.basename(src)}...')
            lang, exe, cwd = compile_source(src)
            self._log(f'Compile successful ({lang}). Executable: {exe}')
            
            cmd = {'c': [exe], 'cpp': [exe],
                   'java': ['java', '-cp', os.path.dirname(exe), os.path.basename(exe)],
                   'python': [sys.executable, exe]}[lang]
            
            self._log(f"Running command: {' '.join(shlex.quote(c) for c in cmd)}")
            
            plugins = [
                MemoryLimitPlugin(self.app_cfg['mem_limit_mb'] * 1024**2, self),
                CpuUsagePlugin(),
            ]

            code, out, err, elapsed, metrics = run_with_memory(
                cmd, stdin_data, cwd=cwd, 
                timeout=self.app_cfg['timeout'],
                plugins=plugins
            )
            
            self.after(0, self._done, code, out, err, elapsed, metrics)

        except Exception as e:
            self.after(0, self._error, e)

    def _set_busy(self, is_busy: bool):
        self.run_btn['state'] = 'disabled' if is_busy else 'normal'
        if is_busy:
            self.status.config(text='Running...')
            self.progressbar.start()
        else:
            self.progressbar.stop()
            # 상태 텍스트는 _done이나 _error에서 설정하므로 여기서는 초기화하지 않음

    def _clear_io(self):
        for box in (self.out_box, self.err_box, self.log_box, self.compare_box):
            box.delete('1.0', 'end')

    def _log(self, msg: str):
        timestamp = datetime.datetime.now().strftime('%H:%M:%S')
        self.log_box.insert('end', f'[{timestamp}] {msg}\n')
        self.log_box.see('end')

    def _error(self, err: Exception):
        self._set_busy(False)
        msg = str(err)
        self.err_box.delete('1.0', 'end') # Clear previous error
        self.err_box.insert('end', msg + '\n')
        self.err_box.see('end')
        self.status.config(text='Execution failed!')
        self._log(f'Error: {msg}')
        # [수정] ScrolledText 위젯 대신 그것을 담고 있는 부모 Frame을 선택합니다.
        self.nb.select(self.err_box.master)

    def _done(self, code, out, err, elapsed, metrics: dict):
        self._set_busy(False)
        self.out_box.insert('end', out)
        self.err_box.insert('end', err)

        status_parts = [f"Exit: {code}"]
        status_parts.extend(f"{k}: {v}" for k, v in metrics.items())
        status_parts.append(f"Time: {elapsed * 1000:.2f} ms")
        
        final_status = ' | '.join(status_parts)
        self.status.config(text=final_status)
        self._log(f'Execution finished. Status: {final_status}')
        
        if code != 0:
            # [수정] ScrolledText 위젯 대신 그것을 담고 있는 부모 Frame을 선택합니다.
            self.nb.select(self.err_box.master)
        else:
            # [수정] ScrolledText 위젯 대신 그것을 담고 있는 부모 Frame을-을 선택합니다.
            self.nb.select(self.out_box.master)

        self.after(100, self.compare_output)

    def clean_clicked(self):
        self.stdin_box.delete('1.0', tk.END)

    def analysis_clicked(self):
        src_path = self.src_var.get().strip()

        if not src_path or not os.path.isfile(src_path):
            msgbox.showerror("경로 오류", "분석할 소스 코드 파일 경로가 잘못되었습니다.", parent=self)
            return
        
        if importlib.util.find_spec("lizard") is None:
            if not msgbox.askyesno("lizard 미설치",
                                   "lizard 파이썬 패키지가 설치돼 있지 않습니다.\n"
                                   "지금 바로 설치하시겠습니까?",
                                   parent=self):
                return
            try:
                subprocess.check_call([sys.executable, "-m", "pip", "install", "--user", "lizard"])
            except subprocess.CalledProcessError as e:
                msgbox.showerror("설치 실패", f"lizard 설치 중 오류가 발생했습니다:\n{e}", parent=self)
                return
            
        tmp_html = tempfile.NamedTemporaryFile(suffix=".html", delete=False, mode='w', encoding='utf-8')
        tmp_html_path = tmp_html.name
        
        try:
            lizard_cmd = shutil.which("lizard")
            cmd = [lizard_cmd or sys.executable, "-m", "lizard"] if not lizard_cmd else [lizard_cmd]
            cmd.extend(["--html", src_path])

            proc = subprocess.run(cmd, stdout=tmp_html, stderr=subprocess.PIPE, text=True, encoding='utf-8')
            tmp_html.close()

            if proc.returncode != 0:
                msgbox.showerror("분석 실패", f"lizard 실행 중 오류가 발생했습니다:\n{proc.stderr}", parent=self)
                os.unlink(tmp_html_path)
                return
            
            webbrowser.open_new_tab(pathlib.Path(tmp_html_path).as_uri())
            msgbox.showinfo("완료", "코드 분석 결과가 브라우저 새 탭으로 열렸습니다!", parent=self)

        except Exception as e:
            msgbox.showerror("실행 실패", f"lizard 실행 중 예외가 발생했습니다: {e}", parent=self)
            if os.path.exists(tmp_html_path):
                os.unlink(tmp_html_path)
    
    _token_pat = re.compile(r'\{([^{}]+?)\}')

    @staticmethod
    def _line_to_regex(exp_line:str)->re.Pattern:
        if exp_line.startswith('re:'):
            pat = exp_line[3:]
            return re.compile(pat)
        parts, pos = [], 0
        for m in App._token_pat.finditer(exp_line):
            parts.append(re.escape(exp_line[pos:m.start()]))
            alts = [re.escape(s) for s in m.group(1).split('|')]
            parts.append('(?:' + '|'.join(alts) + ')')
            pos = m.end()
        parts.append(re.escape(exp_line[pos:]))

        return re.compile('^' + ''.join(parts) + '$')
    
    @staticmethod
    def _normalize(line:str)->str:
        return re.sub(r'\s+', ' ', line.rstrip())

    def compare_output(self):
        expected_path = self.expected_var.get().strip()
        if not expected_path or not os.path.isfile(expected_path):
            self.compare_box.delete('1.0', 'end')
            self.compare_box.insert('end', '[비교 건너뜀] 기대 출력 파일이 지정되지 않았습니다.')
            return
        
        self.compare_box.delete('1.0', 'end')
        self._log("Comparing output with expected file...")

        try:
            with open(expected_path, 'r', encoding='utf-8') as f:
                expected = [ln.rstrip('\n\r') for ln in f.readlines()]
        except Exception as e:
            self._fail(0, f"기대 출력 파일 읽기 오류: {e}", [], [])
            return
        
        actual = [ln.rstrip('\n\r') for ln in self.out_box.get('1.0', 'end-1c').splitlines()]

        for idx, (e_line, a_line) in enumerate(zip_longest(expected, actual, fillvalue=None), start=1):
            if e_line is None:
                self._fail(idx, '실제 출력이 기대 출력보다 깁니다.', expected, actual); return
            if a_line is None:
                self._fail(idx, '실제 출력이 기대 출력보다 짧습니다.', expected, actual); return
            
            normalized_e = self._normalize(e_line)
            normalized_a = self._normalize(a_line)
            
            try:
                pattern = self._line_to_regex(normalized_e)
                if not pattern.fullmatch(normalized_a):
                    self._fail(idx, f'내용 불일치', expected, actual)
                    if msgbox.askyesno("테스트 실패", "기대 출력과 실제 출력이 다릅니다.\n소스 코드를 클립보드에 복사하시겠습니까?", parent=self):
                        self._copy_source_to_clipboard()
                    return
            except re.error as re_err:
                self._fail(idx, f"기대 출력의 정규식 패턴 오류: {re_err}", expected, actual)
                return

        result = '✅ PASS: 실제 출력이 기대 출력과 일치합니다.\n'
        self.compare_box.insert('end', result)
        self._log("Comparison result: PASS")
        if msgbox.askyesno("테스트 성공", "소스 코드를 클립보드에 복사하시겠습니까?", parent=self):
            self._copy_source_to_clipboard()
    
    def _fail(self, line_num:int, why:str, exp:list[str], act:list[str]):
        diff = unified_diff(exp, act, fromfile='Expected', tofile='Actual', lineterm='')
        msg = f'❌ FAIL (at line {line_num}): {why}\n\n' + '\n'.join(diff)
        self.compare_box.delete('1.0', 'end')
        self.compare_box.insert('end', msg)
        # [수정] ScrolledText 위젯 대신 그것을 담고 있는 부모 Frame을 선택합니다.
        self.nb.select(self.compare_box.master)
        self._log(f"Comparison result: FAIL - {why}")

    def _copy_source_to_clipboard(self):
        src_path = self.src_var.get()
        try:
            with open(src_path, 'r', encoding='utf-8') as f:
                content = f.read()
            pyperclip.copy(content)
            # CustomToast 또는 해결된 ToastNotification 사용
            CustomToast("Copied", "Source code copied to clipboard.", duration=2000, bootstyle='success')
        except Exception as e:
            msgbox.showerror("Error", f"Failed to read and copy source file:\n{e}", parent=self)

class CustomToast(tb.Toplevel):
    def __init__(self, title, message, duration=3000, bootstyle='primary', parent=None):
        super().__init__(alpha=0.0, parent=parent)
        self.duration = duration
        self.overrideredirect(False)
        self.wm_attributes("-type", "splash")
        self.wm_title(title)

        main_frame = ttk.Frame(self,
                               bootstyle=bootstyle, padding=10)
        main_frame.pack(fill='both', expand=True)

        title_label = ttk.Label(main_frame, text=title, font="-weight bold", bootstyle=f'inverse-{bootstyle}')
        title_label.pack(anchor='nw', fill='x')

        message_label = ttk.Label(main_frame, text=message, bootstyle=f'inverse-{bootstyle}')
        message_label.pack(anchor='nw', pady=(5, 0), fill='x')
        self.update_idletasks()

        if parent:
            screen_width = parent.winfo_screenwidth()
            screen_height = parent.winfo_screenheight()
        else:
            screen_width = self.winfo_screenwidth()
            screen_height = self.winfo_screenheight()

        width = self.winfo_width()
        height = self.winfo_height()
        x = screen_width - width - 20
        y = screen_height - height - 50

        self.geometry(f'{width}x{height}+{x}+{y}')
        self.fade_in()
        self.after(self.duration, self.fade_out)

    def fade_in(self):
        alpha = self.attributes('-alpha')
        if alpha < 0.9:
            alpha += 0.08
            self.attributes('-alpha', alpha)
            self.after(15, self.fade_in)

    def fade_out(self):
        alpha = self.attributes('-alpha')
        if alpha > 0.0:
            alpha -= 0.08
            self.attributes('-alpha', alpha)
            self.after(15, self.fade_out)
        else:
            self.destroy()


# ─── 실행 ──────────────────────────────────────────────────────
if __name__ == '__main__':
    # DPI 인식 활성화 (Windows에서 선명한 폰트를 위해)
    if os.name == 'nt':
        try:
            from ctypes import windll
            windll.shcore.SetProcessDpiAwareness(1)
        except Exception:
            pass
    
    app = App()
    app.mainloop()