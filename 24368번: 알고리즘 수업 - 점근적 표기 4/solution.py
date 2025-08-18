import sys

def ceil_div(a, b):
    return -((-a) // b)

def solve():
    data = sys.stdin.read().strip().split()
    a2, a1, a0 = map(int, data[:3])
    c = int(data[3])
    n0 = int(data[4])
    b2 = a2 - c
    b1 = a1
    b0 = a0

    def q(n):
        return b2 * n * n + b1 * n + b0
    
    if b2 > 0:
        print(0)
        return
    
    if b2 == 0:
        if b1 > 0:
            print(0)
            return
        if b1 == 0:
            print(1 if b0 <= 0 else 0)
            return
        print(1 if q(n0) <= 0 else 0)
        return
    
    num = -b1
    den = 2 * b2
    cv = ceil_div(num, den)
    end_n = cv + 1
    if end_n < n0:
        end_n = n0

    ok = True
    for n in range(n0, end_n + 1):
        if q(n) > 0:
            ok = False
            break
    
    print(1 if ok else 0)

if __name__ == "__main__":
    solve()