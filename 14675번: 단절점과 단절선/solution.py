import sys
input = sys.stdin.readline

def main():
    n = int(input().strip())
    degree = [0] * (n + 1)

    for _ in range(n - 1):
        u, v = map(int, input().split())
        degree[u] += 1
        degree[v] += 1

    q = int(input().strip())
    out = []

    for _ in range(q):
        t, k = map(int, input().split())
        if t == 1:
            out.append('yes' if degree[k] >= 2 else 'no')
        else:
            out.append('yes')

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()