def solve():
    import sys, bisect
    input = sys.stdin.readline
    n = int(input().strip())
    stars = set()
    row_stars = {}
    col_stars = {}

    for _ in range(n):
        x, y = map(int, input().split())
        stars.add((x, y))
        if y not in row_stars:
            row_stars[y] = []
        row_stars[y].append(x)
        if x not in col_stars:
            col_stars[x] = []
        col_stars[x].append(y)

    for key in row_stars:
        row_stars[key].sort()
    for key in col_stars:
        col_stars[key].sort()

    directions = [(1, 0), (0, -1), (-1, 0), (0, 1)]
    x, y = 0, 0
    d = 0
    energy = 0
    THRESHOLD = 10**10

    visited = set()

    while abs(x) <= THRESHOLD and abs(y) <= THRESHOLD:
        state = (x, y, d)
        if state in visited:
            print("oo")
            return
        visited.add(state)

        dx, dy = directions[d]

        free_steps = float('inf')
        if dx != 0:
            if y in row_stars:
                lst = row_stars[y]
                if dx == 1:
                    idx = bisect.bisect_right(lst, x)
                    if idx < len(lst):
                        free_steps = lst[idx] - x - 1
                else:
                    idx = bisect.bisect_left(lst, x) - 1
                    if idx >= 0:
                        free_steps = x - lst[idx] - 1
        else:
            if x in col_stars:
                lst = col_stars[x]
                if dy == 1:
                    idx = bisect.bisect_right(lst, y)
                    if idx < len(lst):
                        free_steps = lst[idx] - y - 1
                else:
                    idx = bisect.bisect_left(lst, y) - 1
                    if idx >= 0:
                        free_steps = y - lst[idx] - 1

        if dx == 1:
            t_bound = THRESHOLD - x
        elif dx == -1:
            t_bound = x + THRESHOLD
        elif dy == 1:
            t_bound = THRESHOLD - y
        else:
            t_bound = y + THRESHOLD

        move = min(free_steps, t_bound)
        x += dx * move
        y += dy * move

        if move == t_bound:
            print(energy)
            return
        
        energy += 1
        d = (d + 1) % 4
    
    print(energy)

if __name__ == "__main__":
    solve()