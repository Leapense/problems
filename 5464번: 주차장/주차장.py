def solve():
    import sys
    import heapq
    input = sys.stdin.readline
    N, M = map(int, input().split())
    rates = [int(input()) for _ in range(N)]
    weights = [int(input()) for _ in range(M)]
    events = [int(input()) for _ in range(2 * M)]
    available = list(range(N))
    heapq.heapify(available)
    parked = {}
    total = 0
    from collections import deque
    waiting = deque()
    for event in events:
        if event > 0:
            car = event - 1
            if available:
                slot = heapq.heappop(available)
                parked[car] = slot
                total += weights[car] * rates[slot]
            else:
                waiting.append(car)
        else:
            car = -event - 1
            slot = parked[car]
            if waiting:
                next_car = waiting.popleft()
                parked[next_car] = slot
                total += weights[next_car] * rates[slot]
            else:
                heapq.heappush(available, slot)
    print(total)

if __name__ == "__main__":
    solve()