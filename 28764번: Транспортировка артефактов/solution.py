import sys

def solve():
    data = list(map(int, sys.stdin.read().split()))
    rects = [(data[0],data[1]),(data[2],data[3]),(data[4],data[5])]
    best = 10**30
    from itertools import permutations, product
    for (w1,h1),(w2,h2),(w3,h3) in permutations(rects):
        for f1,f2,f3 in product((0,1), repeat=3):
            w1,h1 = (h1,w1) if f1 else (w1,h1)
            w2,h2 = (h2,w2) if f2 else (w2,h2)
            w3,h3 = (h3,w3) if f3 else (w3,h3)
            # 1) All side by side
            W = w1 + w2 + w3
            H = max(h1, h2, h3)
            best = min(best, W*H)
            # 2) All stacked
            W = max(w1, w2, w3)
            H = h1 + h2 + h3
            best = min(best, W*H)
            # 3) L-shape: two side by side, third below
            W = max(w1 + w2, w3)
            H = max(h1, h2) + h3
            best = min(best, W*H)
            # 4) L-shape: two stacked, third to the right
            W = max(w1, w2) + w3
            H = max(h1 + h2, h3)
            best = min(best, W*H)
    print(best)

if __name__ == "__main__":
    solve()
