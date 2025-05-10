import sys

def solve_shortcuts():
    """
    Solves the shortcuts problem using dynamic programming.
    Reads input from stdin and prints the result to stdout.
    """
    line1 = sys.stdin.readline().split()
    N = int(line1[0])
    D = int(line1[1])

    shortcuts = []
    for _ in range(N):
        start, end, length = map(int, sys.stdin.readline().split())
        if end <= D and length < (end - start):
            shortcuts.append((start, end, length))

    dp = [float('inf')] * (D + 1)
    dp[0] = 0

    for i in range(D + 1):
        if i > 0:
            dp[i] = min(dp[i], dp[i - 1] + 1)

        for start, end, length in shortcuts:
            if end == i:
                if dp[start] != float('inf'):
                    dp[i] = min(dp[i], dp[start] + length)

    print(dp[D])

if __name__ == "__main__":
    solve_shortcuts()