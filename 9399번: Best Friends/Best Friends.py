import sys

def find_row(n):
    r = 1
    while r * (r + 1) // 2 < n:
        r += 1
    return r

def coords(n):
    r = find_row(n)
    c = n - (r * (r - 1) // 2)
    X = c - 1
    Y = r - c
    Z = 1 - r
    return (X, Y, Z)

for line in sys.stdin:
    a, b = map(int, line.split())
    if a == 0 and b == 0:
        break

    X1, Y1, Z1 = coords(a)
    X2, Y2, Z2 = coords(b)
    dist = max(abs(X1 - X2), abs(Y1 - Y2), abs(Z1 - Z2))
    print(dist)