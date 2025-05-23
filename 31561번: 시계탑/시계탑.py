M = int(input().strip())

if 0 <= M < 30:
    T = M / 2
else:
    T = 15 + (M - 30) * 1.5

print(T)