#!/usr/bin/env python3
# multi_run_mem_gui.py  –  ttkbootstrap(darkly) + 정확한 RSS + Java cwd fix

import os, sys, time, threading, subprocess, tempfile, platform, resource
import psutil                                       # pip install psutil
import shlex
import fnmatch
from functools import partial
import pathlib
# ─── GUI 라이브러리 ───────────────────────────────────────────────
import ttkbootstrap as tb                           # pip install ttkbootstrap
from ttkbootstrap import ttk
from ttkbootstrap.scrolled import ScrolledText
from tkinter import filedialog, messagebox
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
        cmd = ['gcc' if lang == 'c' else 'g++', src,
               '-O2', '-std=c17' if lang == 'c' else '-std=c++26',
               '-Wall', '-pipe', '-o', exe]
        res = subprocess.run(cmd, capture_output=True, text=True)
        if res.returncode != 0:
            raise RuntimeError(f"gcc/g++ compile error\n\n"
                               f"$ {' '.join(map(shlex.quote, cmd))}\n"
                               f"{res.stderr.strip()}")
        return lang, exe, workdir

    if lang == 'java':
        res = subprocess.run(['javac', src], capture_output=True, text=True)
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
                    cwd: str | None = None, timeout: int = 10):
    """
    returns (exit_code, stdout, stderr, peak_rss_bytes, elapsed_sec)
    """
    start = time.time()
    proc  = subprocess.Popen(cmd, cwd=cwd, text=True,
                             stdin=subprocess.PIPE,
                             stdout=subprocess.PIPE,
                             stderr=subprocess.PIPE)
    ps_proc = psutil.Process(proc.pid)

    peak = ps_proc.memory_info().rss                # 스폰 직후 1회 측정

    def monitor():
        nonlocal peak
        try:
            while proc.poll() is None:
                rss_total = ps_proc.memory_info().rss
                for ch in ps_proc.children(recursive=True):
                    rss_total += ch.memory_info().rss
                peak = max(peak, rss_total)
                time.sleep(0.015)                   # 15 ms 간격
        except psutil.Error:
            pass
    threading.Thread(target=monitor, daemon=True).start()

    try:
        out, err = proc.communicate(input=stdin_data, timeout=timeout)
    except subprocess.TimeoutExpired:
        proc.kill(); out, err = proc.communicate()

    elapsed = time.time() - start

    # 종료 직후 보정
    try:
        peak = max(peak, ps_proc.memory_info().rss)
    except psutil.Error:
        pass

    if platform.system() == 'Linux':
        ru = resource.getrusage(resource.RUSAGE_CHILDREN)
        peak = max(peak, ru.ru_maxrss * 1024)
        peak = max(peak, _linux_rss_fallback(proc.pid))

    return proc.returncode, out, err, peak, elapsed

class PathBar(ttk.Frame): # ttk.Frame을 사용 (ttkbootstrap의 Frame)
    def __init__(self, parent, path, callback, style="flatly"): # style 매개변수 추가 및 기본값 설정
        super().__init__(parent)
        self.callback = callback
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

        self.set_path(path)

    def _on_label_enter(self, event, label):
        label.configure(font=self.underline_font, cursor="hand2")

    def _on_label_leave(self, event, label):
        label.configure(font=self.base_font, cursor="")

    def _on_label_click(self, path_to_send, event):
        self.callback(path_to_send)

    def set_path(self, path):
        for widget in self.winfo_children():
            widget.destroy()

        if not path:
            return

        normalized_path = os.path.normpath(path)
        p = pathlib.Path(normalized_path)
        path_parts = p.parts

        if not path_parts:
            if normalized_path == ".":
                path_parts = (".",)
            else:
                return

        current_accumulated_path = ""
        for i, part_text in enumerate(path_parts):
            if i == 0:
                current_accumulated_path = part_text
            else:
                current_accumulated_path = os.path.join(current_accumulated_path, part_text)

            # ttk.Label은 from ttkbootstrap import ttk 때문에 ttkbootstrap.Label을 가리킴
            label_part = ttk.Label(
                self,
                text=part_text,
                font=self.base_font
            )
            # ttkbootstrap의 Label은 bootstyle 옵션을 가짐
            if hasattr(label_part, 'configure'): # configure_get() 사용 권장
                try:
                    label_part.configure(bootstyle=self.style_name)
                except tk.TclError: # 유효하지 않은 bootstyle 이름일 경우 대비
                    pass # 기본 스타일 유지

            label_part.pack(side="left", padx=1, pady=2)

            label_part.bind("<Button-1>", partial(self._on_label_click, current_accumulated_path))
            label_part.bind("<Enter>", partial(self._on_label_enter, label=label_part))
            label_part.bind("<Leave>", partial(self._on_label_leave, label=label_part))

            if i < len(path_parts) - 1:
                sep_text = ">"
                separator = ttk.Label(self, text=f" {sep_text} ", font=self.base_font)
                if hasattr(separator, 'configure'):
                    try:
                        separator.configure(bootstyle=self.style_name)
                    except tk.TclError:
                        pass
                separator.pack(side="left", padx=1, pady=2)

# File Picker 팝업
class CustomFileDialog(tb.Toplevel):
    def __init__(self, parent, title="Select File", initialdir=None, filetypes=None, callback=None):
        super().__init__(parent)
        self.title(title)
        self.resizable(True, True)
        self.grab_set()
        self.geometry("900x700")
        self.callback = callback
        self.filetypes = filetypes or [("All files", "*.*")]
        self.selected_file = None

        self.current_dir = os.path.abspath(initialdir or os.getcwd())

        self.history = [self.current_dir]
        self.history_index = 0
        self.search_var = tb.StringVar()

        toolbar = ttk.Frame(self)
        toolbar.pack(fill='x', padx=0, pady=0)

        self.prev_btn = ttk.Button(toolbar, text="◀", width=3, command=self.go_prev, style="darkly")
        self.prev_btn.grid(row=0, column=0, padx=2, pady=4, sticky='ns')
        self.next_btn = ttk.Button(toolbar, text="▶", width=3, command=self.go_next, style="darkly")
        self.next_btn.grid(row=0, column=1, padx=2, pady=4, sticky='ns')
        self.refresh_btn = ttk.Button(toolbar, text="⟳", width=3, command=self.refresh, style="darkly")
        self.refresh_btn.grid(row=0, column=2, padx=2, pady=4, sticky='ns')

        self.pathbar = PathBar(toolbar, self.current_dir, self.change_dir)
        self.pathbar.grid(row=0, column=3, sticky='ew', padx=(2,0), pady=2)

        search_entry = ttk.Entry(toolbar, textvariable=self.search_var, width=24)
        search_entry.grid(row=0, column=4, padx=8, pady=4, sticky='ns')
        search_entry.insert(0, "Search files..")
        search_entry.bind("<FocusIn>", lambda e: search_entry.delete(0, 'end'))
        search_entry.bind("<FocusOut>", lambda e: search_entry.insert(0, "Search files..") if not search_entry.get() else None)
        search_entry.bind("<KeyRelease>", lambda e: self.populate())

        toolbar.columnconfigure(3, weight=1)

        columns = ("name", "date", "type", "size")
        self.tree = ttk.Treeview(self, columns=columns, show="headings", height=20)
        self.tree.heading("name", text="Name")
        self.tree.heading("date", text="Date modified")
        self.tree.heading("type", text="Type")
        self.tree.heading("size", text="Size")
        self.tree.column("name", width=320)
        self.tree.column("date", width=160)
        self.tree.column("type", width=120)
        self.tree.column("size", width=80, anchor='e')
        self.tree.pack(fill='both', expand=True, padx=0, pady=0)

        self.tree.bind("<Double-1>", self.on_double_click)
        self.tree.bind("<<TreeviewSelect>>", self.on_select)

        self.status = ttk.Label(self, text="", anchor='w')
        self.status.pack(side='bottom', fill='x', padx=8, pady=2)

        btn_frame = ttk.Frame(self)
        btn_frame.pack(fill='x', pady=4)
        ttk.Button(btn_frame, text="Cancel", command=self.destroy, style="darkly").pack(side='right', padx=4)
        ttk.Button(btn_frame, text="OK", command=self.on_ok, style="darkly").pack(side='right')

        self.populate()
        self.update_nav_buttons()

    def populate(self):
        self.tree.delete(*self.tree.get_children())
        search = self.search_var.get().strip().lower()
        try:
            entries = os.listdir(self.current_dir)
        except Exception:
            entries = []
        dirs, files = [], []
        for name in entries:
            path = os.path.join(self.current_dir, name)
            if os.path.isdir(path):
                dirs.append(name)
            elif self._match_filetypes(name):
                files.append(name)
            elif search and search not in name.lower():
                continue
        total_size = 0
        for d in sorted(dirs):
            dt = self._format_time(os.path.getmtime(os.path.join(self.current_dir, d)))
            self.tree.insert("", "end", values=(d, dt, "Directory", ""))
        for f in sorted(files):
            fpath = os.path.join(self.current_dir, f)
            size = os.path.getsize(fpath)
            total_size += size
            dt = self._format_time(os.path.getmtime(fpath))
            ext = os.path.splitext(f)[1].lower()
            typ = self._file_type(ext)
            self.tree.insert("", "end", values=(f, dt, typ, self._format_size(size)))
        self.status['text'] = f"{len(dirs)+len(files)} items | {self._format_size(total_size)} Total"

    def _file_type(self, ext):
        if ext in (".md",):
            return "MD file"
        elif ext in (".py", ".c", ".cpp", ".java"):
            return "Source file"
        elif ext:
            return f"{ext[1:].upper()} file"
        else:
            return "Unknown file"

    def _format_time(self, t):
        return time.strftime("%Y-%m-%d %H:%M", time.localtime(t))

    def _match_filetypes(self, filename):
        for desc, patterns in self.filetypes:
            for pat in patterns.split():
                if fnmatch.fnmatch(filename, pat):
                    return True
        return False

    def _format_size(self, size):
        for unit in ['B','KB','MB','GB']:
            if size < 1024.0:
                return f"{size:.0f} {unit}"
            size /= 1024.0
        return f"{size:.0f} TB"

    def on_double_click(self, event):
        item = self.tree.selection()
        if not item:
            return
        name = self.tree.item(item[0], "values")[0]
        path = os.path.join(self.current_dir, name)
        if os.path.isdir(path):
            self.change_dir(path)
        else:
            self.selected_file = path
            self.on_ok()

    def on_select(self, event):
        item = self.tree.selection()
        if not item:
            self.selected_file = None
            return
        name = self.tree.item(item[0], "values")[0]
        path = os.path.join(self.current_dir, name)
        if os.path.isfile(path):
            self.selected_file = path
        else:
            self.selected_file = None

    def on_ok(self):
        if self.selected_file and os.path.isfile(self.selected_file):
            if self.callback:
                self.callback(self.selected_file)
            self.destroy()
        else:
            tb.messagebox.showwarning("No file selected", "Please select a file.")

    def change_dir(self, new_dir):
        new_dir = os.path.abspath(new_dir)
        if new_dir != self.current_dir:
            if self.history_index < len(self.history) - 1:
                self.history = self.history[:self.history_index+1]
            self.history.append(new_dir)
            self.history_index += 1
            self.current_dir = new_dir
            self.pathbar.set_path(self.current_dir)  # PathBar 갱신
            self.populate()
            self.update_nav_buttons()

    def go_prev(self):
        if self.history_index > 0:
            self.history_index -= 1
            self.current_dir = self.history[self.history_index]
            self.pathbar.set_path(self.current_dir)
            self.populate()
            self.update_nav_buttons()

    def go_next(self):
        if self.history_index < len(self.history) - 1:
            self.history_index += 1
            self.current_dir = self.history[self.history_index]
            self.pathbar.set_path(self.current_dir)
            self.populate()
            self.update_nav_buttons()

    def refresh(self):
        self.populate()

    def update_nav_buttons(self):
        self.prev_btn['state'] = 'normal' if self.history_index > 0 else 'disabled'
        self.next_btn['state'] = 'normal' if self.history_index < len(self.history) - 1 else 'disabled'
    

# Settings 팝업
class SettingsDialog(tb.Toplevel):
    def __init__(self, parent, cfg: dict, theme_names: list[str], callback):
        super().__init__(parent)
        self.title("Preferences")
        self.resizable(False, False)
        self.grab_set()
        self.callback = callback
        self.cfg_copy = cfg.copy()

        ttk.Label(self, text="Theme:").grid(row=0, column=0, sticky='e', padx=6, pady=6)
        self.theme_var = tb.StringVar(value=cfg['theme'])
        ttk.Combobox(self, textvariable=self.theme_var, values=theme_names, state='readonly', width=18).grid(row=0, column=1, padx=6, pady=6)

        ttk.Label(self, text="Base font size:").grid(row=1, column=0, sticky='e', padx=6, pady=6)
        self.font_var = tb.IntVar(value=cfg['font_size'])
        ttk.Spinbox(self, from_=8, to=24, textvariable=self.font_var, width=6).grid(row=1, column=1, sticky='w', padx=6, pady=6)

        ttk.Label(self, text="Timeout (sec):").grid(row=2, column=0, sticky='e', padx=6, pady=6)
        self.to_var = tb.IntVar(value=cfg['timeout'])
        ttk.Spinbox(self, from_=1, to=60, textvariable=self.to_var, width=6).grid(row=2, column=1, sticky='w', padx=6, pady=6)

        familes = sorted(tkfont.families())

        ttk.Label(self, text="Base font:").grid(row=3, column=0, sticky='e', padx=6, pady=6)
        self.base_var = tb.StringVar(value=cfg['base_font'])
        ttk.Combobox(self, textvariable=self.base_var, values=familes, state='readonly', width=22).grid(row=3, column=1, padx=6, pady=6)

        ttk.Label(self, text="Mono font:").grid(row=4, column=0, sticky='e', padx=6, pady=6)
        self.mono_var = tb.StringVar(value=cfg['mono_font'])
        ttk.Combobox(self, textvariable=self.mono_var, values=familes, state='readonly', width=22).grid(row=4, column=1, padx=6, pady=6)



        btn_fr = ttk.Frame(self); btn_fr.grid(columnspan=2, pady=8)
        ttk.Button(btn_fr, text="Cancel", command=self.destroy, style="darkly").pack(side='right', padx=4)
        ttk.Button(btn_fr, text="OK", command=self._ok, style="darkly").pack(side='right')

        self.columnconfigure(1, weight=1)
        self.bind('<Return>', lambda *_: self._ok())

    def _ok(self):
        self.cfg_copy.update({
            'theme' : self.theme_var.get(),
            'font_size' : self.font_var.get(),
            'timeout' : self.to_var.get(),
            'base_font' : self.base_var.get(),
            'mono_font' : self.mono_var.get()
        })
        self.callback(self.cfg_copy)
        self.destroy()


# ─── GUI 클래스 ─────────────────────────────────────────────────
class App(tb.Window):
    def __init__(self):
        self.app_cfg = {'theme':'darkly', 'font_size':12, 'timeout':10, 'base_font':'Apple SD Gothic Neo', 'mono_font':'SF Mono'}
        super().__init__(themename=self.app_cfg['theme'])
        self.title('MultiRunMem GUI')
        self.geometry('860x660')

        self.code_font = tkfont.Font(
            name='CodeFont',
            family=self.app_cfg['mono_font'],
            size=10                     # 기본 크기
        )

        style = ttk.Style()
        style.configure("Path.TLabel",
                        background="#345",   # 원하는 색상
                        foreground="white",
                        padding=6,
                        relief="raised")

        self._apply_base_font()

        menubar = tb.Menu(self)
        file_m = tb.Menu(menubar, tearoff=0)
        file_m.add_command(label='Exit', command=self.quit)
        menubar.add_cascade(label='File', menu=file_m)

        set_m = tb.Menu(menubar, tearoff=0)
        set_m.add_command(label='Preferences...', command=self.open_settings)
        menubar.add_cascade(label='Settings', menu=set_m)

        help_m = tb.Menu(menubar, tearoff=0)
        help_m.add_command(label='About', command=lambda:messagebox.showinfo('About', 'MultiRunMem GUI\nⓒ 2025'))
        menubar.add_cascade(label='Help', menu=help_m)

        self.config(menu=menubar)

        # ── 상단 파일 입력부 ──────────────────────
        top = ttk.Frame(self); top.pack(fill='x', padx=8, pady=4)
        self.src_var, self.in_var = tb.StringVar(), tb.StringVar()

        ttk.Label(top, text='Source:').grid(row=0, column=0, sticky='w')
        ttk.Entry(top, textvariable=self.src_var, width=60)\
            .grid(row=0, column=1, sticky='we')
        ttk.Button(top, text='...', command=self.pick_src, style="darkly")\
            .grid(row=0, column=2, padx=4)

        ttk.Label(top, text='Input File:').grid(row=1, column=0, sticky='w')
        ttk.Entry(top, textvariable=self.in_var, width=60)\
            .grid(row=1, column=1, sticky='we')
        ttk.Button(top, text='...', command=self.pick_in, style="darkly")\
            .grid(row=1, column=2, padx=4)
        # ── 상태 바 ───────────────────────────────
        self.status = ttk.Label(self, text='Ready', anchor='w')
        self.status.pack(side='bottom', fill='x', padx=8, pady=4)
        top.columnconfigure(1, weight=1)

        # ── 수동 stdin 입력 ───────────────────────
        ttk.Label(self, text='Manual stdin (optional):').pack(anchor='w', padx=8)
        self.stdin_box = ScrolledText(self, height=6, font='CodeFont')
        self.stdin_box.pack(fill='both', padx=8, pady=(0, 6))

        btn_frame = ttk.Frame(self)
        btn_frame.pack(fill='x', pady=4)

        # ── RUN 버튼 ─────────────────────────────
        self.run_btn = ttk.Button(btn_frame, text='RUN',
                                  style='darkly',
                                  command=self.run_clicked)
        self.run_btn.pack(side='left', padx=8, pady=4)

        self.clean_btn = ttk.Button(btn_frame, text='Clear stdin',
                                    style='darkly',
                                    command=self.clean_clicked)
        
        self.clean_btn.pack(side='left', padx=8, pady=4)

        # ── 결과 탭 ───────────────────────────────
        self.nb = ttk.Notebook(self, style="darkly")
        self.out_box = ScrolledText(self.nb, font='CodeFont');  self.nb.add(self.out_box, text='Output')
        self.err_box = ScrolledText(self.nb, bootstyle='danger', font='CodeFont'); self.nb.add(self.err_box, text='Error')
        self.log_box = ScrolledText(self.nb, bootstyle='info', font='CodeFont'); self.nb.add(self.log_box, text='Log')
        self.nb.pack(fill='both', expand=True, padx=8, pady=4)

        self._toast = None

    # ── 설정 창 열기 ─────────────────
    def open_settings(self):
        SettingsDialog(self, self.app_cfg,
                       theme_names=tb.Style().theme_names(),
                       callback=self.apply_settings)

    def apply_settings(self, new_cfg:dict):
        """SettingsDialog -> OK 눌렀을 때 호출"""
        changed_theme = new_cfg['theme'] != self.app_cfg['theme']
        changed_font  = new_cfg['font_size'] != self.app_cfg['font_size']
        changed_base = new_cfg['base_font'] != self.app_cfg['base_font']
        changed_mono = new_cfg['mono_font'] != self.app_cfg['mono_font']
        self.app_cfg.update(new_cfg)

        if changed_theme:
            tb.Style().theme_use(self.app_cfg['theme'])

        if changed_font or changed_base:
            self._apply_base_font()

        if changed_mono:
            self.code_font.configure(family=self.app_cfg['mono_font'])

        # timeout 은 run_with_memory 호출 때 사용
        self._log('Settings updated.')

    def _apply_base_font(self):
        base = tkfont.nametofont('TkDefaultFont')
        base.configure(size=self.app_cfg['font_size'], family=self.app_cfg['base_font'])
        # Treeview/Entry 등에도 자동 전파

    # ── 파일 다이얼로그 ──────────────────────────
    
    def pick_src(self):
        def on_file_selected(path):
            self.src_var.set(path)
            self._file_dialog = None  # release reference

        # Keep a reference!
        self._file_dialog = CustomFileDialog(
            self,
            title="Choose source",
            initialdir=os.path.dirname(self.src_var.get() or os.getcwd()),
            filetypes=[('Source', '*.c *.cpp *.cc *.cxx *.java *.py'), ('All', '*.*')],
            callback=on_file_selected
        )

    def pick_in(self):
        def on_file_selected(path):
            self.in_var.set(path)
            self._file_dialog = None
        
        self._file_dialog = CustomFileDialog(
            self,
            title="Choose input",
            initialdir=os.path.dirname(self.in_var.get() or os.getcwd()),
            filetypes=[('All', '*.*')],
            callback=on_file_selected
        )
        
    # ── RUN 클릭 ────────────────────────────────
    def run_clicked(self):
        src = self.src_var.get().strip()
        if not src:
            messagebox.showwarning('Warn', '소스 파일을 선택하세요')
            return

        stdin_data = (open(self.in_var.get()).read()
                      if self.in_var.get()
                      else self.stdin_box.get('1.0', 'end-1c'))

        self._set_busy(True)
        self._clear_io()
        self._log('Start...')

        threading.Thread(target=self._worker,
                         args=(src, stdin_data),
                         daemon=True).start()
        
    def clean_clicked(self):
        self.stdin_box.delete('1.0', tk.END)


    # ── 백그라운드 작업 ──────────────────────────
    def _worker(self, src, stdin_data):
        try:
            lang, exe, cwd = compile_source(src)
            self._log(f'Compiled ({lang}) OK')
            cmd = {'c':     [exe],
                   'cpp':   [exe],
                   'java':  ['java', exe],
                   'python':['python3', exe]}[lang]

            code, out, err, peak, t = run_with_memory(cmd, stdin_data, cwd=cwd)
            if code != 0:
                raise RuntimeError(f"Program exited with code {code}\n\n{err.strip()}")
            self.after(0, self._done, code, out, err, peak, t)
        except Exception as e:
            self.after(0, self._error, e)

    # ── UI 유틸 ─────────────────────────────────
    def _set_busy(self, b: bool):
        self.run_btn['state'] = 'disabled' if b else 'normal'
        self.status['text'] = 'Running...' if b else 'Ready'

    def _clear_io(self):
        for box in (self.out_box, self.err_box, self.log_box):
            box.delete('1.0', 'end')

    def _log(self, msg: str):
        self.log_box.insert('end', msg + '\n')
        self.log_box.see('end')

    def _error(self, err: Exception):
        self._set_busy(False)
        msg = str(err)
        self.err_box.insert('end', msg+'\n')
        self.err_box.see('end')
        self.status['text'] = 'Error'

        self.nb.select(self.err_box)

    def _done(self, code, out, err, peak, elapsed):
        self._set_busy(False)
        self.out_box.insert('end', out)
        self.err_box.insert('end', err)
        self.status['text'] = (f'Exit:{code}, '
                               f'Peak:{peak/1024/1024:.2f} MB, '
                               f'{elapsed:.2f}s')
        self.nb.select(self.out_box)
        self._log('Done.')

# ─── 실행 ──────────────────────────────────────────────────────
if __name__ == '__main__':
    
    App().mainloop()