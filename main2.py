#!/usr/bin/env python3
# inspect_pt.py
import argparse, torch, torch.nn as nn
from pathlib import Path

# ── CLI ──────────────────────────────────────────────
ap = argparse.ArgumentParser()
ap.add_argument('pt_file')
ap.add_argument('--show-weights', action='store_true')
ap.add_argument('--summary',       action='store_true',
                help='torchinfo summary 출력')
args = ap.parse_args()

# ── 체크포인트 로드 ──────────────────────────────────
ckpt = torch.load(args.pt_file, map_location='cpu')
print('* Keys:', ckpt.keys())
print('* Feature dim:', ckpt.get('dim'))

# ── (옵션) 가중치 목록 보기 ──────────────────────────
if args.show_weights:
    for k, v in ckpt['state'].items():
        print(f'{k:25s}  {tuple(v.shape)}  mean={v.mean():.4f}')

# ── (옵션) torchinfo summary ─────────────────────────
if args.summary:
    from torchinfo import summary

    class MLP(nn.Module):                     # 저장 당시 구조와 동일해야 함
        def __init__(self, d):
            super().__init__()
            self.m = nn.Sequential(
                nn.Linear(d, 64), nn.ReLU(),
                nn.Linear(64, 32), nn.ReLU(),
                nn.Linear(32, 1))
        def forward(self, x): return self.m(x)

    model = MLP(ckpt['dim'])
    model.load_state_dict(ckpt['state'])
    model.eval()

    print('\n── torchinfo summary ──')
    summary(model, input_size=(1, ckpt['dim']))