import sys
import math
from functools import lru_cache

def main():
    data = sys.stdin.read().strip()
    if not data:
        return
    
    n = int(data)

    if n < 7:
        full = math.factorial(n)
        s = str(full).rstrip('0')
        sys.stdout.write(s)
        return
    
    def count_factor(n_val, p):
        cnt = 0
        power = p
        while power <= n_val:
            cnt += n_val // power
            power *= p
        return cnt
    
    E5 = count_factor(n, 5)
    MOD125 = 125

    g = [1] * MOD125
    for i in range(1, MOD125):
        if i % 5 == 0:
            g[i] = g[i - 1]
        else:
            g[i] = (g[i - 1] * i) % MOD125

    B = g[124]

    sys.setrecursionlimit(10_000_000)

    @lru_cache(maxsize=None)
    def T_mod125(x):
        if x == 0:
            return 1
        
        q, r = divmod(x, MOD125)
        part_recursive = T_mod125(x // 5)
        part_block = pow(B, q, MOD125)
        part_remainder = g[r]
        return (part_recursive * part_block * part_remainder) % MOD125
    
    pow2_e5_mod125 = pow(2, E5, MOD125)
    inv2e5_mod125 = pow(pow2_e5_mod125, -1, MOD125)

    Tn = T_mod125(n)
    Y = (Tn * inv2e5_mod125) % MOD125
    mod8 = 8
    q_mod8 = ((-Y) * 5) % mod8
    X_mod1000 = (125 * q_mod8 + Y) % 1000

    sys.stdout.write(str(X_mod1000).zfill(3))

if __name__ == "__main__":
    main()