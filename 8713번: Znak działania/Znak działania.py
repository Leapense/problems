def biggest_op(a, b):
    # 연산 결과 계산
    results = [a+b, a-b, a*b]
    max_value = max(results)
    
    # 최대값이 여러 번 나타나는지 확인
    if results.count(max_value) > 1:
        return -1  # 여러 연산이 같은 최대 결과를 가짐
    else:
        return results.index(max_value)  # 최대값을 주는 연산의 인덱스 반환

def format_number(num):
    # 숫자를 문자열로 변환하고, 음수는 괄호로 감쌈
    if num < 0:
        return f"({num})"
    return str(num)

def main():
    # 입력 받기
    a, b = map(int, input().split())
    operation_index = biggest_op(a, b)
    
    # 결과 출력
    if operation_index == 0:
        print(f"{format_number(a)}+{format_number(b)}={format_number(a+b)}")
    elif operation_index == 1:
        print(f"{format_number(a)}-{format_number(b)}={format_number(a-b)}")
    elif operation_index == 2:
        print(f"{format_number(a)}*{format_number(b)}={format_number(a*b)}")
    else:
        print("NIE")

if __name__ == "__main__":
    main()
