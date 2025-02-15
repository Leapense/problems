import sys
import bisect

def main():
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    # 입력 파싱
    N = int(input_data[0])
    M = int(input_data[1])
    S = set()
    for i in range(M):
        S.add(int(input_data[2 + i]))
    
    # S에 속하지 않는 가장 작은 자연수 m
    m = 1
    while m in S:
        m += 1

    # 만약 m^3 > N이면 (모든 x,y,z >= m이므로)
    if m**3 > N:
        print(m**3 - N)
        return

    # 탐색 범위: [L, R]
    L = m
    R = N + 100  # 여유 있게 잡음

    # 범위 내에서 S에 속하지 않는 수의 목록 A (정렬됨)
    A = [x for x in range(L, R + 1) if x not in S]
    if not A:
        # A가 빈 경우는 없지만 혹시 모를 상황 처리
        print(abs(N - m**3))
        return

    best = float('inf')
    # A의 길이
    n = len(A)
    
    # 두 수 x,y에 대해 반복
    for i in range(n):
        x = A[i]
        for j in range(n):
            y = A[j]
            prod = x * y
            # 목표: z ~ N / prod
            # 만약 prod > 0 (항상 자연수이므로)
            target = N / prod
            # 이진 탐색으로 A에서 target이 들어갈 위치를 찾음
            pos = bisect.bisect_left(A, target)
            # 후보: pos-1와 pos
            for candidate in [pos-1, pos]:
                if 0 <= candidate < n:
                    z = A[candidate]
                    val = prod * z
                    diff = abs(N - val)
                    if diff < best:
                        best = diff
                        # 최적값이 0이면 더 이상 탐색할 필요 없음.
                        if best == 0:
                            print(0)
                            return
    print(best)

if __name__ == '__main__':
    main()