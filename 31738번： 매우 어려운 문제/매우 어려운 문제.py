import sys
import math

def sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(math.sqrt(n)) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    primes = [i for i, val in enumerate(is_prime) if val]
    return primes

def factorize(m, primes):
    factors = []

    for p in primes:
        if p * p > m:
            break
        if m % p == 0:
            count = 0
            while m % p == 0:
                m //= p
                count += 1
            factors.append((p, count))
    if m > 1:
        factors.append((m, 1))
    return factors

def count_p_in_factorial(n, p):
    count = 0
    power = p
    while power <= n:
        count += n // power
        if power > n // p:
            break
        power *= p
    return count

def main():
    input = sys.stdin.read
    N, M = map(int, input().strip().split())

    if N >= M:
        print(0)
        return
    
    primes = sieve(int(math.isqrt(M)) + 1)
    factors = factorize(M, primes)

    divisible = True

    for p, e in factors:
        cnt = count_p_in_factorial(N, p)
        if cnt < e:
            divisible = False
            break

    if divisible:
        print(0)
    else:
        result = 1
        for i in range(1, N + 1):
            result = (result * i) % M
            if result == 0:
                break
        print(result)

if __name__ == '__main__':
    main()