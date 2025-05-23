def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    w = int(data[0])
    h = int(data[1])
    n = int(data[2])

    coordinates = data[3:]
    x = [int(coordinates[2 * i]) for i in range(n)]
    y = [int(coordinates[2 * i + 1]) for i in range(n)]

    ans = 0
    for i in range(1, n):
        dx = x[i] - x[i-1]
        dy = y[i] - y[i-1]
        if dx * dy >= 0:
            ans += max(abs(dx), abs(dy))
        else:
            ans += abs(dx) + abs(dy)

    print(ans)

if __name__ == '__main__':
    main()