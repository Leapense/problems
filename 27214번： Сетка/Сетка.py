def draw_grid(k, w, h, t):
    line_length = w * k + (w + 1) * t
    horizontal_line = '*' * line_length
    cell_line = '*' * t
    for _ in range(w):
        cell_line += '.' * k + '*' * t
    
    for i in range(h):
        for _ in range(t):
            print(horizontal_line)
        for _ in range(k):
            print(cell_line)

    for _ in range(t):
        print(horizontal_line)

k = int(input())
w = int(input())
h = int(input())
t = int(input())

draw_grid(k, w, h, t)