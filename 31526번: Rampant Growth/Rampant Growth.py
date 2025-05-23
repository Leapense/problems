def count_ways(r, c):
    MOD = 998244353
    if c == 1:
        return r % MOD
    if r == 1:
        return 0
    return (r * pow(r - 1, c - 1, MOD)) % MOD

# 입력 처리
r, c = map(int, input().strip().split())
print(count_ways(r, c))
