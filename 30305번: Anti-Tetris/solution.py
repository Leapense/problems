import sys

def rotate_cw(g):
    h, w = len(g), len(g[0])
    return ["".join(g[h - 1 - r][c] for r in range(h)) for c in range(w)]

def trim(g):
    H, W = len(g), len(g[0])
    rows = [i for i in range(H) if '#' in g[i]]
    cols = [j for j in range(W) if any(g[i][j] == '#' for i in range(H))]
    r1, r2 = min(rows), max(rows)
    c1, c2 = min(cols), max(cols)
    return [g[i][c1:c2+1] for i in range(r1, r2 + 1)]

def ok_column_top_prefix(S):
    H, W = len(S), len(S[0])
    if any(S[0][j] != '#' for j in range(W)):
        return False
    
    for j in range(W):
        i = 0
        while i < H and S[i][j] == '#':
            i += 1
        for k in range(i, H):
            if S[k][j] == '#':
                return False
    return True

def build_and_print(S):
    H, W = len(S), len(S[0])
    print(H, W)
    for i in range(H):
        row = ''.join('.' if ch == '#' else '#' for ch in S[i])
        print(row)

def main():
    data = sys.stdin.read().splitlines()
    h, w = map(int, data[0].split())
    g = data[1:]
    for _ in range(4):
        S = trim(g)
        if ok_column_top_prefix(S):
            build_and_print(S)
            return
        g = rotate_cw(g)
    print("impossible")

if __name__ == "__main__":
    main()