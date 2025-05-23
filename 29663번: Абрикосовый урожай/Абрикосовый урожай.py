def count_squares(n, m, S, matrix):
    sum_matrix = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            sum_matrix[i][j] = matrix[i-1][j-1] + sum_matrix[i-1][j] + sum_matrix[i][j-1] - sum_matrix[i-1][j-1]

    count = 0
    max_k = min(n, m)

    for k in range(1, max_k + 1):
        for i in range(k, n + 1):
            for j in range(k, m + 1):
                total = sum_matrix[i][j] - sum_matrix[i - k][j] - sum_matrix[i][j - k] + sum_matrix[i - k][j - k]
                if total < S:
                    count += 1
    return count

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    m = int(data[1])
    S = int(data[2])

    matrix = []
    idx = 3

    for _ in range(n):
        row = list(map(int, data[idx:idx + m]))
        matrix.append(row)
        idx += m
    
    result = count_squares(n, m, S, matrix)
    print(result)

if __name__ == '__main__':
    main()