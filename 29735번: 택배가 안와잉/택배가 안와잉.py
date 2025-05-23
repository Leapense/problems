def parse_time(time_str):
    hh, mm = map(int, time_str.split(':'))
    return hh * 60 + mm

def format_time(minutes):
    hh = (minutes // 60) % 24
    mm = minutes % 60
    return f'{hh:02d}:{mm:02d}'

def main():
    start_time_str, end_time_str = input().split()
    N_str, T_str = input().split()
    N = int(N_str)
    T = int(T_str)

    start_time = parse_time(start_time_str)
    end_time = parse_time(end_time_str)

    # Compute number of deliveries per day
    deliveries_per_day = 0
    k = 0
    while True:
        delivery_start = start_time + k * T
        delivery_end = delivery_start + T
        if delivery_end >= end_time:
            break
        deliveries_per_day += 1
        k += 1

    total_packages_to_deliver = N + 1  # Including 브실이's package

    total_days_needed = (total_packages_to_deliver - 1) // deliveries_per_day + 1
    packages_delivered_before_last_day = (total_days_needed - 1) * deliveries_per_day
    packages_on_last_day = total_packages_to_deliver - packages_delivered_before_last_day

    delivery_time = start_time + packages_on_last_day * T

    # Adjust if the delivery time exceeds end time
    if delivery_time > end_time:
        total_days_needed += 1
        delivery_time = start_time + (packages_on_last_day % deliveries_per_day) * T

    # Format the delivery time
    delivery_time_formatted = format_time(delivery_time)

    days_after = total_days_needed - 1

    print(days_after)
    print(delivery_time_formatted)

if __name__ == '__main__':
    main()
