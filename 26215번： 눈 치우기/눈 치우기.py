def solve():
    import sys
    input = sys.stdin.readline

    N = int(input().strip())
    snow = list(map(int, input().split()))
    
    S = sum(snow); M = max(snow)
    answer = max(M, (S + 1) // 2)

    if answer > 1440:
        print(-1)
    else:
        print(answer)

if __name__ == "__main__":
    solve()