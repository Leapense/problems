import sys
from collections import deque

def parse_all(lines):
    i = 0
    first = lines[0].split()
    datasets = []
    if len(first) == 1 and first[0].isdigit():
        n = int(first[0])
        i = 1
        for _ in range(n):
            r, c = map(int, lines[i].split())
            i += 1
            grid = [lines[i + k].rstrip("\n") for k in range(r)]
            i += r
            datasets.append((r, c, grid))
    else:
        while i < len(lines):
            r, c = map(int, lines[i].split())
            i += 1
            grid = [lines[i + k].rstrip("\n") for k in range(r)]
            i += r
            datasets.append((r, c, grid))
    return datasets

def count_sections_and_spaces(r, c, grid):
    vis = [[False] * c for _ in range(r)]
    sections = 0
    spaces = 0
    for y in range(r):
        for x in range(c):
            if grid[y][x] == '.' and not vis[y][x]:
                sections += 1
                q = deque()
                q.append((y, x))
                vis[y][x] = True
                while q:
                    cy, cx = q.popleft()
                    spaces += 1
                    for dy, dx in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                        ny, nx = cy + dy, cx + dx
                        if 0 <= ny < r and 0 <= nx < c and not vis[ny][nx] and grid[ny][nx] == '.':
                            vis[ny][nx] = True
                            q.append((ny, nx))
    return sections, spaces

def pluralize(n, singular, plural):
    return singular if n == 1 else plural

def main():
    data = sys.stdin.read().strip().splitlines()
    if not data:
        return
    datasets = parse_all(data)
    out = []
    for r, c, grid in datasets:
        secs, sp = count_sections_and_spaces(r, c, grid)
        out.append(f"{secs} {pluralize(secs, 'section', 'sections')}, {sp} {pluralize(sp, 'space', 'spaces')}")

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()