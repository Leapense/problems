import sys

def main():
    input = sys.stdin.readline
    h, w = map(int, input().split())
    grid = [input().rstrip() for _ in range(h)]
    cnt = [0] * w
    for row in grid:
        for i, c in enumerate(row):
            if c == 'I':
                cnt[i] += 1
    ans = 0
    for row in grid[:-1]:
        for i, c in enumerate(row):
            if c == 'I':
                cnt[i] -= 1
        s = 0
        for i, c in enumerate(row):
            if c == 'O':
                ans += s
            elif c == 'J':
                s += cnt[i]
    print(ans)

if __name__ == "__main__":
    main()