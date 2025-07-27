import sys
import math

def sieve(limit: int) -> list[int]:
    is_prime = bytearray(b"\x01") * (limit + 1)
    is_prime[:2] = b"\x00\x00"
    for num in range(2, int(limit ** 0.5) + 1):
        if is_prime[num]:
            step = num * num
            is_prime[step:limit + 1:num] = b"\x00" * ((limit - step) // num + 1)
    return [i for i, v in enumerate(is_prime) if v]

def factor_primes(value: int, primes: list[int]) -> set[int]:
    factors = set()
    remaining = value
    for p in primes:
        if p * p > remaining:
            break
        if remaining % p == 0:
            factors.add(p)
            while remaining % p == 0:
                remaining //= p

    if remaining > 1:
        factors.add(remaining)
    return factors

def main() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    n = int(data[0])
    numbers = list(map(int, data[1:1 + n]))
    limit = int(math.isqrt(max(numbers)))
    primes = sieve(limit)
    sums: dict[int, int] = {}
    for v in numbers:
        if v == 1:
            continue
        for p in factor_primes(v, primes):
            sums[p] = sums.get(p, 0) + v
    print(max(sums.values(), default = 0))

if __name__ == "__main__":
    main()