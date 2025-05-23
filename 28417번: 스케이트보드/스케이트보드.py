def find_winning_score(N, scores):
    max_score = 0
    
    for score in scores:
        run1, run2, trick1, trick2, trick3, trick4, trick5 = score
        best_run = max(run1, run2)
        best_tricks = sorted([trick1, trick2, trick3, trick4, trick5], reverse=True)[:2]
        final_score = best_run + sum(best_tricks)
        
        if final_score > max_score:
            max_score = final_score
    
    return max_score

# 입력 처리
import sys
input = sys.stdin.read
data = input().split()

N = int(data[0])
scores = []

index = 1
for i in range(N):
    scores.append(list(map(int, data[index:index+7])))
    index += 7

# 최종 우승자의 점수 출력
print(find_winning_score(N, scores))