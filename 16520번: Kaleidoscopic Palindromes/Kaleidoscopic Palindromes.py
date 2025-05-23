def solve():
    import sys
    a, b, k = map(int, sys.stdin.readline().split())
    if k >= 3:
        ans = 0
        if a <= 0 <= b:
            ans += 1
        if a <= 1 <= b:
            ans += 1
        print(ans)
    else:
        ans = 0
        for n in range(a, b + 1):
            s = bin(n)[2:]
            if s == s[::-1]:
                ans += 1
        print(ans)

if __name__ == "__main__":
    solve()