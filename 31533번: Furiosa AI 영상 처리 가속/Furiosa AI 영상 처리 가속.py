a = float(input())
m, n = map(float, input().split())

if m > n:
    m, n = n, m

m /= a

if m * 2 < n:
    print(m * 2)
else:
    print(n)