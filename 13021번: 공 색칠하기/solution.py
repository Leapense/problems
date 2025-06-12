import sys
import math

def main():
    data = sys.stdin.read().strip().split()
    n, m = map(int, data[:2])
    intervals = [tuple(map(int, data[i:i+2])) for i in range(2, 2+2*m, 2)]
    covered = [False] * (n + 1)
    useful_ops = 0

    for L, R in reversed(intervals):
        has_uncovered = False
        for pos in range(L, R + 1):
            if not covered[pos]:
                has_uncovered = True
                break
        if has_uncovered:
            useful_ops += 1

        for pos in range(L, R + 1):
            covered[pos] = True
        
    result = 1 << useful_ops
    sys.stdout.write(str(result))

if __name__ == "__main__":
    main()