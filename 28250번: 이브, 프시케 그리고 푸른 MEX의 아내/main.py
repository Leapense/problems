import sys

def main():
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))
    f0 = 0
    f1 = 0
    for x in A:
        if x == 0:
            f0 += 1
        elif x == 1:
            f1 += 1

    rest = N - f0 - f1
    ans = 2 * f0 * f1 + f0 * (f0 - 1) // 2 + f0 * rest
    print(ans)

if __name__ == "__main__":
    main()
