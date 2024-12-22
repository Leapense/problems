n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

possible = []
max_k = (m - n) // (n - 1) if n > 1 else m - n

for k in range(0, max_k + 1):
    required_length = n + (n - 1) * k
    if required_length > m:
        continue
    for p in range(0, m - required_length + 1):
        match = True
        for i in range(n):
            if b[p + i * (k + 1)] != a[i]:
                match = False
                break
        if match:
            possible.append(k)
            break
if not possible:
    print(-1)
else:
    print(min(possible), max(possible))