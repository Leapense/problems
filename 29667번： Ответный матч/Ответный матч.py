def will_there_be_penalty_shootout():
    # 첫 번째 경기의 스코어보드 입력 받기
    score_first_match = input().split(':')
    A1, B1 = int(score_first_match[0]), int(score_first_match[1])
    
    # 두 번째 경기의 스코어보드 입력 받기
    score_second_match = input().split(':')
    B2, A2 = int(score_second_match[0]), int(score_second_match[1])
    
    # 각 팀의 총 점수 계산
    total_A = A1 + A2
    total_B = B1 + B2
    
    # 승부차기를 할 가능성이 있는지 판단
    if total_A == total_B and A2 == B1:
        return "YES"
    else:
        return "NO"

# 결과 출력
print(will_there_be_penalty_shootout())