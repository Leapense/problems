from __future__ import annotations
from collections import deque
import sys
from typing import Deque, Tuple, Set, FrozenSet

Vector2 = Tuple[int, int]

# --------------------------------------------------------------------------- #
# Input
# --------------------------------------------------------------------------- #
def read_input() -> tuple[int, int, FrozenSet[Vector2]]:
    """Parse stdin and return target (x, y) and the set of puddles."""
    raw = sys.stdin.buffer.read().split()
    if len(raw) < 3:
        raise ValueError("Not enough input tokens.")
    x_target, y_target, n = map(int, raw[:3])

    puddles: Set[Vector2] = set()
    it = iter(raw[3:])
    for _ in range(n):
        ax = int(next(it))
        by = int(next(it))
        puddles.add((ax, by))
    return x_target, y_target, frozenset(puddles)


# --------------------------------------------------------------------------- #
# BFS core
# --------------------------------------------------------------------------- #
def shortest_path(
    x_goal: int,
    y_goal: int,
    forbidden: FrozenSet[Vector2],
) -> int:
    """Return the length of the shortest path or -1 (should never happen)."""
    # Bounding rectangle
    all_x = [0, x_goal, *[x for x, _ in forbidden]]
    all_y = [0, y_goal, *[y for _, y in forbidden]]
    min_x, max_x = min(all_x) - 1, max(all_x) + 1
    min_y, max_y = min(all_y) - 1, max(all_y) + 1

    width, height = max_x - min_x + 1, max_y - min_y + 1
    # visited as bytearray for memory efficiency
    visited = bytearray(width * height)

    def idx(px: int, py: int) -> int:
        """Map (grid-x, grid-y) to a flat index in [0, width*height)."""
        return (py - min_y) * width + (px - min_x)

    start: Vector2 = (0, 0)
    if start in forbidden:
        raise ValueError("Start cell is blocked – problem guarantees this never happens.")

    queue: Deque[Tuple[Vector2, int]] = deque([(start, 0)])
    visited[idx(*start)] = 1

    # 4-directional moves
    directions: tuple[Vector2, ...] = ((1, 0), (-1, 0), (0, 1), (0, -1))

    while queue:
        (cx, cy), dist = queue.popleft()
        if (cx, cy) == (x_goal, y_goal):
            return dist

        for dx, dy in directions:
            nx, ny = cx + dx, cy + dy
            if nx < min_x or nx > max_x or ny < min_y or ny > max_y:
                continue
            if (nx, ny) in forbidden:
                continue
            pos_idx = idx(nx, ny)
            if visited[pos_idx]:
                continue
            visited[pos_idx] = 1
            queue.append(((nx, ny), dist + 1))

    # According to the task this should never be triggered.
    return -1


# --------------------------------------------------------------------------- #
# Main guard
# --------------------------------------------------------------------------- #
def main() -> None:
    """Entry point."""
    x, y, puddles = read_input()
    answer = shortest_path(x, y, puddles)
    print(answer)


if __name__ == "__main__":
    main()