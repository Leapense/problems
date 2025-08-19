import sys

def solve():
    a2, a1, a0 = map(int, sys.stdin.readline().split())
    c = int(sys.stdin.readline())
    n0 = int(sys.stdin.readline())

    f_n0 = a2 * n0 ** 2 + a1 * n0 + a0
    c_g_n0 = c * n0 ** 2

    if c < a2:
        print(0)
    elif c == a2:
        if a1 * n0 + n0 <= 0 and a1 <= 0:
            print(1)
        else:
            print(0)
    else:
        if f_n0 <= c_g_n0:
            print(1)
        else:
            print(0)
    
solve()