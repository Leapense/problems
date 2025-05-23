def solve():
    import sys
    input = sys.stdin.readline
    T = int(input().strip())
    for _ in range(T):
        n = int(input().strip())
        freq = [0] * 50
        for _ in range(n):
            nums = list(map(int, input().split()))
            for x in nums:
                freq[x] += 1

        def custom_rank(x):
            return 0 if x == 7 else x
        
        candidates = list(range(1, 50))
        candidates.sort(key=lambda x: (-freq[x], custom_rank(x)))

        chosen = candidates[:6]

        chosen.sort()
        print(' '.join(map(str, chosen)))

if __name__ == '__main__':
    solve()