import sys
import math

def norm_edge(p, q):
    return (p, q) if p <= q else (q, p)
def length(p, q):
    return math.hypot(p[0] - q[0], p[1] - q[1])
def main():
    it = iter(sys.stdin.read().strip().split())
    try:
        m = int(next(it))
    except StopIteration:
        return
    edges = []
    freq = {}
    for _ in range(m):
        x1 = int(next(it)); y1 = int(next(it))
        x2 = int(next(it)); y2 = int(next(it))
        x3 = int(next(it)); y3 = int(next(it))
        pts = [(x1,y1), (x2,y2), (x3,y3)]
        tri_edges = [(pts[0],pts[1]),(pts[1],pts[2]),(pts[2],pts[0])]
        for a, b in tri_edges:
            k = norm_edge(a, b)
            edges.append((k, a, b))
            freq[k] = freq.get(k, 0) + 1

    total = 0.0
    seen = set()
    for k, a, b in edges:
        if k in seen:
            continue
        seen.add(k)
        if freq[k] == 1:
            total += length(a, b)

    print("{:.10f}".format(total))

if __name__ == "__main__":
    main()