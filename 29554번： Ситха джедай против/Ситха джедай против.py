def find_first_day(n, j, l, s, d):
    # 하루하루 시뮬레이션
    for day in range(100001):  # 최대 100000일을 넘지 않게 설정
        is_jedi_better = True
        
        for i in range(n):
            # 해당 스킬에서 제다이가 시스보다 낮다면, 이 날은 불가능
            if j[i] + l[i] * day < s[i] + d[i] * day:
                is_jedi_better = False
                break
        
        # 모든 스킬에서 제다이가 시스보다 같거나 높다면 그 날을 출력
        if is_jedi_better:
            return day
    
    # 만약 끝까지 없다면, 시스가 이긴 것임
    return "Strong is dark side of the force."

# 입력 받기
n = int(input())
j = list(map(int, input().split()))
l = list(map(int, input().split()))
s = list(map(int, input().split()))
d = list(map(int, input().split()))

# 결과 출력
print(find_first_day(n, j, l, s, d))