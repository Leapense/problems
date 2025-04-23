import sys
import itertools

def max_taste(n, k, C):
    best = -10**18
    for combo in itertools.combinations(range(n), k):
        s = 0
        for i in range(k):
            for j in range(i + 1, k):
                s += C[combo[i]][combo[j]]
        if s > best:
            best = s
    return best if best != -10**18 else 0

def main():
    input = sys.stdin.readline
    n, k = map(int, input().split())
    C = [list(map(int, input().split())) for _ in range(n)]
    print(max_taste(n, k, C))

if __name__ == "__main__":
    main()
