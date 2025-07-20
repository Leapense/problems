import sys

def main():
    data = sys.stdin.readline
    t = int(data())
    out = []
    INF = 10 ** 30
    for _ in range(t):
        n = int(data())
        arr = list(map(int, data().split()))
        min_pref = [0, INF]
        total = 0
        best = -INF
        for i, x in enumerate(arr, start=1):
            total += x
            p = i & 1
            candidate = total - min_pref[1 - p]
            if candidate > best:
                best = candidate
            if total < min_pref[p]:
                min_pref[p] = total

        out.append(str(best))

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()