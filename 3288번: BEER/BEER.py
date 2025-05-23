import sys

def main():
    import sys

    sys.setrecursionlimit(10000)
    N = int(sys.stdin.readline())
    input_lines = [sys.stdin.readline().strip() for _ in range(N)]

    # Map directions to integers
    dir_map = {'U':0, 'R':1, 'D':2, 'L':3}

    # Initialize grid: rows are 1 to N (bottom to top)
    grid = {}
    for r in range(1, N+1):
        line = input_lines[N - r]
        for c in range(1, len(line)+1):
            grid[(r, c)] = dir_map[line[c-1]]

    # Assign unique indices to each bottle
    index_map = {}
    reverse_map = {}
    idx = 0
    for r in range(1, N+1):
        for c in range(1, N - r + 2):
            index_map[(r, c)] = idx
            reverse_map[idx] = (r, c)
            idx +=1
    total_vars = idx

    # Initialize augmented matrix
    matrix = [ [0]*(total_vars +1) for _ in range(total_vars) ]

    for r in range(1, N+1):
        for c in range(1, N - r +2):
            eq_idx = index_map[(r, c)]
            # x_{r,c}
            matrix[eq_idx][index_map[(r, c)]] =1
            # x_{r-1,c}
            if (r-1, c) in index_map:
                matrix[eq_idx][index_map[(r-1, c)]] =1
            # x_{r-1,c-1}
            if (r-1, c-1) in index_map:
                matrix[eq_idx][index_map[(r-1, c-1)]] =1
            # RHS
            matrix[eq_idx][-1] = (-grid[(r, c)]) %4

    # Gaussian Elimination mod4
    for col in range(total_vars):
        pivot = -1
        for row in range(col, total_vars):
            if matrix[row][col] %4 in [1,3]:
                pivot = row
                break
        if pivot == -1:
            continue  # Free variable
        # Swap rows
        matrix[col], matrix[pivot] = matrix[pivot], matrix[col]
        # Normalize pivot row
        if matrix[col][col]%4 ==3:
            # Multiply by 3
            for j in range(col, total_vars +1):
                matrix[col][j] = (matrix[col][j]*3)%4
        elif matrix[col][col]%4 ==1:
            pass  # Nothing
        else:
            # Should not happen
            pass
        # Eliminate below
        for row in range(total_vars):
            if row != col and matrix[row][col]%4 !=0:
                factor = matrix[row][col]
                for j in range(col, total_vars +1):
                    matrix[row][j] = (matrix[row][j] - factor * matrix[col][j])%4

    # Check for inconsistency
    for row in range(total_vars):
        all_zero = True
        for col in range(total_vars):
            if matrix[row][col]%4 !=0:
                all_zero = False
                break
        if all_zero and matrix[row][-1]%4 !=0:
            print("No solution found.")
            return

    # Assign variables
    solution = [0]*total_vars
    for row in range(total_vars):
        pivot_col = -1
        for col in range(total_vars):
            if matrix[row][col]%4 !=0:
                pivot_col = col
                break
        if pivot_col == -1:
            continue  # Free variable, set to 0
        solution[pivot_col] = matrix[row][-1]%4

    # Generate move list
    moves = []
    for idx, cnt in enumerate(solution):
        if cnt >0:
            r,c = reverse_map[idx]
            for _ in range(cnt):
                moves.append((r, c))

    # Check if moves exceed 1000
    if len(moves) >1000:
        print("No solution within 1000 moves.")
        return

    # Output moves
    for move in moves:
        print(move[0], move[1])

if __name__ == "__main__":
    main()
