import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    table = [input().strip().split(',') for _ in range(n)]
    for c1 in range(m):
        for c2 in range(c1+1, m):
            seen = {}
            for i in range(n):
                key = (table[i][c1], table[i][c2])
                if key in seen:
                    print("NO")
                    print(seen[key] + 1, i + 1)
                    print(c1 + 1, c2 + 1)
                    return
                seen[key] = i
    print("YES")

if __name__ == "__main__":
    main()