#!/usr/bin/env python3
# multi_run_mem_gui.py  –  ttkbootstrap(darkly) + 정확한 RSS + Java cwd fix

import os, sys, time, threading, subprocess, tempfile, platform, resource
import psutil                                       # pip install psutil
import shlex
import fnmatch
from functools import partial
import pathlib
import datetime
import matplotlib
matplotlib.use('TkAgg')
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure

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

# File Picker 팝업
class CustomFileDialog(tb.Toplevel):
    _col_caption = {
        "name": "Name",
        "date": "Date modified",
        "type": "Type",
        "size": "Size"
    }
    PLACEHOLDER = "Search files.."
    EXT_COLORS = {
        '.py': '#B0F7B4',
        '.cpp': '#B0D0F7',
        '.c': '#B0D0F7',
        '.java': '#f2b468',
        '.md': '#9468f2',
    }
    def __init__(self, parent, title="Select File", initialdir=None, filetypes=None, callback=None):
        super().__init__(parent)
        self.title(title)
        self.resizable(True, True)
        self.grab_set()
        self.geometry("1200x700")
        self.callback = callback
        self.filetypes = filetypes or [("All files", "*.*")]
        self.current_dir = os.path.abspath(initialdir or os.getcwd())
        self.selected_file = None

        side = ttk.Frame(self); side.pack(side='left', fill='y', padx=4, pady=4)
        ttk.Label(side, text="Bookmarks").pack(anchor='nw')
        self.bm_list = []
        self.bm_var = tb.StringVar(value=self.bm_list)
        self.bm_lb = tk_list = tk.Listbox(side, listvariable=self.bm_var, height=8, exportselection=False)
        tk_list.pack(fill='both', expand=False)
        tk_list.bind("<<ListboxSelect>>", self._on_bm_select)
        btn_fr = ttk.Frame(side); btn_fr.pack(fill='x', pady=(2,10))
        ttk.Button(btn_fr, text="+", width=2, command=self._add_bookmark, style='darkly', cursor="hand2").pack(side='left', padx=2, pady=2)
        ttk.Button(btn_fr, text="-", width=2, command=self._remove_bookmark, style='darkly', cursor="hand2").pack(side='left', padx=2, pady=2)

        self.show_hidden = tb.BooleanVar(value=False)
        ttk.Checkbutton(side, text="Show hidden", variable=self.show_hidden,
                        bootstyle="round-toggle", command=self.populate).pack(anchor='w')

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
        self.pathbar.grid(row=0, column=3, sticky='ew', padx=(2,0), pady=0)

        self.search_entry = ttk.Entry(toolbar, textvariable=self.search_var, width=24)
        self.search_entry.grid(row=0, column=4, padx=8, pady=4, sticky='ns')
        self.search_entry.insert(0, self.PLACEHOLDER)
        self.search_entry.bind("<FocusIn>", self._clear_placeholder)
        self.search_entry.bind("<FocusOut>", self._add_placeholder)
        self.search_entry.bind("<KeyRelease>", lambda e: self.populate())

        toolbar.columnconfigure(3, weight=1)

        tree_frame = ttk.Frame(self)
        tree_frame.pack(fill='both', expand=True)

        columns = ("name", "date", "type", "size")
        self.tree = ttk.Treeview(tree_frame, columns=columns, show="headings")
        self.tree.tag_configure('odd',  background='#272727')  # 다크테마 예시
        self.tree.tag_configure('even', background='#252525')

        for ext, clr in self.EXT_COLORS.items():
            tag = f"ext_{ext}"
            self.tree.tag_configure(tag, foreground=clr)

        vsb = ttk.Scrollbar(tree_frame, orient="vertical", command=self.tree.yview)
        hsb = ttk.Scrollbar(tree_frame, orient="horizontal", command=self.tree.xview)
        self.tree.configure(yscrollcommand=vsb.set, xscrollcommand=hsb.set)

        self.tree.grid(row=0, column=0, sticky='nsew')
        vsb.grid(row=0, column=1, sticky='ns')
        hsb.grid(row=1, column=0, sticky='ew')
        tree_frame.rowconfigure(0, weight=1)
        tree_frame.columnconfigure(0, weight=1)

        for col in columns:
            self.tree.heading(col, text=self._col_caption[col],
                              command=lambda c=col: self._sort_by_column(c))
        self.tree.column("name", width=320)
        self.tree.column("date", width=160)
        self.tree.column("type", width=120)
        self.tree.column("size", width=80, anchor='e')

        self.tree.bind("<Double-1>", self.on_double_click)
        self.tree.bind("<<TreeviewSelect>>", self.on_select)

        self.status = ttk.Label(self, text="", anchor='w')
        self.status.pack(side='bottom', fill='x', padx=8, pady=2)

        btn_frame = ttk.Frame(self)
        btn_frame.pack(fill='x', pady=4)
        ttk.Button(btn_frame, text="Cancel", command=self.destroy, style="darkly").pack(side='right', padx=4)
        ttk.Button(btn_frame, text="OK", command=self.on_ok, style="darkly").pack(side='right')

        self._current_sort = ("name", False)
        self.populate()
        self.update_nav_buttons()

    def on_cb_change(self, newdir):
        print("CD:", newdir)
        self.pathbar.set_path(newdir)

    def _add_bookmark(self):
        p = self.current_dir
        if p not in self.bm_list:
            self.bm_list.append(p)
            self.bm_var.set(self.bm_list)

    def _remove_bookmark(self):
        sel = self.bm_lb.curselection()
        if not sel: return
        idx = sel[0]
        del self.bm_list[idx]
        self.bm_var.set(self.bm_list)

    def _on_bm_select(self, ev):
        sel = self.bm_lb.curselection()
        if not sel: return
        path = self.bm_list[sel[0]]
        self.change_dir(path)

    def _clear_placeholder(self, event):
        if self.search_var.get() == self.PLACEHOLDER:
            self.search_entry.delete(0, 'end')

    def _add_placeholder(self, event):
        if not self.search_var.get().strip():
            self.search_entry.delete(0, 'end')
            self.search_entry.insert(0, self.PLACEHOLDER)

    def reset_search(self):
        self.search_var.set("")
        self.search_entry.delete(0, 'end')
        self.search_entry.insert(0, self.PLACEHOLDER)
        self.populate()

    def populate(self):
        self.tree.delete(*self.tree.get_children())
        raw = self.search_var.get().strip()
        if raw.lower() == self.PLACEHOLDER.lower():
            search = ""
        else:
            search = raw.lower()
        try:
            entries = os.listdir(self.current_dir)
        except Exception:
            entries = []
        dirs, files = [], []
        for name in entries:
            if search and search not in name.lower():
                continue
            path = os.path.join(self.current_dir, name)
            if os.path.isdir(path):
                dirs.append(name)
            elif self._match_filetypes(name):
                files.append(name)
            
        total_size = 0
        row_idx = 0
        for d in sorted(dirs):
            tag = 'even' if row_idx % 2 else 'odd'
            dt = self._format_time(os.path.getmtime(os.path.join(self.current_dir, d)))
            self.tree.insert("", "end", values=(d, dt, "Directory", ""), tags=(tag,))
            row_idx += 1
        for f in sorted(files):
            tag = 'even' if row_idx % 2 else 'odd'
            fpath = os.path.join(self.current_dir, f)
            size = os.path.getsize(fpath)
            total_size += size
            dt = self._format_time(os.path.getmtime(fpath))
            ext = os.path.splitext(f)[1].lower()
            typ = self._file_type(ext)
            tags = [tag]
            if ext in self.EXT_COLORS:
                tags.append(f"ext_{ext}")
            self.tree.insert("", "end", values=(f, dt, typ, self._format_size(size)), tags=tuple(tags))
            row_idx += 1
        self.status['text'] = f"{len(dirs)+len(files)} items | {self._format_size(total_size)} Total"

        col, rev = self._current_sort
        self._sort_by_column(col, keep_direction=True)

    def _sort_by_column(self, col, keep_direction=False):
        if keep_direction:
            reverse = self._current_sort[1]
        else:
            reverse = not self._current_sort[1] if self._current_sort[0] == col else False
        self._current_sort = (col, reverse)

        def sort_key(item_id):
            value = self.tree.set(item_id, col)
            if col == "size":
                return self._str_size_to_int(value)
            if col == "date":
                try:
                    return datetime.datetime.strptime(value, "%Y-%m-%d %H:%M")
                except ValueError:
                    return datetime.datetime.min
            return value.lower()
        
        items = self.tree.get_children("")
        sorted_items = sorted(items, key=sort_key, reverse=reverse)

        for idx, item_id in enumerate(sorted_items):
            self.tree.move(item_id, "", idx)

        for c in self.tree["columns"]:
            text = self._col_caption[c]
            if c == col:
                text += " ▲" if not reverse else " ▼"
            self.tree.heading(c, text=text, command=lambda c=c: self._sort_by_column(c))

    @staticmethod
    def _str_size_to_int(txt):
        if not txt:
            return 0
        num, unit = txt.split()
        num = float(num)
        unit = unit.upper()
        factor = {"B":1, "KB":1024, "MB":1024**2, "GB":1024**3, "TB":1024**4}
        return int(num * factor.get(unit, 1))            

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
            self.reset_search()
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

        ttk.Label(self, text="Memory Limit (MB):").grid(row=5, column=0, sticky='e', padx=6, pady=6)
        self.mem_var = tb.IntVar(value=cfg.get('mem_limit_mb', 0))
        ttk.Spinbox(self, from_=0, to=10240, textvariable=self.mem_var, width=6).grid(row=5, column=1, sticky='w', padx=6, pady=6)



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
        self.peak = 0
        self.proc = None

    def on_start(self, proc: psutil.Process):
        self.proc = proc
        try:
            rss0 = proc.memory_info().rss
            self.peak = rss0
        except psutil.Error:
            self.peak = 0

    def on_sample(self):
        if not self.proc:
            return
        try:
            rss = self.proc.memory_info().rss
            # 피크 갱신
            if rss > self.peak:
                self.peak = rss
            # limit 초과 시 알람 + 강제 종료
            if self.limit > 0 and self.peak > self.limit:
                self.proc.kill()
                ToastNotification(
                    title="Memory Limit Exceeded",
                    message=(
                        f"Peak RSS {self.peak/1024**2:.1f} MB  >  "
                        f"Limit {self.limit/1024**2:.1f} MB"
                    ),
                    duration=3000,
                    alert=True
                ).show_toast(self.parent)
        except psutil.Error:
            pass

    def on_finish(self):
        # 종료 직후 한 번 더 체크
        try:
            rss = self.proc.memory_info().rss
            if rss > self.peak:
                self.peak = rss
        except:
            pass
        return {"peak_rss": f"{self.peak/1024**2:.1f} MB"}
    

class CpuUsagePlugin(PluginBase):
    """CPU 평균/최대 사용률 측정"""
    def __init__(self):
        self.proc = None
        self.max_pct = 0.0
        self.start_cpu_time = 0.0
        self.start_wall = 0.0

    def on_start(self, proc: psutil.Process):
        self.proc = proc
        # 시작 시점 전체 CPU 시간(user+sys) 과 wall-clock 시간 기록
        times = proc.cpu_times()
        self.start_cpu_time = times.user + times.system
        self.start_wall = time.time()
        # cpu_percent() 첫 호출은 baseline 설정용
        try:
            proc.cpu_percent(interval=None)
        except psutil.Error:
            pass

    def on_sample(self):
        if not self.proc:
            return
        try:
            pct = self.proc.cpu_percent(interval=None)
            if pct > self.max_pct:
                self.max_pct = pct
        except psutil.Error:
            pass

    def on_finish(self):
        end_wall = time.time()
        elapsed = end_wall - self.start_wall
        try:
            times = self.proc.cpu_times()
            total_cpu = (times.user + times.system) - self.start_cpu_time
            avg_pct = (total_cpu / elapsed * 100) if elapsed > 0 else 0.0
        except psutil.Error:
            avg_pct = 0.0
        return {
            "cpu_avg%": round(avg_pct, 1),
            "cpu_max%": round(self.max_pct, 1)
        }

# ─── GUI 클래스 ─────────────────────────────────────────────────
class App(tb.Window):
    def __init__(self):
        self.app_cfg = {'theme':'darkly', 'font_size':12, 'timeout':10, 'base_font':'Apple SD Gothic Neo', 'mono_font':'SF Mono', 'mem_limit_mb': 0,}
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

        self._large_font_var      = tb.BooleanVar(value=False)
        self._high_contrast_var   = tb.BooleanVar(value=False)

        menubar = tb.Menu(self)
        file_m = tb.Menu(menubar, tearoff=0)
        file_m.add_command(label='Open Source...', accelerator='Ctrl+O', command=self.pick_src)
        file_m.add_command(label='Open Input...', accelerator='Ctrl+I', command=self.pick_in)
        file_m.add_separator()
        file_m.add_command(label='Exit', accelerator='Ctrl+Q', command=self.quit)
        menubar.add_cascade(label='File', menu=file_m)

        set_m = tb.Menu(menubar, tearoff=0)
        set_m.add_command(label='Preferences...', command=self.open_settings)
        menubar.add_cascade(label='Settings', menu=set_m)

        # View menu (our new accessibility toggles)
        view_m = tb.Menu(menubar, tearoff=0)
        view_m.add_checkbutton(label='Large Font', accelerator='Ctrl+Plus / Ctrl+Minus',
                               variable=self._large_font_var,
                               command=self._toggle_large_font)
        view_m.add_checkbutton(label='High Contrast',
                               variable=self._high_contrast_var,
                               command=self._toggle_high_contrast)
        menubar.add_cascade(label='View', menu=view_m)

        help_m = tb.Menu(menubar, tearoff=0)
        help_m.add_command(label='About', command=lambda:messagebox.showinfo('About', 'MultiRunMem GUI\nⓒ 2025'))
        menubar.add_cascade(label='Help', menu=help_m)

        self.config(menu=menubar)

        self.bind_all('<Control-o>', lambda e: self.pick_src())
        self.bind_all('<Control-i>', lambda e: self.pick_in())
        self.bind_all('<Control-r>', lambda e: self.run_clicked())
        self.bind_all('<Control-q>', lambda e: self.quit())

        self.bind_all('<Control-plus>',  lambda e: self._adjust_font_size(+2))
        self.bind_all('<Control-minus>', lambda e: self._adjust_font_size(-2))

        self.bind_all('<F6>',       self._cycle_tab_forward)
        self.bind_all('<Shift-F6>', self._cycle_tab_backward)

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

        self.stats_frame = ttk.Frame(self.nb)
        self.nb.add(self.stats_frame, text='Stats')

        self.stats_time = []
        self.stats_cpu = []
        self.stats_mem = []

        self.fig = Figure(figsize=(5,2.5), dpi=100)
        self.ax_cpu = self.fig.add_subplot(211)
        self.ax_mem = self.fig.add_subplot(212)

        self.line_cpu, = self.ax_cpu.plot([], [], label='CPU %', color='tab:orange')
        self.line_mem, = self.ax_mem.plot([], [], label='RSS (MB)', color='tab:green')

        self.ax_cpu.set_ylabel('CPU %')
        self.ax_mem.set_ylabel('RSS (MB)')
        self.ax_mem.set_xlabel('Time (s)')
        self.ax_cpu.set_xlim(0,10); self.ax_cpu.set_ylim(0,100)
        self.ax_mem.set_xlim(0,10); self.ax_mem.set_ylim(0,100)

        self.ax_cpu.legend(loc='upper right', fontsize='small')
        self.ax_mem.legend(loc='upper right', fontsize='small')

        self.canvas_plot = FigureCanvasTkAgg(self.fig, master=self.stats_frame)
        self.canvas_plot.draw()
        self.canvas_plot.get_tk_widget().pack(fill='both', expand=True)

        self.nb.pack(fill='both', expand=True, padx=8, pady=4)

        self._stats_after_id = None
        # sampling interval (ms)
        self.sampling_ms = 100

        self._toast = None

    def _cycle_tab_forward(self, event=None):
        tabs = self.nb.tabs()
        if not tabs: return
        idx = tabs.index(self.nb.select())
        self.nb.select(tabs[(idx + 1) % len(tabs)])

    def _cycle_tab_backward(self, event=None):
        tabs = self.nb.tabs()
        if not tabs: return
        idx = tabs.index(self.nb.select())
        self.nb.select(tabs[(idx - 1) % len(tabs)])

    def _toggle_large_font(self):
        """Switch between normal and large-base‐font mode."""
        base = tkfont.nametofont('TkDefaultFont')
        if self._large_font_var.get():
            base.configure(size=max(base.cget('size'), 16))
        else:
            # revert to user‐configured app_cfg size
            base.configure(size=self.app_cfg['font_size'])

    def _adjust_font_size(self, delta: int):
        """Ctrl+Plus / Ctrl+Minus to nudge the font size."""
        cur = self.app_cfg['font_size'] = max(8, self.app_cfg['font_size'] + delta)
        if not self._large_font_var.get():
            nametofont = tkfont.nametofont('TkDefaultFont')
            nametofont.configure(size=cur)

    def _toggle_high_contrast(self):
        """Switch to a high‐contrast ttkbootstrap theme or back."""
        if self._high_contrast_var.get():
            tb.Style().theme_use('cyborg')   # built‐in high‐contrast dark theme
        else:
            tb.Style().theme_use(self.app_cfg['theme'])

    def _start_stats(self):
        self.stats_time.clear()
        self.stats_cpu.clear()
        self.stats_mem.clear()
        self._stats_start = time.time()
        if self._stats_after_id:
            self.after_cancel(self._stats_after_id)
        self._stats_after_id = self.after(self.sampling_ms, self._update_stats)

    def _update_stats(self):
        """Sample current CPU% and RSS, update plots, and reschedule."""
        proc = getattr(self, '_current_proc', None)
        if proc and proc.poll() is None:
            ps_proc = psutil.Process(proc.pid)
            now = time.time() - self._stats_start
            try:
                cpu_pct = ps_proc.cpu_percent(interval=None)
                rss_mb  = ps_proc.memory_info().rss / (1024**2)
            except psutil.Error:
                cpu_pct, rss_mb = 0.0, 0.0

            # append data
            self.stats_time.append(now)
            self.stats_cpu.append(cpu_pct)
            self.stats_mem.append(rss_mb)

            # update line data
            self.line_cpu.set_data(self.stats_time, self.stats_cpu)
            self.line_mem.set_data(self.stats_time, self.stats_mem)

            # rescale X axis
            xmax = max(10, now)
            self.ax_cpu.set_xlim(0, xmax)
            self.ax_mem.set_xlim(0, xmax)
            # optionally autoscale RSS Y
            ymax_mem = max(self.stats_mem) * 1.2 if self.stats_mem else 100
            self.ax_mem.set_ylim(0, max(ymax_mem, 1))

            # redraw
            self.canvas_plot.draw()

            # schedule next
            self._stats_after_id = self.after(self.sampling_ms, self._update_stats)
        else:
            # process ended → stop scheduling
            self._stats_after_id = None

    def _cancel_stats(self):
        """Cancel the scheduled after-loop if any."""
        if self._stats_after_id:
            self.after_cancel(self._stats_after_id)
            self._stats_after_id = None

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

        self._start_stats()

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
            
            proc = subprocess.Popen(
                cmd, cwd=cwd, text=True,
                stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE
            )

            self._current_proc = proc
            ps_proc = psutil.Process(proc.pid)

            plugins = [
                MemoryLimitPlugin(self.app_cfg['mem_limit_mb'] * 1024 ** 2, self),
                CpuUsagePlugin(),
            ]
            for pl in plugins:
                pl.on_start(ps_proc)

            def monitor_loop():
                while proc.poll() is None:
                    for pl in plugins:
                        pl.on_sample()
                    time.sleep(0.05)
                threading.Thread(target=monitor_loop, daemon=True).start()

            code, out, err, peak, t = run_with_memory(cmd, stdin_data, cwd=cwd)
            if code != 0:
                raise RuntimeError(f"Program exited with code {code}\n\n{err.strip()}")
            
            metrics = {}
            for pl in plugins:
                metrics.update(pl.on_finish())

            self.after(0, self._done, code, out, err, peak, t, metrics)
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
        self._cancel_stats()
        self._set_busy(False)
        msg = str(err)
        self.err_box.insert('end', msg+'\n')
        self.err_box.see('end')
        self.status['text'] = 'Error'

        self.nb.select(self.err_box)

    def _done(self, code, out, err, peak, elapsed, metrics:dict):
        self._cancel_stats()
        self._set_busy(False)
        self.out_box.insert('end', out)
        self.err_box.insert('end', err)
        msg = f"Exit:{code} | "
        msg += " | ".join(f"{k}: {v if isinstance(v, str) else round(v, 2)}" for k,v in metrics.items())
        msg += f" | Elapsed Time(ms): {(elapsed * 1000.0):.2f} ms"
        self.status['text'] = msg
        self.nb.select(self.out_box)
        self._log('Done.')

# ─── 실행 ──────────────────────────────────────────────────────
if __name__ == '__main__':
    
    App().mainloop()