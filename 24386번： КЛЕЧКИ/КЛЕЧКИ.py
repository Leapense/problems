def solve():
    l = [0] * 101
    c = 0
    t = []

    for i in range(3):
        a, b = map(int, input().split())
        f = False
        for j in range(a, b + 1):
            if l[j]:
                f = True
            l[j] = 1
        if not f:
            c += 1
        t.append(b-a)
    print(c)
    t.sort()
    print(t[0], t[-1])

solve()