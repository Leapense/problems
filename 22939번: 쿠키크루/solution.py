import sys
from itertools import permutations

def read_input():
    data = sys.stdin.read().strip().splitlines()
    n = int(data[0].strip())
    grid = [list(line.rstrip()) for line in data[1:1+n]]
    return n, grid

def dist(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def solve():
    _, grid = read_input()
    pos_h = None
    pos_hash = None
    tops = {"W": [], "C": [], "B": [], "J": []}
    for i, row in enumerate(grid):
        for j, c in enumerate(row):
            if c == "H":
                pos_h = (i, j)
            elif c == "#":
                pos_hash = (i, j)
            elif c in tops:
                tops[c].append((i, j))
    order = ["J", "C", "B", "W"]
    label = {"J": "Assassin", "C": "Healer", "B": "Mage", "W": "Tanker"}
    best_cost = None
    best_key = None
    for k in order:
        pts = tops[k]
        cur = None
        for p1, p2, p3 in permutations(pts, 3):
            val = dist(pos_h, p1) + dist(p1, p2) + dist(p2, p3) + dist (p3, pos_hash)
            if cur is None or val < cur:
                cur = val
        if best_cost is None or cur < best_cost or (cur == best_cost and order.index(k) < order.index(best_key)):
            best_cost = cur
            best_key = k
    print(label[best_key])

if __name__ == "__main__":
    solve()