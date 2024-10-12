a = int(input())
if a == 1:
    print("INF")
elif a > 1:
    count = 1 + (a - 1) // 2 + a // 2
    print(count)
else:
    print(1)
