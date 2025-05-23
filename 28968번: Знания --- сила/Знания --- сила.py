import sys
input_data = sys.stdin.read().split()

n = int(input_data[0])
k = int(input_data[1])
mod = 10 ** 9 + 7

if k == 0:
    print(n % mod)
    exit()

a0, a1 = 1, 2
if k == 1:
    print((n * a1) % mod)
    exit()

for _ in range(2, k + 1):
    a0, a1 = a1, (3 * a1 - a0) % mod

print((n * a1) % mod)