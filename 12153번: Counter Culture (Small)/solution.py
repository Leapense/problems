from collections import deque
import sys

MAX_N: int = 1_000_000

def reverse_int(value: int) -> int:
    return int(str(value)[::-1])

def build_distance_table(limit: int) -> int:
    distance: list[int] = [0] * (limit + 1)
    distance[1] = 1

    queue: deque[int] = deque([1])
    while queue:
        current: int = queue.popleft()
        current_steps: int = distance[current]

        nxt: int = current + 1
        if nxt <= limit and distance[nxt] == 0:
            distance[nxt] = current_steps + 1
            queue.append(nxt)

        rev: int = reverse_int(current)
        if rev > current and rev <= limit and distance[rev] == 0:
            distance[rev] = current_steps + 1
            queue.append(rev)

    return distance

def main() -> None:
    reader = sys.stdin.readline
    test_count: int = int(reader().strip())
    inputs: list[int] = [int(reader().strip()) for _ in range(test_count)]

    max_requested: int = max(inputs)
    dist_table: list[int] = build_distance_table(max_requested)
    out_lines: list[str] = []
    for idx, n_value in enumerate(inputs, start=1):
        out_lines.append(f"Case #{idx}: {dist_table[n_value]}")
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()