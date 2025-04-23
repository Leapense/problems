import sys
import math

def solve():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    s = int(data[0])
    if s == 0:
        print(0)
        return
    
    k1 = math.isqrt(s)
    k2 = k1 + 1

    f1 = k1 + (s + k1 - 1) // k1 if k1 >= 1 else 10 ** 30
    f2 = k2 + (s + k2 - 1) // k2
    ans = f1 if f1 < f2 else f2
    print(ans)

if __name__ == "__main__":
    solve()