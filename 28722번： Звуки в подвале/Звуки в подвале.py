def solve():
    import sys
    input = sys.stdin.read
    s = input().strip()

    if s[0] != s[-1]:
        print("Win")
    else:
        print("Lose")

solve()