import sys

def main():
    data = sys.stdin.read().strip().split()
    it = iter(data)
    N = int(next(it))
    M = int(next(it))
    D = int(next(it))

    grid = [list(next(it)) for _ in range(N)]
    ROWMASK = (1 << M) - 1
    letter_masks = [[0] * N for _ in range(26)]
    present_flags = 0
    for r in range(N):
        row_masks = [0] * 26
        for j, ch in enumerate(grid[r]):
            idx = ord(ch) - 65
            row_masks[idx] |= (1 << j)
        for idx in range(26):
            mask = row_masks[idx]
            letter_masks[idx][r] = mask
            if mask:
                present_flags |= (1 << idx)

    start_idx = None
    for idx in range(26):
        if (present_flags >> idx) & 1:
            start_idx = idx
            break
        
    if start_idx is None:
        print('Z' * D)
        return
    
    S = [letter_masks[start_idx][r] for r in range(N)]
    used_mask = 1 << start_idx
    word = [chr(65 + start_idx)]
    def neighbors_of(S_rows):
        nb = [0] * N
        for r in range(N):
            cur = S_rows[r]
            horiz = ((cur << 1) | (cur >> 1)) & ROWMASK
            total = horiz
            if r > 0:
                p = S_rows[r - 1]
                total |= (p | ((p << 1) & ROWMASK) | (p >> 1))
            if r + 1 < N:
                n = S_rows[r + 1]
                total |= (n | ((n << 1) & ROWMASK) | (n >> 1))
            nb[r] = total
        return nb
    
    for _ in range(1, D):
        nb = neighbors_of(S)
        next_idx = None
        for idx in range(26):
            if (used_mask >> idx) & 1:
                continue
            found = False
            for r in range(N):
                if nb[r] & letter_masks[idx][r]:
                    found = True
                    break
            if found:
                next_idx = idx
                break
            
        if next_idx is None:
            word.append('Z' * (D - len(word)))
            break
        
        S = [nb[r] & letter_masks[next_idx][r] for r in range(N)]
        used_mask |= (1 << next_idx)
        word.append(chr(65 + next_idx))

    print(''.join(word))

if __name__ == "__main__":
    main()