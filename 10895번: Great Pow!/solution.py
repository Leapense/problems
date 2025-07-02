import sys

def solve():
    try:
        a, k = map(int, sys.stdin.readline().split())
    except (IOError, ValueError) as e:
        return

    mod = a + 1
    if k == 0:
        print(a)
        return

    if a % 2 == 0:
        print(1)
    else:
        print(a)

if __name__ == "__main__":
    solve()