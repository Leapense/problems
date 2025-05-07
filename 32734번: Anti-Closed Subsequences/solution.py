import sys

def solve():
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    b = []

    for x in a:
        b.append(x.bit_length())

    sys.stdout.write(" ".join(map(str, b)) + "\n")

if __name__ == "__main__":
    solve()