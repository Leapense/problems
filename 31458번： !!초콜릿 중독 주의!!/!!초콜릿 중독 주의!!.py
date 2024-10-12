def calculate_expression(expression):
    # n의 위치를 찾는다
    n_index = 0
    while expression[n_index] == '!':
        n_index += 1

    # n은 expression[n_index] 위치에 있다
    n = int(expression[n_index])
    
    # 앞쪽에 붙은 !의 개수 (논리 반전)
    left_bang_count = n_index
    
    # 뒤쪽에 붙은 !의 개수 (팩토리얼)
    right_bang_count = len(expression) - n_index - 1
    
    # 팩토리얼 적용
    for _ in range(right_bang_count):
        n = 1  # 0! = 1, 1! = 1
    
    # 논리 반전 적용
    for _ in range(left_bang_count):
        n = 1 - n  # !0 = 1, !1 = 0
    
    return n

# 입력 받기
T = int(input())
results = []

for _ in range(T):
    expression = input().strip()
    result = calculate_expression(expression)
    results.append(result)

# 결과 출력
for result in results:
    print(result)
