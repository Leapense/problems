def max_suitcase_power(n):
    S = n * (n + 1) // 2  # 1부터 n까지의 합

    # S가 홀수이면 직사각형 불가능
    if S % 2 != 0:
        return 0

    target = S // 2
    current_sum = 0
    used_sticks = []

    # 큰 값부터 목표 합(target)까지 더하기
    for i in range(n, 0, -1):
        if current_sum + i <= target:
            current_sum += i
            used_sticks.append(i)
        
        if current_sum == target:
            break

    return sum(used_sticks) * 2  # 직사각형 전체 길이

# 입력
n = int(input().strip())
print(max_suitcase_power(n))