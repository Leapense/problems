n = int(input())
ans = 1

if n % 2 == 1:
    print("0")
else:
    n //= 2
    while n != 0:
        ans *= 2
        n -= 1
    print(ans)