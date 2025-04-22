import sys
from math import comb

def main():
    data = sys.stdin.read().split()
    it = iter(data)
    t = int(next(it))
    out = []
    for _ in range(t):
        p = int(next(it))
        best_num = 0
        best_den = 1
        winners = []
        for idx in range(1, p + 1):
            n = int(next(it)); m = int(next(it)); k = int(next(it))
            num = 0
            for j in range(k, m + 1):
                num += comb(m, j) * comb(n - m, m - j)
            den = comb(n, m)
            if num * best_den > best_num * den:
                best_num, best_den = num, den
                winners = [idx]
            elif num * best_den == best_num * den:
                winners.append(idx)
        out.append(" ".join(map(str, winners)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
