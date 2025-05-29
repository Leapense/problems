import sys
import math

# 각 테스트 케이스마다 초기화될 메모이제이션 딕셔너리
memo_decimal_props = {}

def get_decimal_properties_for_den(denominator):
    """
    분수 1/denominator의 소수부 표현에 대한 속성을 계산합니다.
    반환값: (비순환부의 길이, 순환 마디의 길이)
    """
    if denominator == 0:
        return (0, 0)
    
    # denominator가 1이면 1/1 = 1.0 이므로 소수부 없음.
    if denominator == 1:
        return (0, 0)
    
    if denominator in memo_decimal_props:
        return memo_decimal_props[denominator]
    
    # 비순환부 길이 계산: denominator에 포함된 2와 5의 인수 개수 중 최댓값
    d_copy_for_p2 = denominator
    p2 = 0
    while d_copy_for_p2 > 0 and d_copy_for_p2 % 2 == 0:
        p2 += 1
        d_copy_for_p2 //= 2
    
    d_copy_for_p5 = denominator
    p5 = 0
    while d_copy_for_p5 > 0 and d_copy_for_p5 % 5 == 0:
        p5 += 1
        d_copy_for_p5 //= 5

    len_non_repeat = max(p2, p5)

    # 순환 마디 길이 계산
    den_for_cycle = denominator
    # den_for_cycle에서 모든 2와 5 인수 제거
    while den_for_cycle > 0 and den_for_cycle % 2 == 0:
        den_for_cycle //= 2
    while den_for_cycle > 0 and den_for_cycle % 5 == 0:
        den_for_cycle //= 5

    len_cycle = 0
    if den_for_cycle > 1:
        # 10^k = 1 (mod den_for_cycle)을 만족하는 최소의 k >= 1 찾기
        # (10^k) % den_for_cycle 값을 추적

        # k = 1일 때의 나머지 (10^1 % den_for_cycle)
        current_rem_power_of_10 = 10 % den_for_cycle
        k = 1

        while current_rem_power_of_10 != 1:
            # 이론적으로 k는 den_for_cycle을 넘지 않음 (오일러 토션트 정리)
            # 안전장치로 k > den_for_cycle 검사 (실제로는 불필요할 수 있음)
            if k > den_for_cycle:
                len_cycle = 0
                break

            current_rem_power_of_10 = (current_rem_power_of_10 * 10) % den_for_cycle
            k += 1

            if current_rem_power_of_10 == 0:
                k = 0
                break

        if k > 0 and (current_rem_power_of_10 == 1 or den_for_cycle == 1 and k == 1 and current_rem_power_of_10 == 0):
            if den_for_cycle == 1 and k == 1 and current_rem_power_of_10 == 0:
                len_cycle = 0
            elif current_rem_power_of_10 == 1 and k > 0:
                len_cycle = k

        else:
            len_cycle = 0

    memo_decimal_props[denominator] = (len_non_repeat, len_cycle)
    return len_non_repeat, len_cycle

def solve_all_test_cases():
    global memo_decimal_props

    while True:
        n_str = sys.stdin.readline()
        if not n_str:
            break
        n_limit = int(n_str)

        if n_limit == 0:
            break

        memo_decimal_props.clear()

        for i in range(1, n_limit + 1):
            get_decimal_properties_for_den(i)

        max_overall_len = 0
        if n_limit >= 1:
            max_overall_len = 1

        for a_val in range(1, n_limit + 1):
            for b_val in range(1, n_limit + 1):
                integer_part_val = a_val // b_val
                integer_part_str = str(integer_part_val)
                current_len = len(integer_part_str)
                remainder_numerator = a_val % b_val

                if remainder_numerator == 0:
                    if current_len > max_overall_len:
                        max_overall_len = current_len
                    continue
                current_len += 1

                common_divisor = math.gcd(remainder_numerator, b_val)
                reduced_denominator_for_frac = b_val // common_divisor

                len_non_repeat, len_cycle = get_decimal_properties_for_den(reduced_denominator_for_frac)

                current_len += len_non_repeat
                if len_cycle > 0:
                    current_len += 2
                    current_len += len_cycle

                if current_len > max_overall_len:
                    max_overall_len = current_len

        sys.stdout.write(str(max_overall_len) + "\n")

if __name__ == "__main__":
    solve_all_test_cases()
