import sys
from functools import lru_cache
import math

_prime_cache = {}

def is_prime(n: int) -> bool:
    if n in _prime_cache:
        return _prime_cache[n]
    
    if n < 2:
        _prime_cache[n] = False
        return False
    if n in (2, 3):
        _prime_cache[n] = True
        return True
    if n % 2 == 0 or n % 3 == 0:
        _prime_cache[n] = False
        return False
    
    limit = int(math.isqrt(n))
    i = 5
    step = 2
    while i <= limit:
        if n % i == 0:
            _prime_cache[n] = False
            return False
        i += step
        step = 6 - step

    _prime_cache[n] = True
    return True

@lru_cache(maxsize=None)
def best(s: str) -> int:
    ans = 1
    L = len(s)
    for idx in range(L):
        t = (s[:idx] + s[idx + 1:]).lstrip("0")
        if not t:
            continue
        if is_prime(int(t)):
            ans = max(ans, 1 + best(t))
    return ans

def main() -> None:
    data = sys.stdin.readline().strip()
    if not data:
        return
    if not is_prime(int(data)):
        print(0)
    else:
        print(best(data))

if __name__ == "__main__":
    main()