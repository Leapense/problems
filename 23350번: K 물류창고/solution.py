import sys
from collections import deque

def compute_total_lift_weight(n, m, items):
    rail = deque(items)
    counts = [0] * (m + 1)
    for p, _ in items:
        counts[p] += 1

    target = m
    total = 0
    stack = []

    while rail:
        while target > 0 and counts[target] == 0:
            target -= 1
            stack = []
        if target == 0:
            break

        p, w = rail[0]
        if p == target:
            moved = []
            while stack and stack[-1] < w:
                top = stack.pop()
                total += top
                moved.append(top)
            total += w
            stack.append(w)
            for x in reversed(moved):
                total += x
                stack.append(x)
            counts[target] -= 1
            rail.popleft()
        else:
            p, w = rail.popleft()
            total += w
            rail.append((p, w))
    return total

def main():
    data = sys.stdin.read().strip().split()
    it = iter(data)
    n = int(next(it))
    m = int(next(it))
    items = []
    for _ in range(n):
        p = int(next(it))
        w = int(next(it))
        items.append((p, w))
    print(compute_total_lift_weight(n, m, items))

if __name__ == "__main__":
    main()