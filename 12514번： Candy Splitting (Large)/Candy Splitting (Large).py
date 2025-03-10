def solve():
    import sys
    input = sys.stdin.readline
    T = int(input().strip())
    for t in range(1, T+1):
        n = int(input().strip())
        candies = list(map(int, input().split()))
        xor_total = 0
        for candy in candies:
            xor_total ^= candy
        if xor_total != 0:
            print("Case #{}: NO".format(t))
        else:
            total_sum = sum(candies)
            print("Case #{}: {}".format(t, total_sum - min(candies)))

if __name__ == '__main__':
    solve()
