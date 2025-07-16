import sys
def main():
    data = sys.stdin.readline().split()
    N = int(data[0])
    X = int(data[1])
    if X < N or X > 26 * N:
        print("!")
        return
    result = []
    for i in range(N):
        rem = N - i - 1
        low = X - rem * 26
        if low < 1:
            low = 1
        high = X - rem
        if high > 26:
            high = 26
        c = low
        result.append(chr(64 + c))
        X -= c
    print("".join(result))

if __name__ == '__main__':
    main()