import sys, math

def sieve(n):
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False
    for i in range(2, int(math.isqrt(n)) + 1):
        if sieve[i]:
            sieve[i*i:n+1:i] = [False] * len(range(i*i, n+1, i))
    return sieve

def main():
    sieve_list = sieve(1000000)
    data = list(map(int, sys.stdin.read().split()))
    N = data[0]
    A = data[1:]
    primes = set(x for x in A if sieve_list[x])
    if not primes:
        print(-1)
    else:
        lcm = 1
        for p in primes:
            lcm *= p
        print(lcm)

if __name__ == "__main__":
    main()