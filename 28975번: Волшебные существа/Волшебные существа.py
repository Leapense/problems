import sys
import math

def main():
    input = sys.stdin.read
    data = input().split()
    idx = 0

    t = int(data[idx])
    idx += 1
    s = int(data[idx])
    idx += 1
    n = int(data[idx])
    idx += 1

    total = 0

    for _ in range(n):
        a = int(data[idx])
        idx += 1
        b = int(data[idx])
        idx += 1

        if b < t:
            count = 0
        else:
            if a <= t:
                k_min = 0
            else:
                diff = a - t
                k_min = (diff + s - 1) // s
            diff_max = b - t
            if diff_max < 0:
                count = 0
                total += count
                continue
            k_max = diff_max // s
            if k_max < k_min:
                count = 0
            else:
                count = k_max - k_min + 1
        total += count

    print(total)

if __name__ == '__main__':
    main()