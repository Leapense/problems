import sys

def calculate_tax(income, tax_bands_processed, final_tax_rate):
    """
    주어진 소득에 대한 총 세금을 계산한다.

    Args:
        income (float): 세금을 계산할 총 소득.
        tax_bands_processed (list): (상한선, 세율) 튜플의 리스트.
        final_tax_rate (float): 최종 구간 세율 (백분율).

    Returns:
        float: 계산된 총 세금.
    """
    if income <= 0:
        return 0.0
    
    total_tax = 0.0
    last_band_upper_bound = 0.0

    for upper_bound, rate_percent in tax_bands_processed:
        taxable_income_in_this_band = 0
        if income > last_band_upper_bound:
            taxable_amount = min(income, upper_bound) - last_band_upper_bound
            total_tax += taxable_amount * (rate_percent / 100.0)

        last_band_upper_bound = upper_bound
        if income <= upper_bound:
            break

    if income > last_band_upper_bound:
        remaining_income = income - last_band_upper_bound
        total_tax += remaining_income * (final_tax_rate / 100.0)

    return total_tax

def solve_for_friend(earnings, target_net_gift, tax_bands_processed, final_tax_rate):
    """
    이진 탐색을 사용하여 친구에게 주어야 할 세전 증여액을 찾는다.

    Args:
        earnings (float): 친구의 기존 소득.
        target_net_gift (float): 친구가 받아야 할 세후 순수 증여액.
        tax_bands_processed (list): 처리된 세금 구간 정보.
        final_tax_rate (float): 최종 구간 세율.

    Returns:
        float: 계산된 세전 증여액.
    """
    tax_on_earnings = calculate_tax(earnings, tax_bands_processed, final_tax_rate)

    low = 0.0
    high = earnings + target_net_gift * 200000

    for _ in range(100):
        gross_gift_guess = (low + high) / 2.0
        total_income = earnings + gross_gift_guess

        tax_on_total = calculate_tax(total_income, tax_bands_processed, final_tax_rate)
        net_gift_calculated = gross_gift_guess - (tax_on_total - tax_on_earnings)

        if net_gift_calculated < target_net_gift:
            low = gross_gift_guess
        else:
            high = gross_gift_guess

    return high

def main():
    """
    메인 실행 함수. 입력을 받아 문제를 해결하고 결과를 출력한다.
    """

    try:
        num_bands = int(input())
        tax_bands_input = []
        for _ in range(num_bands):
            size, percent = map(float, input().split())
            tax_bands_input.append((size, percent))

        final_tax_rate = float(input())

        num_friends = int(input())
        friends_data = []
        for _ in range(num_friends):
            earnings, target_gift = map(float, input().split())
            friends_data.append((earnings, target_gift))

    except (IOError, ValueError) as e:
        sys.stderr.write(f"입력 처리 중 오류 발생: {e}\n")
        return
    
    tax_bands_processed = []
    cumulative_size = 0.0
    for size, percent in tax_bands_input:
        cumulative_size += size
        tax_bands_processed.append((cumulative_size, percent))

    for earnings, target_net_gift in friends_data:
        result_gift = solve_for_friend(earnings, target_net_gift, tax_bands_processed, final_tax_rate)
        print(f"{result_gift:.10f}")

if __name__ == "__main__":
    main()