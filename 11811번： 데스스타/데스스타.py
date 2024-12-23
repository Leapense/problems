n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
result = []

for i in range(n):
    or_val = 0
    for j in range(n):
        if i != j:
            or_val |= matrix[i][j]
    result.append(or_val)
print(' '.join(map(str, result)))