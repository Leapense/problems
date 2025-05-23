def solve():
    import sys
    input = sys.stdin.readline

    n, k = map(int, input().split())

    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    count = 0
    for p in range(2, n - k + 1):
        if is_prime[p] and (p + k) <= n and is_prime[p + k]:
            count += 1

    sys.stdout.write(str(count))

if __name__ == "__main__":
    solve()