def solve():
    import sys

    input = sys.stdin.readline
    R = int(input().strip())
    Ls = []
    Rs = []

    for _ in range(R):
        l, r = map(int, input().split())
        Ls.append(l)
        Rs.append(r)

    N = int(input().strip())
    A = [Ls[i] + Rs[i] for i in range(R)]
    base = [A[i] + 1 for i in range(R)]
    value = 0
    mult = 1

    for i in range(R - 1, -1, -1):
        value += Ls[i] * mult
        mult *= base[i]
    value = (value + N) % mult
    newL = [0] * R
    for i in range(R - 1, -1, -1):
        newL[i] = value % base[i]
        value //= base[i]
    for i in range(R):
        print(newL[i], A[i] - newL[i])

solve()