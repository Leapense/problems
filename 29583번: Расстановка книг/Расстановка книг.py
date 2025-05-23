import sys
from itertools import permutations

def solve():
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    p = list(map(int, data[1:n+1]))
    a = list(map(int, data[n+1:]))

    count = 0

    for perm in permutations(p):
        valid = True
        for i in range(n - 1):
            if perm[i] + perm[i+1] > a[i]:
                valid = False
                break
        if valid:
            count += 1

    sys.stdout.write(str(count))

if __name__ == "__main__":
    solve()