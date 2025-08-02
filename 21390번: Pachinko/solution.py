import sys
from functools import lru_cache

def main() -> None:
    data = iter(sys.stdin.read().split())
    t = int(next(data))
    results = []
    for _ in range(t):
        h = int(next(data))
        w = int(next(data))
        board = [list(next(data)) for _ in range(h)]

        @lru_cache(None)
        def expect(r: int, c: int) -> float:
            if r >= h:
                return 0.0
            cell = board[r][c]
            if cell == '.':
                return expect(r + 1, c)
            if cell.isdigit():
                return float(int(cell))
            return 0.5 * expect(r + 1, c - 1) + 0.5 * expect(r + 1, c + 1)
        best = 0.0
        for col in range(w):
            best = max(best, expect(0, col))
        results.append(f'{best:.6f}')
    sys.stdout.write('\n'.join(results))

if __name__ == "__main__":
    main()