def convert_to_minutes(time_str):
    h, m = map(int, time_str.split(':'))
    return h * 60 + m

def compute_effective_times(depart_str, arrive_str):
    dep = convert_to_minutes(depart_str)
    arr = convert_to_minutes(arrive_str)
    if arr < dep:
        arr += 1440

    return dep, arr + 1

import sys

def main():
    data = sys.stdin.read().strip().splitlines()
    if not data:
        return
    n = int(data[0].strip())

    trips_from_zagreb = []
    trips_from_graz = []

    for line in data[1:n+1]:
        parts = line.strip().split()
        route = parts[0]
        times = parts[1]

        depart_time, arrive_time = times.split('--')
        city_from, city_to = route.split('-')

        if city_from == "Zagreb" and city_to == "Graz":
            dep, eff_arr = compute_effective_times(depart_time, arrive_time)
            trips_from_zagreb.append((dep, eff_arr))
        elif city_from == "Graz" and city_to == "Wroclaw":
            base_dep, eff_arr = compute_effective_times(depart_time, arrive_time)
            trips_from_graz.append((base_dep, eff_arr))

    best_time = None

    for dep1, eff_arr1 in trips_from_zagreb:
        for base_dep2, base_eff_arr2 in trips_from_graz:
            if base_dep2 > eff_arr1:
                k = 0
            else:
                k = (eff_arr1 - base_dep2) // 1440 + 1

            abs_dep2 = base_dep2 + k * 1440

            if abs_dep2 <= eff_arr1:
                continue

            abs_eff_arr2 = base_eff_arr2 + k * 1440
            total_time = abs_eff_arr2 - dep1
            if best_time is None or total_time < best_time:
                best_time = total_time

    if best_time is None:
        print("NEMOGUCE")
    else:
        hours = best_time // 60
        minutes = best_time % 60
        print(f"{hours}:{minutes:02d}")

if __name__ == "__main__":
    main()