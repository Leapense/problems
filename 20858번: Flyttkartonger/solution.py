import sys

def main() -> None:
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    need = a[-1]
    for i in range(n - 2, -1, -1):
        next_height = a[i + 1]
        if need > next_height:
            need = 2 * need - next_height
        else:
            need = next_height

    extra = max(0, need - a[0])
    print(extra)

if __name__ == "__main__":
    main()