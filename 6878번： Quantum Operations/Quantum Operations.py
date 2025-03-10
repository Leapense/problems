def tensor_product(A, B):
    m, n = len(A), len(A[0])
    p, q = len(B), len(B[0])
    result = [[0] * (n * q) for _ in range(m * p)]
    for i in range(m):
        for j in range(n):
            for r in range(p):
                for c in range(q):
                    result[i * p + r][j * q + c] = A[i][j] * B[r][c]
    return result

import sys
input_data = sys.stdin.read().split()
idx = 0
N = int(input_data[idx])
idx += 1

result = []
for _ in range(N):
    r = int(input_data[idx])
    c = int(input_data[idx + 1])
    idx += 2
    matrix = []

    for _ in range(r):
        row = list(map(int, input_data[idx:idx + c]))
        idx += c
        matrix.append(row)
    if not result:
        result = matrix
    else:
        result = tensor_product(result, matrix)

max_element = max(max(row) for row in result)
min_element = min(min(row) for row in result)
row_sums = [sum(row) for row in result]
max_row_sum = max(row_sums)
min_row_sum = min(row_sums)
col_sums = [sum(result[i][j] for i in range(len(result))) for j in range(len(result[0]))]
max_col_sum = max(col_sums)
min_col_sum = min(col_sums)

print(max_element, min_element, max_row_sum, min_row_sum, max_col_sum, min_col_sum, sep="\n")