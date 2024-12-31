import sys
import itertools

def main():
    N, *rest = map(int, sys.stdin.read().split())
    points = [tuple(rest[i*2:(i+1)*2]) for i in range(N)]
    min_L = float('inf')
    def compute_L(subset):
        if len(subset) >=1:
            min_x = min(p[0] for p in subset)
            max_x = max(p[0] for p in subset)
            min_y = min(p[1] for p in subset)
            max_y = max(p[1] for p in subset)
            return max(max_x - min_x, max_y - min_y) +2
        else:
            return 2
    subsets = [points]
    for i in range(N):
        subsets.append(points[:i] + points[i+1:])
    for i, j in itertools.combinations(range(N),2):
        subsets.append(points[:i] + points[i+1:j] + points[j+1:])
    for subset in subsets:
        L = compute_L(subset)
        min_L = min(min_L, L)
    print(min_L * min_L)

if __name__ == "__main__":
    main()
