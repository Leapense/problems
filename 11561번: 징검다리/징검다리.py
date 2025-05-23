import math, sys
def main():
    T, *rest = sys.stdin.read().split()
    for i in range(int(T)):
        N = int(rest[i])
        k = (math.isqrt(8 * N + 1) - 1) // 2
        print(k)

if __name__ == '__main__':
    main()