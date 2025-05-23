import sys
input = sys.stdin.readline

mod = 10**9 + 7

N = int(input())
h = list(map(int, input().split()))

if N == 1:
    print(h[0] % mod)
else:
    ans = 1
    ans = (ans * min(h[0], h[1])) % mod
    for i in range(1, N-1):
        ans = (ans * min(min(h[i-1], h[i]), min(h[i], h[i+1]))) % mod
    ans = (ans * min(h[N-2], h[N-1])) % mod
    print(ans % mod)