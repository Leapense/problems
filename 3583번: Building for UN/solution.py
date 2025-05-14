import sys
import string

SYMS = list(string.ascii_uppercase + string.ascii_lowercase)

def idx2c(idx: int) -> str:
    return SYMS[idx]

def build(n: int) -> tuple[str, list[str], list[str]]:
    h, w, l = 2, n, n

    floor0 = []
    for i in range(n):
        ch = idx2c(i)
        floor0.append(ch * n)

    col_string = ''.join(idx2c(j) for j in range(n))
    floor1 = [col_string for _ in range(n)]

    return f"{h} {w} {l}", floor0, floor1

def solve() -> None:
    data = sys.stdin.read().strip()
    if not data:
        return
    
    n = int(data)
    header, f0, f1 = build(n)

    out_lines = [header, *f0, "", *f1]
    sys.stdout.write("\n".join(out_lines) + "\n")

if __name__ == "__main__":
    solve()