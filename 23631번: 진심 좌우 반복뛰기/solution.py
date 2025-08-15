import sys
from math import isqrt

def solve() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    tcase = data[0]
    out = []
    idx = 1
    for _ in range(tcase):
        n = data[idx]
        k = data[idx + 1]
        idx += 2
        s = n - 1
        if s == 0:
            out.append("0 R")
            continue
        
        q = s // k
        t = (isqrt(1 + 8 * q) - 1) // 2
        tri = t * (t + 1) // 2

        if t % 2 == 0:
            base_pos = -(t // 2) * k
            dir_right = True
        else:
            base_pos = ((t + 1) // 2) * k
            dir_right = False

        rem = s - k * tri
        x = base_pos + rem if dir_right else base_pos - rem
        out.append(f"{x} {'R' if dir_right else 'L'}")
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    solve()