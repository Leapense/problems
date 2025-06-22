import sys
sys.setrecursionlimit(10000)

def tromino(x0, y0, size, hole_x, hole_y):
    global tile_id, board
    if size == 2:
        tile_id += 1
        for dx in range(2):
            for dy in range(2):
                x = x0 + dx
                y = y0 + dy
                if not (x == hole_x and y == hole_y):
                    board[y][x] = tile_id
        return
    
    half = size // 2
    mid_x = x0 + half - 1
    mid_y = y0 + half - 1

    if hole_x > mid_x and hole_y > mid_y:
        hole_quad = 1
    elif hole_x <= mid_x and hole_y > mid_y:
        hole_quad = 2
    elif hole_x <= mid_x and hole_y <= mid_y:
        hole_quad = 3
    else:
        hole_quad = 4

    centers = {
        1: (mid_x + 1, mid_y + 1),
        2: (mid_x, mid_y + 1),
        3: (mid_x, mid_y),
        4: (mid_x + 1, mid_y)
    }

    tile_id += 1
    for q, (cx, cy) in centers.items():
        if q != hole_quad:
            board[cy][cx] = tile_id

    nx0, ny0 = mid_x + 1, mid_y + 1
    nhx, nhy = (hole_x, hole_y) if hole_quad == 1 else centers[1]
    tromino(nx0, ny0, half, nhx, nhy)

    nx0, ny0 = x0, mid_y + 1
    nhx, nhy = (hole_x, hole_y) if hole_quad == 2 else centers[2]
    tromino(nx0, ny0, half, nhx, nhy)

    nx0, ny0 = x0, y0
    nhx, nhy = (hole_x, hole_y) if hole_quad == 3 else centers[3]
    tromino(nx0, ny0, half, nhx, nhy)

    nx0, ny0 = mid_x + 1, y0
    nhx, nhy = (hole_x, hole_y) if hole_quad == 4 else centers[4]
    tromino(nx0, ny0, half, nhx, nhy)

def main():
    data = sys.stdin.read().split()
    k = int(data[0])
    hole_x, hole_y = map(int, data[1:3])

    n = 1 << k
    global board, tile_id
    board = [[0] * (n + 1) for _ in range(n + 1)]
    board[hole_y][hole_x] = -1

    tile_id = 0
    tromino(1, 1, n, hole_x, hole_y)

    out_lines = []
    for y in range(n, 0, -1):
        row = ' '.join(str(board[y][x]) for x in range(1, n + 1))
        out_lines.append(row)
    print('\n'.join(out_lines))

if __name__ == "__main__":
    main()