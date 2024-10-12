def main():
    import sys
    import math

    input = sys.stdin.read
    data = input().strip().split()
    X = int(data[0])
    Y = int(data[1])

    if X <= Y <= 2 * X:
        W_times_2024 = (2 * X - Y) * 506
        print(W_times_2024)
    else:
        print(-1)

if __name__ == "__main__":
    main()