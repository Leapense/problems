#!/usr/bin/env python3

"""
1) 각 변수의 구간 [v_i, w_i]에 대해 0~4 모듈러 잔여 클래스별 개수를 계산 (c_i 배열)
2) 순환 컨볼루션 DP를 통해 최종적으로 합계가 mod 5로 r인 조합의 개수를 구함
3) f(r) 값을 미리 정의하고 dp[r] * f(r)를 누적하여 최종 합을 출력
"""

import sys

def count_values_mod_5(single_range: tuple) -> list[int]:
    """
    주어진 구간 (v, w) 안에서 정수 x가 가질 수 있는 x % 5 = k (k = 0..4)인 경우의 개수를 계산하여 리스트로 반환
    Args:
        single_range (tuple[int, int]): (v, w) 범위. v <= w, 0 <= v, w <= 100
    
    Returns:
        counts (list[int]): 크기 5인 리스트. counts[k] = 구간 [v, w]에서 x % 5 == k인 정수의 개수
    """
    v, w = single_range
    counts = [0] * 5

    for k in range(5):
        if w >= k:
            upper_count = (w - k) // 5 + 1
        else:
            upper_count = 0

        v_minus_1 = v - 1
        if v_minus_1 >= k:
            lower_count = (v_minus_1 - k) // 5 + 1
        else:
            lower_count = 0

        counts[k] = upper_count - lower_count

    return counts

def compute_final_sum(ranges: list[tuple[int, int]]) -> int:
    """
    주어진 n개의 구간 [(v1, w1), (v2, w2), ..., (vn, wn)]을 입력으로 받아
    모든 (x1, ..., xn)을 순회하면서 f(x1,..., xn)의 합을 DP 방식으로 계산

    1) 각 변수 i마다 counts_i[k] = 범위 [v_i, w_i]에서 'x_i % 5 == k'인 개수를 구한다.
    2) dp[r] 배열을 사용하여 순환 컨볼루션을 수행하고,
       최종적으로 합 === r(mod 5)인 조합 개수를 dp[r]에 기록한다.
    3) f(r) 값을 상수 테이블로 만들어 최종 합을 구한 뒤 반환한다.

    반환값:
        answer (int): 모든 조합에 대해 f(x1, .., xn) 을 더한 최종 결과
    """
    n = len(ranges)
    dp = [0] * 5
    dp[0] = 1

    for i in range(n):
        v_i, w_i = ranges[i]
        c_i = count_values_mod_5((v_i, w_i))

        new_dp = [0] * 5
        for r in range(5):
            subtotal = 0
            for k in range(5):
                prev_rem = (r - k) % 5
                subtotal += dp[prev_rem] * c_i[k]
            new_dp[r] = subtotal
        
        dp = new_dp

    f_values = [1, 4, 5, 5, 4]

    answer = 0
    for r in range(5):
        answer += dp[r] * f_values[r]

    return answer

def main():
    """
    표준 입력으로부터 다음 형식으로 입력을 받는다:
    n v1 w1 v2 w2 ... vn wn
    - n: 변수 개수, 1 <= n <= 1000
    - v_i, w_i: 각 변수 i가 취할 수 있는 범위 (0 <= v_i <= w_i <= 100)

    표준 출력으로 최종 합을 하나 출력한다.
    """
    data = sys.stdin.read().strip().split()
    n = int(data[0])
    ranges = []
    idx = 1
    for _ in range(n):
        v_i = int(data[idx])
        w_i = int(data[idx + 1])
        ranges.append((v_i, w_i))
        idx += 2

    result = compute_final_sum(ranges)
    print(result)

if __name__ == "__main__":
    main()