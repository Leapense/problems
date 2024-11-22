import sys
from math import gcd

def main():
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])
    x_list = list(map(int, data[1:N+1]))

    primes = [
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
        31, 37, 41, 43, 47
    ]

    def factorize(n):
        factors = {}
        for p in primes:
            if p * p > n:
                break
            while n % p == 0:
                factors[p] = factors.get(p, 0) + 1
                n //= p
        if n > 1:
            factors[n] = factors.get(n, 0) + 1
        return factors

    factor_cache = {}
    for num in range(2, 51):
        factor_cache[num] = factorize(num)

    max_exponents = {}

    for x in x_list:
        val = 2 * x
        factors = factor_cache.get(val, {})
        for prime, exp in factors.items():
            if prime in max_exponents:
                if exp > max_exponents[prime]:
                    max_exponents[prime] = exp
            else:
                max_exponents[prime] = exp

    lcm = 1
    for prime, exp in max_exponents.items():
        lcm *= prime ** exp
    
    print(lcm)

if __name__ == '__main__':
    main()