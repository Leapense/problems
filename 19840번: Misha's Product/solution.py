import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7
n = int(input().strip())
arr = list(map(int, input().split()))
pow10 = [1] * 11
for i in range(1, 11):
    pow10[i] = pow10[i - 1] * 10 % MOD

lengths = [len(str(x)) for x in arr]
ten_pows = [pow10[l] for l in lengths]
sum_ten_pows = sum(ten_pows) % MOD
sum_arr = sum(arr) % MOD
res = 0
for a, tp in zip(arr, ten_pows):
    res = (res + a * ((sum_ten_pows - tp) % MOD)) % MOD
res = (res + sum_arr * (n - 1)) % MOD
print(res)