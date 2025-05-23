import sys, itertools
from itertools import combinations

N, K = map(int, sys.stdin.readline().split())
scores = list(map(float, sys.stdin.readline().split()))
A = float(sys.stdin.readline())

indices = list(range(N))
for skipped in combinations(indices, K):
    R = [scores[i] for i in indices if i not in skipped]
    min_r = min(R)
    max_r = max(R)
    R_copy = R.copy()
    if min_r != max_r:
        try:
            R_copy.remove(min_r)
            R_copy.remove(max_r)
        except ValueError:
            continue
    else:
        if R_copy.count(min_r) < 2:
            continue
        R_copy.remove(min_r)
        R_copy.remove(min_r)
    sum_r = sum(R_copy)
    avg = sum_r / (N - K - 2)
    avg_rounded = round(avg + 1e-8, 2)
    if avg_rounded == A:
        skipped_scores = [scores[i] for i in skipped]
        erased = [min_r, max_r]
        result = skipped_scores + erased
        print(' '.join(f"{x:.2f}" for x in result))
        sys.exit(0)