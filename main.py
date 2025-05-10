import os, sys, subprocess, tempfile, threading, time, shutil
import psutil

def detect_lang(path:str)->str|None:
    ext = os.path.splitext(path)[1].lower()
    return {
        '.c'   :'c',
        '.cpp' :'cpp', '.cc':'cpp', '.cxx':'cpp',
        '.java':'java',
        '.py'  :'python',
    }.get(ext)

def compile_source(src:str) -> dict:
    lang = detect_lang(src)
    if lang is None:
        raise ValueError(f'지원하지 않는 확장자: {src}')
    
    if lang in ('c','cpp'):
        exe = tempfile.mktemp(prefix='prog_', dir='.')          # 임시 실행 파일 경로
        cmd = ['gcc' if lang=='c' else 'g++', src,
               '-O2','-std=c17' if lang=='c' else '-std=c++26',
               '-Wall','-pipe','-o', exe]
        subprocess.check_call(cmd)
        return {'lang':lang, 'run_path':exe}

    # Java
    if lang=='java':
        subprocess.check_call(['javac', src])
        main_class = os.path.splitext(os.path.basename(src))[0]
        return {'lang':'java', 'run_path':main_class}

    # Python (컴파일 없음)
    return {'lang':'python', 'run_path':src}

def run_with_memory(cmd:list, input_data:str='',
                    timeout:int=10)->tuple[int,str,str,int]:
    """
    cmd            : 실행 커맨드(list)
    input_data     : stdin 으로 보낼 문자열
    return         : (exit_code, stdout, stderr, peak_rss_bytes)
    """
    proc   = subprocess.Popen(cmd,
                              stdin=subprocess.PIPE,
                              stdout=subprocess.PIPE,
                              stderr=subprocess.PIPE,
                              text=True)
    ps_proc = psutil.Process(proc.pid)
    peak    = 0

    # 모니터링 스레드
    def monitor():
        nonlocal peak
        try:
            while proc.poll() is None:
                peak = max(peak, ps_proc.memory_info().rss)
                time.sleep(0.05)
        except psutil.NoSuchProcess:
            pass

    threading.Thread(target=monitor, daemon=True).start()

    try:
        stdout, stderr = proc.communicate(input=input_data, timeout=timeout)
    except subprocess.TimeoutExpired:
        proc.kill()
        stdout, stderr = proc.communicate()

    # 혹시 모를 종료 직전 값 반영
    try:
        peak = max(peak, ps_proc.memory_info().rss)
    except psutil.Error:
        pass

    return proc.returncode, stdout, stderr, peak

def main():
    if len(sys.argv) < 2:
        print('사용법: python3 main.py <소스파일> [<입력파일>]')
        sys.exit(1)
    
    src_file = sys.argv[1]
    input_data = open(sys.argv[2]).read() if len(sys.argv) >= 3 else ''
    info = compile_source(src_file)
    lang, run_path = info['lang'], info['run_path']

    cmd = {
        'c'     : [run_path],
        'cpp'   : [run_path],
        'java'  : ['java', run_path],
        'python': ['python3', run_path],
    }[lang]

    code, out, err, mem = run_with_memory(cmd, input_data)

    print(f'=====  실행 결과  =====')
    print(f'   언어        : {lang}')
    print(f'   종료코드    : {code}')
    print(f'   Peak Memory : {mem/1024/1024:.2f} MB')
    print('>>> stdout -------------------------------')
    print(out.rstrip())
    print('>>> stderr -------------------------------')
    print(err.rstrip())

if __name__ == '__main__':
    main()