h, w, n = map(int, input().split())
frames = [list(map(int, input().split())) for _ in range(n)]

canvas = [['.'] * w for _ in range(h)]

for i in range(n):
    r1, c1, r2, c2 = frames[i]

    r1 -= 1
    c1 -= 1
    r2 -= 1
    c2 -= 1

    symbol = chr(ord('a') + i)

    for c in range(c1, c2 + 1):
        canvas[r1][c] = symbol
        canvas[r2][c] = symbol
    
    for r in range(r1, r2 + 1):
        canvas[r][c1] = symbol
        canvas[r][c2] = symbol

for row in canvas:
    print(''.join(row))