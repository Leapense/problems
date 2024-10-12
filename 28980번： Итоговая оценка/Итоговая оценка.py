grades = input().strip()

# 각 성적을 숫자 값으로 변환 (A=1, B=2, ..., Z=26)
grade_values = [ord(grade) - ord('A') + 1 for grade in grades]

# 평균 계산
average = sum(grade_values) / len(grade_values)

# 소수 부분 추출
fractional_part = average - int(average)

# 학생에게 유리한 반올림 규칙 적용
if fractional_part > 0.5:
    final_grade_num = int(average) + 1
else:
    final_grade_num = int(average)

# 최악의 성적 계산 (숫자 값이 가장 큰 성적)
worst_grade_num = max(grade_values)

# 최종 성적은 최악의 성적보다 한 단계 이상 좋을 수 없음
# 즉, 숫자 값이 (최악의 성적 값 - 1)보다 작을 수 없음
minimum_final_grade_num = worst_grade_num - 1
if final_grade_num < minimum_final_grade_num:
    final_grade_num = minimum_final_grade_num

# 숫자 값을 다시 문자로 변환
final_grade_letter = chr(ord('A') + final_grade_num - 1)

print(final_grade_letter)