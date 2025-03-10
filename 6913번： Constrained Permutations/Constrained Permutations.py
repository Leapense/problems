import sys
import itertools

def main():
    input = sys.stdin.readline
    n = int(input())
    k = int(input())
    constraints = []
    for _ in range(k):
        x, y = map(int, input().split())
        constraints.append((x, y))
    count = 0
    for perm in itertools.permutations(range(1, n + 1)):
        valid = True
        for x, y in constraints:
            if perm.index(x) > perm.index(y):
                valid = False
                break
        if valid:
            count += 1
    print(count)

if __name__ == "__main__":
    main()