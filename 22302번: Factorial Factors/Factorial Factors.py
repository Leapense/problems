import sys, math

def sieve(n):
    is_prime = [True] * (n+1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(math.sqrt(n))+1):
        if is_prime[i]:
            for j in range(i*i, n+1, i):
                is_prime[j] = False
    primes = [i for i, val in enumerate(is_prime) if val]
    return primes

primes = sieve(100000)
C = int(sys.stdin.readline())
for _ in range(C):
    N = int(sys.stdin.readline())
    D = 0; T = 0
    for p in primes:
        if p > N: break
        D += 1
        e = 0
        x = p
        while x <= N:
            e += N // x
            x *= p
        T += e
    print(D, T)