n = int(input())
if n < 7:
    print(0)
else:
    S = n * (n + 1) // 2
    print(S - (S % 4))