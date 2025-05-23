def main():
    import sys
    L, R = map(int, sys.stdin.read().split())
    total = 0
    lm = L - 1
    for d in range(1, R + 1):
        q = R // d - lm // d
        total += d * q
    print(total)

if __name__ == '__main__':
    main()