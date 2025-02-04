n = int(input())
if n < 7:
    print(0)
else:
    S = n * (n + 1) // 2
    mod8 = n % 8
    if mod8 == 0 or mod8 == 7:
        r = 0
    elif mod8 == 1 or mod8 == 6:
        r = 1
    elif mod8 == 2 or mod8 == 5:
        r = 3
    else:
        r = 6
    print(S - r)