def is_diagonally_dominant(matrix, n):
    dominant_count = 0

    for i in range(n):
        diagonal_element = matrix[i][i]
        row_sum = sum(matrix[i]) - diagonal_element
        if diagonal_element < row_sum:
            return "NO"
        
        if diagonal_element > row_sum:
            dominant_count += 1

    if dominant_count > 0:
        return f"YES\n{dominant_count}"
    else:
        return "NO"
    
n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]

print(is_diagonally_dominant(matrix, n))