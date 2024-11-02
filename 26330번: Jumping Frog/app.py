#=====================================================================
#   26330번:    Jumping Frog                   
#   @date:   2024-10-27              
#   @link:   https://www.acmicpc.net/problem/26330  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

import math
import sys

def can_reach(x1, y1, x2, y2):
    gcd_start = math.gcd(x1, y1)
    gcd_target = math.gcd(x2, y2)
    return 1 if gcd_start == gcd_target else 0

def main():
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    index = 1

    for _ in range(n):
        x1 = int(data[index])
        y1 = int(data[index + 1])
        x2 = int(data[index + 2])
        y2 = int(data[index + 3])
        index += 4
        result = can_reach(x1, y1, x2, y2)
        print(result)

if __name__ == '__main__':
    main()