#=====================================================================
#   25882번:    Simplified Keyboard                   
#   @date:   2024-10-27              
#   @link:   https://www.acmicpc.net/problem/25882  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

keyboard = ["           ", " abcdefghi ", " jklmnopqr ", " stuvwxyz  ", "           "]
mapping = {}

for i in range(3):
    for j in range(9):
        mapping[keyboard[i+1][j+1]] = keyboard[i][j:j+3] + keyboard[i+1][j:j+3] + keyboard[i+2][j:j+3]

cases = int(input())
for a in range(cases):
    words = input().split(" ")
    if words[0] == words[1]:
        print(1)
    elif len(words[0]) != len(words[1]):
        print(3)
    else:
        status = 2
        for i in range(len(words[0])):
            if words[0][i] not in mapping[words[1][i]]:
                status = 3
                break
        print(status)
