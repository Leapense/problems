a, b, c = map(int, input().split())

if a == 0:
    a = c ** 2 - b
    print(a)
elif b == 0:
    b = c ** 2 - a
    print(b)
elif c == 0:
    c = int((a + b) ** 0.5)
    print(c)