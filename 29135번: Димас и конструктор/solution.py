import sys
data = sys.stdin.readline().split()
n, k = map(int, data)
a = list(map(int, sys.stdin.readline().split()))
lo = min(a)
hi = lo + k

while lo < hi:
    mid = (lo + hi + 1) // 2
    need = 0
    for v in a:
        if v < mid:
            need += mid - v
            if need > k:
                break
    if need <= k:
        lo = mid
    else:
        hi = mid - 1

print(lo)