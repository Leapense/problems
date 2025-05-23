import sys
from itertools import product

def read_input():
    return int(sys.stdin.read())

def main():
    M = read_input()
    for N in range(2, 11):
        candidates = [str(num) for num in range(10 ** (N - 1), 10 ** N) if num % M == 0]
        grid = []
        used = set()

        def backtrack(row):
            if row == N:
                cols = [''.join(grid[r][c] for r in range(N)) for c in range(N)]
                diag1 = ''.join(grid[i][i] for i in range(N))
                diag2 = ''.join(grid[i][N-1-i] for i in range(N))
                all_numbers = set(candidates_selected)
                for num in cols + [diag1, diag2]:
                    if num[0] == '0' or int(num) % M != 0 or num in all_numbers:
                        return False
                    all_numbers.add(num)
                print(N)
                for line in grid:
                    print(' '.join(line))
                sys.exit(0)
            for num in candidates:
                if num not in used:
                    grid.append(num)
                    used.add(num)
                    candidates_selected.append(num)
                    backtrack(row + 1)
                    grid.pop()
                    used.remove(num)
                    candidates_selected.pop()
        candidates_selected = []
        backtrack(0)
main()