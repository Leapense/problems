import sys

def solve():
    it = iter(sys.stdin.read().strip().split())
    t = int(next(it))
    out_lines = []
    for case_idx in range(1, t + 1):
        n = int(next(it)); x = int(next(it)); y = int(next(it))
        s = n * (n + 1) // 2
        denom = x + y
        if s % denom != 0:
            out_lines.append(f"Case #{case_idx}: IMPOSSIBLE")
            continue
        unit = s // denom
        target = unit * x
        chosen = []
        for v in range(n, 0, -1):
            if target >= v:
                chosen.append(v)
                target -= v
                if target == 0:
                    break
        if target != 0:
            out_lines.append(f"Case #{case_idx}: IMPOSSIBLE")
            continue
        chosen.reverse()
        out_lines.append(f"Case #{case_idx}: POSSIBLE")
        out_lines.append(str(len(chosen)))
        out_lines.append(" ".join(map(str, chosen)))
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()