import sys


def solve():
    """
    알고리즘 수업 - 점근적 표기 4 문제를 해결합니다.
    주어진 f(n), c, n0에 대해 O(n^2) 정의를 만족하는지 확인합니다.
    """
    
    # 입력을 받습니다.
    a2, a1, a0 = map(int, sys.stdin.readline().split())
    c = int(sys.stdin.readline())
    n0 = int(sys.stdin.readline())

    # 문제의 조건: 모든 n >= n0에 대해 a2*n^2 + a1*n + a0 <= c*n^2
    # 부등식을 변형: (c - a2)*n^2 - a1*n - a0 >= 0
    # d(n) = (c - a2)*n^2 - a1*n - a0 이라고 할 때,
    # 모든 n >= n0에 대해 d(n) >= 0 인지 확인합니다.

    # 경우 1: c > a2 (d(n)이 아래로 볼록한 포물선)
    if c > a2:
        # d(n)이 n >= n0에서 항상 0 이상이려면,
        # 1. 시작점 d(n0)가 0 이상이어야 하고,
        # 2. n0에서 기울기가 0 이상이어서 계속 증가해야 합니다.
        
        # 조건 1: d(n0) >= 0
        cond1 = (c - a2) * n0**2 - a1 * n0 - a0 >= 0
        
        # 조건 2: d'(n0) >= 0
        # d'(n) = 2*(c - a2)*n - a1
        cond2 = 2 * (c - a2) * n0 - a1 >= 0
        
        if cond1 and cond2:
            print(1)
        else:
            print(0)
            
    # 경우 2: c == a2 (d(n)이 직선)
    elif c == a2:
        # d(n) = -a1*n - a0
        # 이 직선이 n >= n0에서 항상 0 이상이려면,
        # 1. 시작점 d(n0)가 0 이상이어야 하고,
        # 2. 기울기(-a1)가 0 이상이어야 합니다.
        
        # 조건 1: d(n0) >= 0
        cond1 = -a1 * n0 - a0 >= 0
        
        # 조건 2: 기울기 -a1 >= 0 (즉, a1 <= 0)
        cond2 = a1 <= 0
        
        if cond1 and cond2:
            print(1)
        else:
            print(0)
            
    # 경우 3: c < a2 (d(n)이 위로 볼록한 포물선)
    else:
        # 위로 볼록한 포물선은 n이 커지면 반드시 음수가 되므로,
        # 모든 n >= n0에 대해 0 이상일 수 없습니다.
        print(0)

solve()