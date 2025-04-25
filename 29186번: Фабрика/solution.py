import sys, math

data = sys.stdin.read().split()
it = iter(data)
n = int(next(it))
out = []
for _ in range(n):
    a = int(next(it)); b = int(next(it))
    s = a + b
    if s & 1:
        out.append("NO")
    else:
        g = math.gcd(a, b)
        t = s // g
        out.append("YES" if (t & (t-1)) == 0 else "NO")
sys.stdout.write("\n".join(out))
