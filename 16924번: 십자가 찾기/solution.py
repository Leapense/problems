import sys

def read_grid() -> tuple[int, int, list[str]]:
    lines = sys.stdin.read().strip().splitlines()
    n, m = map(int, lines[0].split())
    grid = [list(row) for row in lines[1:]]
    return n, m, grid

def in_bounds(r: int, c: int, n: int, m: int) -> bool:
    return 0 <= r < n and 0 <= c < m

def max_arm_length(r: int, c: int, n: int, m: int, grid: list[list[str]]) -> int:
    if grid[r][c] != '*':
        return 0
    length = 0
    while True:
        length += 1
        for dr, dc in ((-length, 0), (length, 0), (0, -length), (0, length)):
            nr, nc = r + dr, c + dc
            if not in_bounds(nr, nc, n, m) or grid[nr][nc] != '*':
                return length - 1

def detect_crosses(n: int, m: int, grid: list[list[str]]) -> list[tuple[int, int, int]]:
    crosses = []
    for r in range(n):
        for c in range(m):
            size = max_arm_length(r, c, n, m, grid)
            if size >= 1:
                crosses.append((r, c, size))

    return crosses

def overlay(crosses: list[tuple[int, int, int]], n: int, m: int) -> list[list[str]]:
    board = [['.' for _ in range(m)] for _ in range(n)]
    for r, c, s in crosses:
        board[r][c] = '*'
        for k in range(1, s + 1):
            board[r - k][c] = '*'
            board[r + k][c] = '*'
            board[r][c - k] = '*'
            board[r][c + k] = '*'
    return board

def grid_equals(a: list[list[str]], b: list[list[str]]) -> bool:
    return all(a[r][c] == b[r][c] for r in range(len(a)) for c in range(len(a[0])))

def solve() -> None:
    n, m, original = read_grid()
    crosses = detect_crosses(n, m, original)
    reconstructed = overlay(crosses, n, m)
    if grid_equals(original, reconstructed):
        print(len(crosses))
        for r, c, s in crosses:
            print(r + 1, c + 1, s)
    else:
        print(-1)

if __name__ == "__main__":
    solve()