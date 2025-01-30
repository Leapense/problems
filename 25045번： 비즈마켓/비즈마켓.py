n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort(reverse=True)
b.sort(reverse=True)

total = 0
i = 0

for payment in b:
    if i < n and a[i] >= payment:
        total += a[i] - payment
        i += 1

print(total)
