import sys
sys.setrecursionlimit(10000)

def solve():
    input = sys.stdin.readline
    N, K = map(int, input().split())
    memo = {}
    def f(n):
        if n in memo:
            return memo[n]
        if n <= K or (n + K) % 2:
            memo[n] = 1
            return 1
        a = (n + K) // 2
        b = (n - K) // 2
        memo[n] = f(a) + f(b)
        return memo[n]
    print(f(N))
if __name__ == "__main__":
    solve()