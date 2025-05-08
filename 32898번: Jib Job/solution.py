import sys, math

def solve(data: str) -> str:
    it = iter(data.strip().splitlines())
    n = int(next(it))
    cranes = [tuple(map(int, next(it).split())) for _ in range(n)]
    res = []
    for xi, yi, hi in cranes:
        r = hi
        for xj, yj, hj in cranes:
            if hj > hi:
                dx = xi - xj
                dy = yi - yj
                r = min(r, math.isqrt(dx * dx + dy * dy))
                if r == 0:
                    break
        if r == 0:
            r = 1
        res.append(r)
    return '\n'.join(map(str, res))

if __name__ == "__main__":
    print(solve(sys.stdin.read()))