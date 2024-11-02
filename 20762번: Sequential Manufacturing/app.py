#=====================================================================
#   20762번:    Sequential Manufacturing                   
#   @date:   2024-10-16              
#   @link:   https://www.acmicpc.net/problem/20762  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

N, M = map(int, input().split())
ts = 0; mt = 0
t = list(map(int, input().split()))
for i in range(N):
    ts += t[i]
    mt = max(t[i], mt)

print(ts + (M - 1) * mt)