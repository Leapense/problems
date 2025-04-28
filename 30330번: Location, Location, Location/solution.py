#!/usr/bin/env python3

import sys

def main() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    if not data:
        return
    n = data[0]
    xs = data[1::2]
    ys = data[2::2]

    xs.sort()
    ys.sort()

    median_x = xs[(n - 1) // 2]
    median_y = ys[(n - 1) // 2]

    print(median_x, median_y)

if __name__ == "__main__":
    main()