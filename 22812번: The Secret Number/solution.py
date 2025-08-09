import sys

def is_digit(c):
    return '0' <= c <= '9'

def strip_leading_zeros(s):
    t = s.lstrip('0')
    return t if t else '0'

def cmp_num(s1, s2):
    a = strip_leading_zeros(s1)
    b = strip_leading_zeros(s2)
    if len(a) != len(b):
        return 1 if len(a) > len(b) else -1
    if a != b:
        return 1 if a > b else -1
    return 0

def pick_num(s1, s2):
    if s1 is None:
        return s2
    if s2 is None:
        return s1
    return s1 if cmp_num(s1, s2) >= 0 else s2

def pick_len_then_num(s1, s2):
    if s1 is None:
        return s2
    if s2 is None:
        return s1
    if len(s1) != len(s2):
        return s1 if len(s1) > len(s2) else s2
    return s1 if cmp_num(s1, s2) >= 0 else s2

def solve_dataset(W, H, grid):
    A = [[None] * W for _ in range(H)]
    B = [[None] * W for _ in range(H)]
    for i in range(H - 1, -1, -1):
        for j in range(W - 1, -1, -1):
            c = grid[i][j]
            if not is_digit(c):
                A[i][j] = None
                B[i][j] = None
                continue
            ar = A[i][j+1] if j+1 < W else None
            ad = A[i+1][j] if i+1 < H else None
            br = B[i][j+1] if j+1 < W else None
            bd = B[i+1][j] if i+1 < H else None
            contA = None
            if ar is not None or ad is not None:
                contA = pick_len_then_num(ar, ad)
            A[i][j] = c + (contA if contA is not None else "")
            bestB = c
            if c != '0':
                if contA is not None:
                    cand = c + contA
                    if cmp_num(cand, bestB) > 0:
                        bestB = cand
            else:
                contB = None
                if br is not None or bd is not None:
                    contB = pick_num(br, bd)
                if contB is not None:
                    cand = c + contB
                    if cmp_num(cand, bestB) > 0:
                        bestB = cand
            B[i][j] = bestB

    ans = None
    for i in range(H):
        for j in range(W):
            if B[i][j] is not None:
                ans = B[i][j] if ans is None else pick_num(ans, B[i][j])
    return strip_leading_zeros(ans)

def main():
    data = sys.stdin.read().strip().splitlines()
    idx = 0
    out = []
    while idx < len(data):
        if not data[idx].strip():
            idx += 1
            continue
        w_h = data[idx].split()
        idx += 1
        if len(w_h) != 2:
            continue
        W, H = map(int, w_h)
        if W == 0 and H == 0:
            break
        grid = []
        for _ in range(H):
            grid.append(data[idx].rstrip('\n'))
            idx += 1
        out.append(solve_dataset(W, H, grid))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()