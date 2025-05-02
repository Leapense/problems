import sys
from typing import List

def postman(N: int, K: int, d_list: List[int]) -> int:
    """
    N개 집, 시작 집 K, 인접 거리 리스트 d_list (길이 N-1) 를 받아
    페초가 방문하며 이동한 총 거리를 계산하는 함수
    """
    pos = [0] * (N + 1)
    for i in range(2, N + 1):
        pos[i] = pos[i - 1] + d_list[i - 2]

    l, r = K - 1, K + 1
    current = K
    ans = 0

    while l >= 1 or r <= N:
        dist_l = abs(pos[current] - pos[l]) if l >= 1 else 10 ** 18
        dist_r = abs(pos[r] - pos[current]) if r <= N else 10 ** 18

        if dist_l <= dist_r:
            ans += dist_l
            current = l
            l -= 1
        else:
            ans += dist_r
            current = r
            r += 1

    return ans

def solve():
    inp = sys.stdin.readline
    N, K = map(int, inp().split())
    d_list = [int(input()) for _ in range(N - 1)]
    print(postman(N, K, d_list))

if __name__ == "__main__":
    solve()