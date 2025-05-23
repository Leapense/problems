def prime_factors(n):
    factors = set()
    i = 2
    while i * i <= n:
        while n % i == 0:
            factors.add(i)
            n //= i
        i += 1

    if n > 1:
        factors.add(n)
    return factors

t = int(input().strip())
for _ in range(t):
    N = int(input().strip())
    if N == 1:
        print(1)
        continue
    else:
        factors = prime_factors(N)
        k = len(factors)
        print(2 ** (k - 1))