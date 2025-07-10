import sys
import bisect

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    k = int(data[1])
    levels = list(map(int, data[2:2+n]))
    levels.sort()
    prefix = [0] * (n + 1)
    for i in range(n):
        prefix[i + 1] = prefix[i] + levels[i]

    low = levels[0]
    high = low + k + 1
    while low < high:
        mid = (low + high) // 2
        idx = bisect.bisect_left(levels, mid)
        cost = mid * idx - prefix[idx]
        if cost <= k:
            low = mid + 1
        else:
            high = mid
    print(low - 1)

if __name__ == "__main__":
    main()