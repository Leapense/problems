import sys
from collections import deque

def solve():
    input = sys.stdin.readline
    n, m = map(int, input().split())
    start_row, start_col = map(int, input().split())
    enemy_positions = [tuple(map(int, input().split())) for _ in range(m)]
    distances = [[-1] * (n + 1) for _ in range(n + 1)]
    queue = deque()
    distances[start_row][start_col] = 0
    queue.append((start_row, start_col))
    moves = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]

    while queue:
        row, col = queue.popleft()
        for dr, dc in moves:
            new_row, new_col = row + dr, col + dc
            if 1 <= new_row <= n and 1 <= new_col <= n and distances[new_row][new_col] < 0:
                distances[new_row][new_col] = distances[row][col] + 1
                queue.append((new_row, new_col))
    print(' '.join(str(distances[r][c]) for r, c in enemy_positions))

if __name__ == "__main__":
    solve()