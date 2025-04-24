import sys
def main():
    data = sys.stdin.read().split()
    it = iter(data)
    n = int(next(it))
    R = int(next(it))
    a = [int(next(it)) for _ in range(n)]
    intervals = []
    for i, ai in enumerate(a):
        l = ai - R
        r = ai + R
        intervals.append((r, l, i))
    intervals.sort()
    b = [0] * n
    t = -10**30
    distinct = 0
    leftovers = []
    for r, l, idx in intervals:
        if t < l:
            t = l
        if t <= r:
            b[idx] = t
            distinct += 1
            t += 1
        else:
            leftovers.append((l, idx))
    for l, idx in leftovers:
        b[idx] = l
    out = [str(distinct), "\n", " ".join(str(x) for x in b)]
    sys.stdout.write("".join(out))

if __name__ == "__main__":
    main()
