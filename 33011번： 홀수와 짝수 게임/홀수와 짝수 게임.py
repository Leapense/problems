def solve():
    import sys
    input = sys.stdin.readline

    T = int(input().strip())
    for _ in range(T):
        N = int(input().strip())
        cards = list(map(int, input().split()))
        odd = sum(1 for c in cards if c % 2 == 1)
        even = N - odd

        if (odd > even and odd % 2 == 1) or (even > odd and even % 2 == 1):
            print("amsminn")
        else:
            print("heeda0528")

if __name__ == "__main__":
    solve()