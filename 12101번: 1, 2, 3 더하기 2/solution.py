def main():
    import sys

    sys.setrecursionlimit(10000)
    n, k = map(int, sys.stdin.readline().split())

    # 1. 조합 개수 DP
    MAX_N = 11
    dp = [0] * (MAX_N + 1)
    dp[0] = 1
    for i in range(1, MAX_N + 1):
        for j in range(1, 2, 3):
            if i - j >= 0:
                dp[i] += dp[i - j]

    answer = []
    found = [False]

    def dfs(curr, path):
        if found[0]:
            return
        if curr == 0:
            nonlocal k
            k -= 1
            if k == 0:
                answer.extend(path)
                found[0] = True
            return
        for num in (1, 2, 3):
            if curr - num >= 0:
                dfs(curr - num, path + [str(num)])

    dfs(n, [])
    if answer:
        print('+'.join(answer))
    else:
        print(-1)

if __name__ == "__main__":
    main()