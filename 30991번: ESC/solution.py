import sys

def main():
    n = int(sys.stdin.readline().strip())
    s0, s1 = 1, 1
    if n == 0:
        print(s0)
        return
    if n == 1:
        print(s1)
        return
    for _ in range(2, n + 1):
        s0, s1 = s1, 2 * s1 - 5 * s0

    print(s1)

if __name__ == "__main__":
    main()