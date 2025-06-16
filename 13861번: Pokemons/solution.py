import sys

def solve():
    try:
        money_str = sys.stdin.readline()
        if not money_str:
            return
        initial_money = float(money_str)

        n_str = sys.stdin.readline()
        if not n_str:
            return
        num_days = int(n_str)

        if num_days < 2:
            print("0.00")
            return
        
        price_stream = map(float, sys.stdin.readline().split())
        min_price_so_far = next(price_stream)

        try:
            second_price = next(price_stream)
            max_ratio = second_price / min_price_so_far
            min_price_so_far = min(min_price_so_far, second_price)
            remaining_days = num_days - 2
        except StopIteration:
            print("0.00")
            return
    except (ValueError, IndexError):
        return
    
    for _ in range(remaining_days):
        try:
            current_price = next(price_stream)
        except StopIteration:
            break

        current_ratio = current_price / min_price_so_far
        if current_ratio > max_ratio:
            max_ratio = current_ratio
        
        if current_price < min_price_so_far:
            min_price_so_far = current_price

    max_profit = initial_money * (max_ratio - 1.0)
    print(f"{max_profit:.2f}")

if __name__ == "__main__":
    solve()