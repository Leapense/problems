import sys

MOD = 1_000_000_009

def solve():
    data = [line.strip() for line in sys.stdin.read().splitlines()]
    nums = []
    for s in data:
        if s != "":
            nums.append(int(s))
    if not nums:
        return
    t = nums[0]
    ns = nums[1:1+t]
    max_n = max(ns) if ns else 0
    f = [0] * (max_n + 2)
    f[0] = 1
    f[1] = 1
    for k in range(2, max_n + 1):
        f[k] = (f[k-1] + f[k-2]) % MOD
    
    g = [0] * (max_n + 5)
    g[0] = 1
    if max_n >= 1: g[1] = 1
    if max_n >= 2: g[2] = 2
    if max_n >= 3: g[3] = 4
    if max_n >= 4: g[4] = 8
    for k in range(5, max_n + 1):
        g[k] = (g[k - 1] + g[k - 2] + g[k - 3] + g[k - 4]) % MOD

    out = []
    for n in ns:
        out.append(str((f[n] * g[n]) % MOD))
    print("\n".join(out))

if __name__ == "__main__":
    solve()