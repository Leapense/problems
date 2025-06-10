#!/usr/bin/env python3
from sys import stdin

MOD = 1_000_007

def build_combinations(n_max: int, mod: int) -> list[list[int]]:
    comb: list[list[int]] = [[0] * (n_max + 1) for _ in range(n_max + 1)]
    for n in range(n_max + 1):
        comb[n][0] = comb[n][n] = 1
        for k in range(1, n):
            comb[n][k] = (comb[n - 1][k - 1] + comb[n - 1][k]) % mod
    return comb

def main() -> None:
    w, h = map(int, stdin.readline().split())
    x, y = map(int, stdin.readline().split())
    n_max = (w - 1) + (h - 1)
    comb = build_combinations(n_max, MOD)

    paths_home_to_shop = comb[(x - 1) + (y - 1)][x - 1]
    paths_shop_to_school = comb[(w - x) + (h - y)][w - x]
    
    print((paths_home_to_shop * paths_shop_to_school) % MOD)

if __name__ == "__main__":
    main()