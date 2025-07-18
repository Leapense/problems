import sys
from typing import List

def mobius_sieve(limit: int) -> List[int]:
    mu = [1] * (limit + 1)
    is_prime = [True] * (limit + 1)
    mu[0] = 0
    for i in range(2, limit + 1):
        if is_prime[i]:
            for j in range(i, limit + 1, i):
                is_prime[j] = False
                mu[j] *= -1
            sq = i * i
            for j in range(sq, limit + 1, sq):
                mu[j] = 0
    return mu

def jordan_totient(n: int, k: int, mu: List[int]) -> int:
    total = 0
    for d in range(1, n + 1):
        total += mu[d] * (n // d) ** k
    return total

def visible_points(n: int, mu: List[int]) -> int:
    j2 = jordan_totient(n, 2, mu)
    j3 = jordan_totient(n, 3, mu)
    return j3 + 3 * j2 + 3

def main() -> None:
    data = list(map(int, sys.stdin.read().split()))
    t = data[0]
    ns = data[1:]
    max_n = max(ns)
    mu = mobius_sieve(max_n)
    results = [str(visible_points(n, mu)) for n in ns]
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    main()
