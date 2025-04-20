import sys

def solve() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    out_lines = []
    for tc in range(t):
        r, c = map(int, data[idx:idx + 2]); idx += 2
        rr, cr = map(lambda x: int(x) - 1, data[idx:idx + 2]); idx += 2
        rb, cb = map(lambda x: int(x) - 1, data[idx:idx + 2]); idx += 2
        if (r * c) & 1:
            out_lines.append("IMPOSSIBLE")
            if tc != t - 1:
                out_lines.append("")
            continue
        board = [[""] * c for _ in range(r)]
        rot = lambda x, y: (r - 1 - x, c - 1 - y)
        for i in range(r):
            for j in range(c):
                if board[i][j]:
                    continue
                x, y = rot(i, j)
                if (i, j) == (rr, cr) or (x, y) == (rb, cb):
                    board[i][j] = "R"
                    board[x][y] = "B"
                elif (i, j) == (rb, cb) or (x, y) == (rr, cr):
                    board[i][j] = "B"
                    board[x][y] = "R"
                else:
                    board[i][j] = "R"
                    board[x][y] = "B"
        out_lines.extend("".join(row) for row in board)
        if tc != t - 1:
            out_lines.append("")
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()
