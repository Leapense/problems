def is_fibonacci_subsequence(n, numbers):
    # 수열을 오름차순으로 정렬
    numbers.sort()
    
    # n이 2 이하이면 피보나치 조건을 확인할 필요 없이 "YES"
    if n <= 2:
        return "YES"
    
    # 피보나치 수열의 규칙을 만족하는지 확인
    for i in range(2, n):
        if numbers[i] != numbers[i - 1] + numbers[i - 2]:
            return "NO"
    
    return "YES"

# 입력 처리
n = int(input())  # 수열의 길이
numbers = list(map(int, input().split()))  # 수열의 숫자들

# 결과 출력
print(is_fibonacci_subsequence(n, numbers))