import sys
import math

def ceil_div_int(n, d):
    if n >= 0:
        return (n + d - 1) // d
    else:
        # n < 0, d > 0
        # math.ceil(n/d) = -floor(-n/d)
        return - ((-n) // d)

def check(k, a, b, T, M):
    L = k * a - T
    R = k * b - T
    m_low = ceil_div_int(L, M)
    m_high = R // M  # 파이썬의 //는 음수에서도 내림
    return m_low <= m_high

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    a = int(data[0])
    b = int(data[1])
    M = 1 << 61
    T = (1 << 60) - 1
    if b <= 0:
        print(-1)
        return
    lo = 1
    # 초기 상한: 최소한 m=0 후보에서 T <= k*b 이므로 k >= ceil(T/b)
    hi = max(ceil_div_int(T, b), M) + 2
    ans = -1
    while lo <= hi:
        mid = (lo + hi) // 2
        if check(mid, a, b, T, M):
            ans = mid
            hi = mid - 1
        else:
            lo = mid + 1
    print(ans)

if __name__ == '__main__':
    main()
