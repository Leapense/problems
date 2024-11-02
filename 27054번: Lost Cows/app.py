#=====================================================================
#   27054번:    Lost Cows                   
#   @date:   2024-10-28              
#   @link:   https://www.acmicpc.net/problem/27054  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

def find_order(n, smaller_counts):
    order = [None] * n
    available = list(range(1, n + 1))

    for i in range(n - 1, 0, -1):
        count = smaller_counts[i - 1]
        order[i] = available.pop(count)
    order[0] = available[0]

    return order

if __name__ == '__main__':
    n = int(input())
    smaller_counts = [int(input()) for _ in range(n - 1)]
    order = find_order(n, smaller_counts)
    for brand in order:
        print(brand)