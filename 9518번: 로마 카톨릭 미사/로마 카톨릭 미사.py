def count_handshakes(arr, R, S):
    directions = [(-1, -1), (-1, 0), (-1, 1),
                  (0, -1),           (0, 1),
                  (1, -1), (1, 0), (1, 1)]
    handshake = 0

    for r in range(R):
        for c in range(S):
            if arr[r][c] == 'o':
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < R and 0 <= nc < S and arr[nr][nc] == 'o':
                        handshake += 1

    handshake //= 2
    return handshake

def solve():
    import sys
    input = sys.stdin.readline
    R, S = map(int, input().split())
    arr = [list(input().strip()) for _ in range(R)]

    current_handshakes = count_handshakes(arr, R, S)
    empty_seats = [(r, c) for r in range(R) for c in range(S) if arr[r][c] == '.']

    if not empty_seats:
        print(current_handshakes)
        return
    max_handshake = current_handshakes
    for (r, c) in empty_seats:
        arr[r][c] = 'o'
        new_handshakes = count_handshakes(arr, R, S)
        if new_handshakes > max_handshake:
            max_handshake = new_handshakes

        arr[r][c] = '.'

    print(max_handshake)

if __name__ == '__main__':
    solve()