import sys
import re

def next_term(n_str):
    """
    현재 항 n_str(문자열)으로부터 다음 항을 생성한다.
    1. n_str의 역순 문자열을 구함.
    2. 두 수를 더함.
    3. 합의 각 자릿수를 오름차순 정렬하고, 정수 변환을 통해 선행 0을 제거한 후 문자열로 변환.
    """
    rev_str = n_str[::-1]
    total = int(n_str) + int(rev_str)
    sorted_str = ''.join(sorted(str(total)))
    # int 변환을 통해 선행하는 0을 제거 (단, total이 0이면 "0")
    return str(int(sorted_str))

def is_chain(s):
    """
    s가 연쇄(chain) 상태인지 판단.
    패턴:
      - "12"로 시작, 하나 이상의 "3", "4444"로 끝나는 경우
      - "55"로 시작, 하나 이상의 "6", "7777"로 끝나는 경우
    """
    pattern1 = re.compile(r"^12(3+)4444$")
    pattern2 = re.compile(r"^55(6+)7777$")
    return pattern1.match(s) or pattern2.match(s)

def process_test_case(M, start):
    # seen: 항을 저장(문자열)하고, 처음 등장한 인덱스 (1부터 시작)
    seen = {}
    current = start
    for i in range(1, M + 1):
        # 반복 판별: 현재 항이 이미 등장한 경우
        if current in seen:
            return f"R {i}"
        seen[current] = i

        # 연쇄 판별
        if is_chain(current):
            return f"C {i}"

        # M번째 항이면 결과 반환
        if i == M:
            return current

        current = next_term(current)
    
    return current

def main():
    input_lines = sys.stdin.read().splitlines()
    t = int(input_lines[0])
    results = []
    for line in input_lines[1: t+1]:
        if not line.strip():
            continue
        parts = line.split()
        M = int(parts[0])
        start = parts[1].lstrip('0')  # 선행 0 제거
        if start == "":
            start = "0"
        result = process_test_case(M, start)
        results.append(result)
    sys.stdout.write("\n".join(results))

if __name__ == '__main__':
    main()
