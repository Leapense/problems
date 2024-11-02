import sys
import math

def main():
    n = int(sys.stdin.readline())
    min_num = None
    min_den = None
    min_index = -1

    for idx in range(1, n + 1):
        A, B, C = map(int, sys.stdin.readline().split())
        num = A
        den = C - B
        if den <= 0:
            continue
        if min_num is None:
            min_num = num
            min_den = den
            min_index = idx
        else:
            if num * min_den < min_num * den:
                min_num = num
                min_den = den
                min_index = idx
            elif num * min_den == min_num * den:
                if num < min_index:
                    min_num = num
                    min_den = den
                    min_index = idx
    print(min_index)

if __name__ == '__main__':
    main()