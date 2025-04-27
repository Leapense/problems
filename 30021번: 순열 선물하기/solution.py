import sys
input = sys.stdin.readline
def main():
    N = int(input())
    if N == 1:
        print("YES")
        print(1)
    elif N == 2:
        print("NO")
    else:
        print("YES")
        perm = [1, 3, 2] + list(range(4, N+1))
        print(*perm)

if __name__ == "__main__":
    main()