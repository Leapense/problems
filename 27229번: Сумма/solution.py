import sys

def ceil_div(a, b):
    return -((-a) // b)

def main():
    data = sys.stdin.read().strip().split()
    n = int(data[0])
    k = int(data[1])

    T = k * (k - 1) // 2

    lo_a0 = ceil_div(n - T, k)
    hi_a0 = (n + T) // k

    def tail_bounds(v, r):
        t = r * (r + 1) // 2
        return (r * v - t, r * v + t)

    seq = [0] * k
    out = []

    def dfs(i, prev, s):
        if i == k:
            if s == n:
                parts = []
                for idx, val in enumerate(seq):
                    if idx == 0:
                        parts.append(str(val))
                    else:
                        parts.append(("+" if val >= 0 else "") + str(val))
                out.append("".join(parts))
            return

        if i == 0:
            for v in range(lo_a0, hi_a0 + 1):
                r = k - i - 1
                s2 = s + v
                if r == 0:
                    if s2 == n:
                        seq[i] = v
                        dfs(i + 1, v, s2)
                    continue
                mn, mx = tail_bounds(v, r)
                if s2 + mn <= n <= s2 + mx:
                    seq[i] = v
                    dfs(i + 1, v, s2)
        else:
            for v in (prev - 1, prev, prev + 1):
                r = k - i - 1
                s2 = s + v
                if r == 0:
                    if s2 == n:
                        seq[i] = v
                        dfs(i + 1, v, s2)
                    continue
                mn, mx = tail_bounds(v, r)
                if s2 + mn <= n <= s2 + mx:
                    seq[i] = v
                    dfs(i + 1, v, s2)

    dfs(0, 0, 0)
    sys.stdout.write("\n".join(out))
    
if __name__ == "__main__":
    main()
