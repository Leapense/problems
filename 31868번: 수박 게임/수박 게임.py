def max_watermelons(N, K):
    current_fruits = K
    for i in range(1, N):
        current_fruits //= 2
    return current_fruits

# 입력 받기
N, K = map(int, input().split())

# 최대 수박 개수 계산
result = max_watermelons(N, K)

# 결과 출력
print(result)