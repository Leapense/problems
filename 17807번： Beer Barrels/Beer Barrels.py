MOD = 10 ** 9 + 7

def modular_factorial_and_inverse(n, mod):
    fact = [1] * (n + 1)
    for i in range(2, n + 1):
        fact[i] = fact[i - 1] * i % mod

    inv = [1] * (n + 1)
    inv[n] = pow(fact[n], mod - 2, mod)
    for i in range(n - 1, 0, -1):
        inv[i] = inv[i + 1] * (i + 1) % mod
    return fact, inv

def binomial_coefficient(n, k, fact, inv, mod):
    if k < 0 or k > n:
        return 0
    
    return fact[n] * inv[k] % mod * inv[n - k] % mod

def count_occurrences(A, B, K, C):
    if K == 0:
        return 0
    fact, inv = modular_factorial_and_inverse(K, MOD)
    result = 0
    for x in range(K + 1):
        comb = binomial_coefficient(K, x, fact, inv, MOD)
        count_c = x * (A == C) + (K - x) * (B == C)
        result = (result + comb * count_c) % MOD
    return result

A, B, K, C = map(int, input().split())
print(count_occurrences(A, B, K, C))