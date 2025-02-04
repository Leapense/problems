n = int(input())
T = n * (n + 1) // 2
if n < 4:
    print(0)
elif n % 4 == 0 or n % 4 == 3:
    print(T)
else:
    print(0)