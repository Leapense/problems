import sys

def main():
    k, i = map(int, sys.stdin.readline().split())
    start = i - 1
    print(''.join(str((n.bit_count() & 1)) for n in range(start, start + 7)), end = '')

if __name__ == "__main__":
    main()