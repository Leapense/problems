import sys

def main():
    input = sys.stdin.readline
    N, D = map(int, input().split())
    board = [list(map(int, input().split())) for _ in range(N)]

    ps = [[0] * (N + 1) for _ in range(N + 1)]
    for i in range(1, N + 1):
        row = board[i - 1]
        row_sum = 0
        for j in range(1, N + 1):
            row_sum += row[j - 1]
            ps[i][j] = ps[i - 1][j] + row_sum

    def rect_sum(r1, c1, r2, c2):
        return ps[r2][c2] - ps[r1 - 1][c2] - ps[r2][c1 - 1] + ps[r1 - 1][c1 - 1]
    
    best_r = best_c = -1
    best_take = 10 ** 9

    for r in range(1, N + 1):
        for c in range(1, N + 1):
            if board[r - 1][c - 1] == 1:
                continue
            r1 = max(1, r - D)
            c1 = max(1, c - D)
            r2 = min(N, r + D)
            c2 = min(N, c + D)
            s = rect_sum(r1, c1, r2, c2)
            if s == 0:
                print(r, c)
                return
    for r in range(1, N + 1):
        for c in range(1, N + 1):
            if board[r - 1][c - 1] == 1:
                continue
            r1 = max(1, r - D)
            c1 = max(1, c - D)
            r2 = min(N, r + D)
            c2 = min(N, c + D)
            s = rect_sum(r1, c1, r2, c2)
            if s < best_take:
                best_take = s
                best_r, best_c = r, c

    print(best_r, best_c)
    print(best_take)

if __name__ == "__main__":
    main()