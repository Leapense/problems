# solution.py
import sys
def main():
    input = sys.stdin.readline
    n, m = map(int, input().split())
    A = [input().rstrip() for _ in range(n)]
    row_counts = {}
    for row in A:
        row_counts[row] = row_counts.get(row, 0) + 1
    odd_rows = sum(v & 1 for v in row_counts.values())
    cols = [''.join(A[i][j] for i in range(n)) for j in range(m)]
    col_counts = {}
    for col in cols:
        col_counts[col] = col_counts.get(col, 0) + 1
    odd_cols = sum(v & 1 for v in col_counts.values())
    if odd_rows <= (n & 1) and odd_cols <= (m & 1):
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()
