from collections import Counter

def smallest_missing_number(digits):
    # 주어진 숫자 카운트
    digit_count = Counter(digits)
    
    # 1부터 숫자를 하나씩 만들 수 있는지 확인
    current = 1
    
    while True:
        # 숫자를 문자열로 변환하여 각 자리의 숫자를 확인
        str_current = str(current)
        temp_count = Counter(str_current)
        
        # 필요한 숫자가 충분히 있는지 확인
        can_form = True
        for digit, count in temp_count.items():
            if digit_count[digit] < count:
                can_form = False
                break
        
        if not can_form:
            return current
        else:
            # 가능한 경우 숫자를 1 증가시켜 다음 숫자로 넘어감
            current += 1

# 입력 예시 테스트
input_str = input().strip()
print(smallest_missing_number(input_str))
