import sys

def parse_piece_line(line_str, piece_val, board_state_ref, piece_positions_list_ref = None):
    parts = list(map(int, line_str.split()))
    count = parts[0]
    n_rows = len(board_state_ref)
    n_cols = len(board_state_ref[0])

    if count > 0:
        for i in range(count):
            r = parts[2 * i + 1] - 1
            c = parts[2 * i + 2] - 1

            if 0 <= r < n_rows and 0 <= c < n_cols:
                if piece_positions_list_ref is not None:
                    piece_positions_list_ref.append((r, c))
                board_state_ref[r][c] = piece_val

def solve():
    n, m = map(int, sys.stdin.readline().split())
    board_state = [[0 for _ in range(m)] for _ in range(n)]
    is_unsafe = [[False for _ in range(m)] for _ in range(n)]

    queens_pos = []
    knights_pos = []

    parse_piece_line(sys.stdin.readline(), 1, board_state, queens_pos)
    parse_piece_line(sys.stdin.readline(), 2, board_state, knights_pos)
    parse_piece_line(sys.stdin.readline(), 3, board_state)

    knight_moves = [
        (-2, -1), (-2, 1), (-1, -2), (-1, 2),
        (1, -2), (1, 2), (2, -1), (2, 1)
    ]

    for r_k, c_k in knights_pos:
        for dr, dc in knight_moves:
            nr, nc = r_k + dr, c_k + dc
            if 0 <= nr < n and 0 <= nc < m:
                is_unsafe[nr][nc] = True

    queen_dirs = [
        (-1, -1), (-1, 0), (-1, 1), (0, -1),
        (0, 1), (1, -1), (1, 0), (1, 1)
    ]

    for r_q, c_q in queens_pos:
        for dr, dc in queen_dirs:
            curr_r, curr_c = r_q + dr, c_q + dc
            while 0 <= curr_r < n and 0 <= curr_c < m:
                if board_state[curr_r][curr_c] != 0:
                    break

                is_unsafe[curr_r][curr_c] = True
                curr_r += dr
                curr_c += dc

    safe_count = 0
    for r_idx in range(n):
        for c_idx in range(m):
            if board_state[r_idx][c_idx] == 0 and not is_unsafe[r_idx][c_idx]:
                safe_count += 1

    print(safe_count)

if __name__ == "__main__":
    solve()