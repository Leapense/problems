#!/usr/bin/env python3

from sys import stdin, stdout

def minimum_strokes(height: int, width: int, brush_h: int, brush_w: int, target: list[str]) -> int:
    diff = [[0] * (width + 1) for _ in range(height + 1)]
    strokes = 0

    for i in range(height):
        row_acc = 0
        for j in range(width):
            row_acc ^= diff[i][j]
            current_colour = row_acc
            need_colour = 1 if target[i][j] == '1' else 0

            if current_colour != need_colour:
                if i + brush_h > height or j + brush_w > width:
                    return -1
                
                diff[i][j] ^= 1
                diff[i + brush_h][j] ^= 1
                diff[i][j + brush_w] ^= 1
                diff[i + brush_h][j + brush_w] ^= 1
                row_acc ^= 1
                strokes += 1
        
        for j in range(width + 1):
            diff[i + 1][j] ^= diff[i][j]

    return strokes

def main() -> None:
    out_lines : list[str] = []
    it = iter(stdin.read().strip().split())
    for n, m, r, c in zip(it, it, it, it):
        n = int(n)
        m = int(m)
        r = int(r)
        c = int(c)

        if n == 0 and m == 0 and r == 0 and c == 0:
            break
        
        picture = [next(it) for _ in range(n)]
        out_lines.append(str(minimum_strokes(n, m, r, c, picture)))

    stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()