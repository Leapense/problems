a2, a1, a0 = map(int, input().split())
c = int(input())
n0 = int(input())

def g(x):
    return c * (x ** 2)
def f(x):
    return a2 * (x ** 2) + a1 * x + a0

D = (a1 ** 2) - 4 * a0 * (a2 - c)

def solve():
    if a2 == c:
        if a1 == a0 == 0:
            print(1)
        else:
            if a1 > 0:
                print(0)
            elif a1 == 0:
                if a0 > 0:
                    print(0)
                else:
                    print(1)
            else:
                print(1)
    elif a2 == 0:
        if f(n0) <= g(n0):
            print(1)
        else:
            print(0)
    elif a2 > c:
        print(0)
    elif D < 0:
        if f(n0) <= g(n0):
            print(1)
        else:
            print(0)
    elif D == 0:
        if f(n0) <= g(n0):
            print(1)
        else:
            print(0)
    else:
        x = (a1 + D ** (1 / 2)) / (2 * (c - a2))
        if a2 > 0:
            vertex = a1 / (2 * (c - a2))
            if f(vertex) < g(vertex):
                print(0)
            else:
                if x <= n0:
                    print(1)
                else:
                    print(0)
        else:
            if x <= n0:
                print(1)
            else:
                print(0)

solve()