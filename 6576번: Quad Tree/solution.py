import sys
sys.setrecursionlimit(1000000)

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    s = data[1]
    idx = 0
    grid = [['W'] * n for _ in range(n)]

    def decode(x, y, size):
        nonlocal idx
        c = s[idx]
        idx += 1
        if c == 'Q':
            h = size // 2
            decode(x, y, h)
            decode(x, y + h, h)
            decode(x + h, y, h)
            decode(x + h, y + h, h)
        else:
            fill = 'B' if c == 'B' else 'W'
            for i in range(x, x + size):
                for j in range(y, y + size):
                    grid[i][j] = fill
    
    decode(0, 0, n)
    out = []
    out.append(f"#define quadtree_width {n}")
    out.append(f"#define quadtree_height {n}")
    out.append("static char quadtree_bits[] = {")
    for row in grid:
        line = []
        for i in range(0, n, 8):
            v = 0
            for b in range(8):
                if row[i + b] == 'B':
                    v += 1 << b
            
            line.append(f"0x{v:02x}")
        out.append(",".join(line) + ",")
    out.append("};")
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()