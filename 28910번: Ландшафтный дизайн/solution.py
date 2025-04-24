import sys

def main() -> None:
    rd = sys.stdin.readline
    n, k = map(int, rd().split())
    a = list(map(int, rd().split()))
    best = None
    for s in (1, -1):
        if k == 0 and s == -1:
            continue
        arr = [v if i % 2 == 0 else v - s * k for i, v in enumerate(a)]
        arr.sort()
        m = arr[n // 2]
        cost = sum(abs(v - m) for v in arr)
        if best is None or cost < best:
            best = cost
    print(best)

if __name__ == "__main__":
    main()
