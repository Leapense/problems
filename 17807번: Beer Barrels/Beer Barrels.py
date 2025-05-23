MOD = 10 ** 9 + 7
A, B, K, C = map(int, input().split())
if K == 0:
    print(0)
elif A == B:
    print(K % MOD if C == A else 0)
else:
    if C == A or C == B:
        pow2 = pow(2, K - 1, MOD)
        total = (K * pow2) % MOD
        print(total)
    else:
        print(0)