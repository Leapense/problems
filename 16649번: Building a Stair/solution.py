import sys

def solve():
    """
    Constructs and prints a symmetric stair with n cubes.
    """
    try:
        n_str = sys.stdin.readline()
        if not n_str:
            return
        n = int(n_str)
    except (IOError, ValueError):
        return

    m = -1
    for i in range(1, 101):
        if i * i >= n and (i - n) % 2 == 0:
            m = i
            break

    if m == -1:
        print(-1)
        return

    grid = [['.' for _ in range(m)] for _ in range(m)]
    cubes_to_place = n

    for i in range(m):
        grid[i][i] = 'o'
    cubes_to_place -= m

    pairs_to_place = cubes_to_place // 2
    for i in range(m):
        for j in range(i + 1, m):
            if pairs_to_place > 0:
                grid[i][j] = 'o'
                grid[j][i] = 'o'
                pairs_to_place -= 1
    
    print(m)

    for i in range(m - 1, -1, -1):
        print("".join(grid[i]))

solve()