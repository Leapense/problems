import sys

def compute_max_energy(n: int, k: int, values: list[int]) -> int:
    prefix: list[int] = [0] * (n + 1)
    for i in range(n):
        prefix[i + 1] = prefix[i] + values[i]

    next_idx: list[int] = [-1] * n
    surplus: list[int] = [0] * n
    for i in range(n):
        for j in range(i, n):
            if prefix[j + 1] - prefix[i] >= k:
                next_idx[i] = j
                surplus[i] = prefix[j + 1] - prefix[i] - k
                break

    dp: list[int] = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        best = dp[i + 1]
        if next_idx[i] != -1:
            best = max(best, surplus[i] + dp[next_idx[i] + 1])
        dp[i] = best
    return dp[0]

def main() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    
    n = int(data[0])
    k = int(data[1])
    values = list(map(int, data[2:2+n]))
    print(compute_max_energy(n, k, values))

if __name__ == '__main__':
    main()