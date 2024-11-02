#=====================================================================
#   26770번:    Basen                   
#   @date:   2024-10-27              
#   @link:   https://www.acmicpc.net/problem/26770  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

import sys

def minimal_pool_lengths():
    def input():
        return sys.stdin.read()
    
    data = input().split()
    N = int(data[0])
    P = list(map(int, data[1:N+1]))

    L = max(P)
    traverse_count = 1

    direction = 'forward'

    prev = 0
    for pos in P:
        if direction == 'forward':
            if pos < prev and pos < L:
                traverse_count += 1
                direction = 'backward'
        else:
            if pos > prev and pos > 0:
                traverse_count += 1
                direction = 'forward'
        prev = pos
    print(traverse_count)

if __name__ == '__main__':
    minimal_pool_lengths()