import sys, math

def sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False


    primes = [i for i, val in enumerate(is_prime) if val]
    return primes

def prime_factors(x, primes):
    factors = {}
    temp = x
    for p in primes:
        if p * p > temp:
            break
        if temp % p == 0:
            cnt = 0
            while temp % p == 0:
                cnt += 1
                temp //= p
            factors[p] = cnt
        if temp == 1:
            break
    if temp > 1:
        factors[temp] = 1
    return factors

def main():
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    n = int(input_data[0])
    a_list = list(map(int, input_data[1:]))

    primes = sieve(31623)

    result = 0
    for a in a_list:
        factors = prime_factors(a, primes)
        exponents = list(factors.values())
        d = exponents[0]
        for exp in exponents[1:]:
            d = math.gcd(d, exp)

        min_value = 1
        for p, exp in factors.items():
            min_value *= p ** (exp // d)
        result += min_value

    print(result)

if __name__ == "__main__":
    main()
