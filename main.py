#!/usr/bin/env python3
# coding: utf-8
"""
one_by_one_learn.py  (stdin 지원판)
"""

import argparse, json, re, subprocess, time, psutil, sys
from pathlib import Path
import torch, torch.nn as nn, torch.optim as optim

# ──────────────────  (1) 컴파일 관련  ──────────────────
def detect_lang(src: Path):
    return {'.cpp':'cpp','.cc':'cpp','.cxx':'cpp',
            '.java':'java',
            '.py':'python'}.get(src.suffix.lower(), 'python')

def compile_src(src: Path):
    lang = detect_lang(src)
    if lang == 'cpp':
        exe = src.with_suffix('')
        subprocess.run(['g++','-O2','-std=c++26',str(src),'-o',str(exe)], check=True)
        return exe, lang, src.parent
    elif lang == 'java':
        subprocess.run(['javac', src.name],
                       cwd=src.parent, check=True)
        return src.stem, 'java', src.parent   # (exe, lang, work_dir)
    else:  # python
        return src, lang, src.parent

# ──────────────────  (2) 실행 + 메모리 측정  ──────────────────
def run_and_peak(exe, lang, src_dir: Path, input_bytes=None, timeout=30):
    cmd = [str(exe)] if lang=='cpp' else \
          ['java', exe] if lang=='java' else \
          ['python3', str(exe)]

    proc = subprocess.Popen(cmd,
                            cwd=str(src_dir),
                            stdin=subprocess.PIPE,
                            stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE)

    # ── 표준 입력 전달 ────────────────────────────────
    if input_bytes:
        proc.stdin.write(input_bytes)
        proc.stdin.flush()
        proc.stdin.close()   # EOF 알림
        proc.stdin = None    # ★ flush of closed file 방지 ★

    # ── 메모리 샘플링 루프 ────────────────────────────
    import psutil, time
    peak = 0; p = psutil.Process(proc.pid); t0 = time.time()
    while proc.poll() is None:
        try: peak = max(peak, p.memory_info().rss)
        except psutil.NoSuchProcess: break
        if time.time() - t0 > timeout:
            proc.kill(); break
        time.sleep(0.05)

    out, err = proc.communicate()
    return peak/1024**2, out.decode(), err.decode()

# ──────────────────  (3) Feature 추출  ──────────────────
LANG2OH = {'cpp':[1,0,0],'java':[0,1,0],'python':[0,0,1]}
def extract_feat(src: Path):
    code = src.read_text(errors='ignore')
    return [code.count('\n')+1,
            len(code),
            len(re.findall(r'//|#',code))] + LANG2OH[detect_lang(src)]

# ──────────────────  (4) PyTorch 모델  ──────────────────
class MLP(nn.Module):
    def __init__(self,d_in):
        super().__init__()
        self.m = nn.Sequential(
            nn.Linear(d_in,64), nn.ReLU(),
            nn.Linear(64,32), nn.ReLU(),
            nn.Linear(32,1))
    def forward(self,x): return self.m(x)

# ──────────────────  (5) main  ──────────────────
def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--file', required=True, help='측정할 소스 파일')
    ap.add_argument('--stdin', help='따옴표로 감싼 문자열 입력')
    ap.add_argument('--stdin-file', help='입력 내용이 적힌 파일 경로')
    ap.add_argument('--dataset', default='memory_dataset.json')
    ap.add_argument('--epochs', type=int, default=300)
    args = ap.parse_args()

    # 입력 만들기
    if args.stdin:
        input_bytes = args.stdin.encode()
    elif args.stdin_file:
        input_bytes = Path(args.stdin_file).read_bytes()
    else:
        input_bytes = None

    src = Path(args.file).resolve()
    exe, lang, src_dir = compile_src(src)
    peak, stdout_txt, stderr_txt = run_and_peak(exe, lang, src_dir, input_bytes)
    feat = extract_feat(src)
    print(f'📏 {src.name}  peak={peak:.2f} MB  feat={feat}')
    if stderr_txt:
        print(f'⚠️ stderr: {stderr_txt.splitlines()[:3]}')

    # ----- 데이터셋 누적 -----
    ds = Path(args.dataset)
    data = json.loads(ds.read_text()) if ds.exists() else []
    data.append({'feat':feat,'peak':peak})
    ds.write_text(json.dumps(data,indent=2))
    print(f'✅ 누적 샘플 수 = {len(data)} (→ {ds})')

    # ----- 학습 -----
    if len(data) < 2:
        print('ℹ️  샘플 2개 이상 필요 → 학습 건너뜀'); return
    X = torch.tensor([d['feat'] for d in data],dtype=torch.float32)
    y = torch.tensor([[d['peak']] for d in data],dtype=torch.float32)

    model = MLP(X.shape[1]); opt = torch.optim.Adam(model.parameters(),1e-3)
    for ep in range(args.epochs):
        opt.zero_grad(); loss = nn.MSELoss()(model(X),y)
        loss.backward(); opt.step()
        if (ep+1)%50==0 or ep==0:
            print(f'Epoch {ep+1}/{args.epochs}  MSE={loss.item():.3f}')
    torch.save({'state':model.state_dict(),'dim':X.shape[1]},'mem_predictor.pt')
    print('💾 mem_predictor.pt 저장 완료')

if __name__ == '__main__': main()