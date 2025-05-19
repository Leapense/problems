import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    cards = [int(input()) for _ in range(k)]

    z = cards.count(0)
    nums = sorted({x for x in cards if x != 0})

    best = 0
    l = 0
    m = len(nums)

    for r in range(m):
        while l <= r and (nums[r] - nums[l] + 1) - (r - l + 1) > z:
            l += 1
        
        curr_len = (r - l + 1) + z

        if curr_len > n:
            curr_len = n
        
        best = max(best, curr_len)

    if m == 0:
        best = min(z, 1)

    print(best)

if __name__ == "__main__":
    main()