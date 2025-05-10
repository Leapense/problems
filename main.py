#!/usr/bin/env python3
# multi_run_mem_gui.py  –  ttkbootstrap(darkly) + 정확한 RSS + Java cwd fix

import os, sys, time, threading, subprocess, tempfile, platform, resource
import psutil                                       # pip install psutil

# ─── GUI 라이브러리 ───────────────────────────────────────────────
import ttkbootstrap as tb                           # pip install ttkbootstrap
from ttkbootstrap import ttk
from ttkbootstrap.scrolled import ScrolledText
from tkinter import filedialog, messagebox
import tkinter.font as tkfont
import tkinter as tk

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
        subprocess.check_call(cmd)
        return lang, exe, workdir

    if lang == 'java':
        subprocess.check_call(['javac', src])
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
        ttk.Button(btn_fr, text="Cancel", command=self.destroy).pack(side='right', padx=4)
        ttk.Button(btn_fr, text="OK", bootstyle='primary', command=self._ok).pack(side='right')

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
        self.geometry('820x600')

        self._apply_base_font()

        menubar = tb.Menu(self)
        file_m = tb.Menu(menubar, tearoff=0)
        file_m.add_command(label='Exit', command=self.quit)
        menubar.add_cascade(label='File', menu=file_m)

        set_m = tb.Menu(menubar, tearoff=0)
        set_m.add_command(label='Preferences...', command=self.open_settings)
        menubar.add_cascade(label='Settings', menu=set_m)

        help_m = tb.Menu(menubar, tearoff=0)
        help_m.add_command(label='About', command=lambda:messagebox.showinfo('About', 'MultiRunMem GUI\nⓒ 2024'))
        menubar.add_cascade(label='Help', menu=help_m)

        self.config(menu=menubar)

        # ── 상단 파일 입력부 ──────────────────────
        top = ttk.Frame(self); top.pack(fill='x', padx=8, pady=4)
        self.src_var, self.in_var = tb.StringVar(), tb.StringVar()

        ttk.Label(top, text='Source:').grid(row=0, column=0, sticky='w')
        ttk.Entry(top, textvariable=self.src_var, width=60)\
            .grid(row=0, column=1, sticky='we')
        ttk.Button(top, text='...', command=self.pick_src)\
            .grid(row=0, column=2, padx=4)

        ttk.Label(top, text='Input File:').grid(row=1, column=0, sticky='w')
        ttk.Entry(top, textvariable=self.in_var, width=60)\
            .grid(row=1, column=1, sticky='we')
        ttk.Button(top, text='...', command=self.pick_in)\
            .grid(row=1, column=2, padx=4)
        # ── 상태 바 ───────────────────────────────
        self.status = ttk.Label(self, text='Ready', anchor='w')
        self.status.pack(side='bottom', fill='x', padx=8, pady=4)
        top.columnconfigure(1, weight=1)

        # ── 수동 stdin 입력 ───────────────────────
        ttk.Label(self, text='Manual stdin (optional):').pack(anchor='w', padx=8)
        self.stdin_box = ScrolledText(self, height=6, font='CodeFont')
        self.stdin_box.pack(fill='both', padx=8, pady=(0, 6))

        # ── RUN 버튼 ─────────────────────────────
        self.run_btn = ttk.Button(self, text='RUN',
                                  bootstyle='primary',
                                  command=self.run_clicked)
        self.run_btn.pack(pady=4)

        # ── 결과 탭 ───────────────────────────────
        nb = ttk.Notebook(self)
        self.out_box = ScrolledText(nb, font='CodeFont');    nb.add(self.out_box, text='Output')
        self.err_box = ScrolledText(nb, fg='red', font='CodeFont'); nb.add(self.err_box, text='Error')
        self.log_box = ScrolledText(nb, fg='gray', font='CodeFont'); nb.add(self.log_box, text='Log')
        nb.pack(fill='both', expand=True, padx=8, pady=4)

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
            try:
                mono_font = tkfont.nametofont('CodeFont')
            except tk.TclError:
                mono_font = tkfont.Font(name='CodeFont', family=self.app_cfg['mono_font'], size=10)
            else:
                mono_font.configure(family=self.app_cfg['mono_font'])

        # timeout 은 run_with_memory 호출 때 사용
        self._log('Settings updated.')

    def _apply_base_font(self):
        base = tkfont.nametofont('TkDefaultFont')
        base.configure(size=self.app_cfg['font_size'], family=self.app_cfg['base_font'])
        # Treeview/Entry 등에도 자동 전파

    # ── 파일 다이얼로그 ──────────────────────────
    def pick_src(self):
        f = filedialog.askopenfilename(
            title='Choose source',
            filetypes=[('Source', '*.c *.cpp *.cc *.cxx *.java *.py'),
                       ('All', '*.*')])
        if f:
            self.src_var.set(f)

    def pick_in(self):
        f = filedialog.askopenfilename(title='Choose input file')
        if f:
            self.in_var.set(f)

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
        self.err_box.insert('end', str(err))
        self.err_box.see('end')
        self.status['text'] = 'Error'

    def _done(self, code, out, err, peak, elapsed):
        self._set_busy(False)
        self.out_box.insert('end', out)
        self.err_box.insert('end', err)
        self.status['text'] = (f'Exit:{code}, '
                               f'Peak:{peak/1024/1024:.2f} MB, '
                               f'{elapsed:.2f}s')
        self._log('Done.')

# ─── 실행 ──────────────────────────────────────────────────────
if __name__ == '__main__':
    App().mainloop()