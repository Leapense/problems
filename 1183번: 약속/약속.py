#!/usr/bin/env python3
import sys

def main():
    input = sys.stdin.readline
    N = int(input().strip())

    arr = []
    for _ in range(N):
        A, B = map(int, input().split())
        arr.append(-(A - B))

    arr.sort()

    if N % 2 == 1:
        print(1)
    else:
        lower = arr[N // 2 - 1]
        upper = arr[N // 2]
        print(upper - lower + 1)

if __name__ == "__main__":
    main()