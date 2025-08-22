def solve():
    m = int(input())
    mod = 1000007

    if m == 1 or m == 2:
        print(1)
        return
    
    a, b = 1, 1
    for _ in range(m - 2):
        a, b = b, (a + b) % mod

    print(b)

solve()