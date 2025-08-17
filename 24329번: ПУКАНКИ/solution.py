import sys

def min_max_segment_sum(pops, k):
    left = max(pops)
    right = sum(pops)
    while left < right:
        mid = (left + right) // 2
        parts = 1
        current = 0
        for v in pops:
            if current + v <= mid:
                current += v
            else:
                parts += 1
                current = v
        if parts <= k:
            right = mid
        else:
            left = mid + 1
    return left

def solve():
    data = list(map(int, sys.stdin.read().split()))
    n, k, s = data[0], data[1], data[2]
    pops = data[3:3+n]
    best = min_max_segment_sum(pops, k)
    result = (best + s - 1) // s
    print (result)

if __name__ == '__main__':
    solve()