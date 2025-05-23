def print_enlarged_matrix(K):
    # 원본 행렬 정의
    original_matrix = [
        "G...",
        ".I.T",
        "..S."
    ]
    
    # 원본 행렬의 크기
    original_rows = len(original_matrix)
    original_cols = len(original_matrix[0])
    
    # 확대된 행렬 저장
    enlarged_matrix = []
    
    # 각 원소를 KxK 크기로 확대
    for row in original_matrix:
        for _ in range(K):
            enlarged_row = ""
            for char in row:
                enlarged_row += char * K
            enlarged_matrix.append(enlarged_row)
    
    # 확대된 행렬 출력
    for row in enlarged_matrix:
        print(row)

# 입력 받기
K = int(input())

# 확대된 행렬 출력
print_enlarged_matrix(K)