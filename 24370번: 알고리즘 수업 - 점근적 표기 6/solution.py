def solve():
    a2, a1, a0 = map(int, input().split())
    c1, c2 = map(int, input().split())
    n0 = int(input())

    def f(x):
        return a2 * (x ** 2) + a1 * x + a0
    def g(x):
        return c1 * (x ** 2)
    def h(x):
        return c2 * (x ** 2)
    
    D1 = (a1 ** 2) - 4 * a0 * (a2 - c1)
    D2 = (a1 ** 2) - 4 * a0 * (a2 - c2)
    cond1 = False

    if a2 == c1:
        if a1 == a0 == 0:
            cond1 = True
        else:
            if a1 >= 0:
                cond1 = True
            elif a1 == 0:
                if a0 >= 0:
                    cond1 = True
                else:
                    cond1 = False
            else:
                cond1 = False
    elif a2 == 0:
        if f(n0) >= g(n0):
            cond1 = True
        else:
            cond1 = False
    elif a2 < c1:
        cond1 = False
    elif D1 < 0:
        if f(n0) >= g(n0):
            cond1 = True
        else:
            cond1 = False
    elif D1 == 0:
        if f(n0) >= g(n0):
            cond1 = True
        else:
            cond1 = False
    else:
        x1 = (a1 + D1 ** (1 / 2)) / (2 * (c1 - a2))
        x2 = (a1 - D1 ** (1 / 2)) / (2 * (c1 - a2))
        x = max(x1, x2)
        if a2 > 0:
            vertex = a1 / (2 * (c1 - a2))
            if f(vertex) > g(vertex):
                cond1 = True
            else:
                if x <= n0:
                    cond1 = True
                else:
                    cond1 = False
        else:
            if n0 <= x:
                cond1 = False
            else:
                cond1 = True
    cond2 = False
    if a2 == c2:
        if a1 == a0 == 0:
            cond2 = True
        else:
            if a1 > 0:
                cond2 = False
            elif a1 == 0:
                if a0 > 0:
                    cond2 = False
                else:
                    cond2 = True
            else:
                cond2 = True
    elif a2 == 0:
        if f(n0) <= h(n0):
            cond2 = True
        else:
            cond2 = False
    elif a2 > c2:
        cond2 = False
    elif D2 < 0:
        if f(n0) <= h(n0):
            cond2 = True
        else:
            cond2 = False
    elif D2 == 0:
        if f(n0) <= h(n0):
            cond2 = True
        else:
            cond2 = False
    else:
        x = (a1 + D2 ** (1 / 2)) / (2 * (c2 - a2))
        if a2 > 0:
            vertex = a1 / (2 * (c2 - a2))
            if f(vertex) < h(vertex):
                cond2 = False
            else:
                if x <= n0:
                    cond2 = True
                else:
                    cond2 = False
        else:
            if x <= n0:
                cond2 = True
            else:
                cond2 = False
    if cond1 == True and cond2 == True:
        print(1)
    else:
        print(0)

solve()