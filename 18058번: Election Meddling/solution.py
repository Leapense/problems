import sys
import heapq

def calc_cost(v1, opponents):
    heap = [-v for v in opponents]
    heapq.heapify(heap)
    cost = 0
    while heap and v1 <= -heap[0]:
        top = heapq.heappop(heap) + 1
        v1 += 1
        cost += 1
        heapq.heappush(heap, top)
    return cost

def main():
    data = sys.stdin.readline().split()
    w, p = map(int, data)
    costs = []
    win0 = 0
    for _ in range(w):
        votes = list(map(int, sys.stdin.readline().split()))
        v1 = votes[0]
        opponents = votes[1:]
        max_other = max(opponents)
        if v1 > max_other:
            win0 += 1
        else:
            costs.append(calc_cost(v1, opponents))
    need = w // 2 + 1
    remaining = need - win0
    if remaining <= 0:
        print(0)
        return
    costs.sort()
    print(sum(costs[:remaining]))

if __name__ == "__main__":
    main()