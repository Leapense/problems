import sys
import heapq
from typing import List, Tuple

class DisjointSet:
    def __init__(self, n: int) -> None:
        self.parent: List[int] = list(range(n + 2))

    def find(self, x: int) -> int:
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x
    
    def mark_full(self, x: int) -> None:
        self.parent[x] = self.find(x + 1)

def solve_case(n: int, flow: float, caps: List[float]) -> Tuple[float, float]:
    remaining = caps[:]
    rate = [flow] * n
    last_upd = [0.0] * n
    finish = [c / flow for c in remaining]
    filled = [False] * n
    heap: List[Tuple[float, int]] = [(finish[i], i) for i in range(n)]
    heapq.heapify(heap)

    dsu = DisjointSet(n)
    time_lowest_overflow = -1.0
    last_event_time = 0.0

    while heap:
        event_time, idx = heapq.heappop(heap)
        if filled[idx]:
            continue
        if abs(event_time - finish[idx]) > 1e-12:
            continue

        last_event_time = event_time
        filled[idx] = True

        if idx == n - 1 and time_lowest_overflow < 0:
            time_lowest_overflow = event_time

        next_idx = dsu.find(idx + 1)
        dsu.mark_full(idx)

        if next_idx < n:
            elapsed = event_time - last_upd[next_idx]
            remaining[next_idx] -= rate[next_idx] * elapsed
            last_upd[next_idx] = event_time

            rate[next_idx] += rate[idx]
            finish[next_idx] = event_time + remaining[next_idx] / rate[next_idx]
            heapq.heappush(heap, (finish[next_idx], next_idx))

    return time_lowest_overflow, last_event_time

def main() -> None:
    data = sys.stdin.read().strip().split()
    it = iter(data)

    out_lines: List[str] = []
    for n_str, f_str in zip(it, it):
        n = int(n_str)
        flow = float(f_str)
        caps = [float(next(it)) for _ in range(n)]
        t_lowest, t_total = solve_case(n, flow, caps)
        out_lines.append(f"{t_lowest:.10f} {t_total:.10f}")

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()