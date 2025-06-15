import sys

def solve():
    try:
        b = int(sys.stdin.readline())
        bands_info = []
        cumulative_bound = 0.0
        for _ in range(b):
            size, percentage = map(float, sys.stdin.readline().split())
            cumulative_bound += size
            bands_info.append({'bound': cumulative_bound, 'rate': percentage / 100.0})
        final_tax_rate = float(sys.stdin.readline()) / 100.0
        f = int(sys.stdin.readline())
        friends_cases = []
        for _ in range(f):
            earnings, target_gift = map(float, sys.stdin.readline().split())
            friends_cases.append({'earnings': earnings, 'target_gift': target_gift})
    except (IOError, ValueError) as e:
        print(f"입력 처리 중 오류 발생: {e}", file=sys.stderr)
        return
    
    for case in friends_cases:
        earnings = case['earnings']
        target_net_gift = case['target_gift']

        required_gift = find_required_gift(earnings, target_net_gift, bands_info, final_tax_rate)
        print(f"{required_gift:.6f}")

def calculate_net_income(total_gross, bands, final_rate):
    total_tax = 0.0
    income_processed = 0.0

    for band in bands:
        band_upper_bound = band['bound']
        band_rate = band['rate']

        if total_gross <= income_processed:
            break

        taxable_in_this_band = min(total_gross, band_upper_bound) - income_processed
        total_tax += taxable_in_this_band * band_rate
        income_processed = band_upper_bound

    if total_gross > income_processed:
        remaining_income = total_gross - income_processed
        total_tax += remaining_income * final_rate

    return total_gross - total_tax

def find_required_gift(earnings, target_net_gift, bands, final_rate):
    net_from_earnings = calculate_net_income(earnings, bands, final_rate)
    target_total_net = net_from_earnings + target_net_gift

    low_gift = 0.0
    high_gift = 2e7

    for _ in range(100):
        mid_gift = (low_gift + high_gift) / 2.0
        total_gross_income = earnings + mid_gift
        current_net_income = calculate_net_income(total_gross_income, bands, final_rate)

        if current_net_income < target_total_net:
            low_gift = mid_gift
        else:
            high_gift = mid_gift

    return high_gift

if __name__ == "__main__":
    solve()