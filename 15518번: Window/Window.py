def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    h = int(data[1])
    w = int(data[2])
    x = list(map(int, data[3:]))

    w *= 2

    ans = 0

    for i in range(0, n, 2):
        ans += min(x[i] + x[i + 1], w - x[i] - x[i + 1])

    print(ans * h)

main()