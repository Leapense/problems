import sys
import random

MAX_N = 10
MAX_M = 10
X_MAX_LO = 10
X_MAX_HI = 1000

def rand_real(lo: float, hi: float, decimals: int = 2) -> float:
    return round(random.uniform(lo, hi), decimals)

def make_endpoints(k: int, L: int) -> list[int]:
    if k == 1:
        return [L]
    bodies = random.sample(range(1, L), k - 1)
    bodies.sort()
    return bodies + [L]

def main() -> None:
    if len(sys.argv) > 1:
        random.seed(int(sys.argv[1]))
    
    n = random.randint(1, MAX_N)
    m = random.randint(1, MAX_M)
    L = random.randint(X_MAX_LO, X_MAX_HI)

    f_ends = make_endpoints(n, L)
    f_values = [rand_real(-1000, 1000) for _ in range(n)]

    g_ends = make_endpoints(m, L)
    a_vals = [rand_real(-1, 1, 6) for _ in range(m)]
    b_vals = [rand_real(-10, 10, 4) for _ in range(m)]
    c_vals = [rand_real(-100, 100) for _ in range(m)]

    out_lines = []
    out_lines.append(str(n))
    out_lines.extend(f"{x} {y}" for x, y in zip(f_ends, f_values))
    out_lines.append(str(m))
    out_lines.extend(f"{x} {a} {b} {c}" for x, a, b, c in zip(g_ends, a_vals, b_vals, c_vals))

    sys.stdout.write("\n".join(out_lines) + "\n")

if __name__ == "__main__":
    main()