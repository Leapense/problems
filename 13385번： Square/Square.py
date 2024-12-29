def compute_L(a):
    p, q = a[-1], 1
    for ai in reversed(a[:-1]):
        p, q = ai * p + q, p
    return p

M = int(input())
for _ in range(M):
    parts = list(map(int, input().split()))
    r = parts[0]
    a = parts[1:]
    print(compute_L(a))