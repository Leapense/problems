import sys

def main():
    input = sys.stdin.read().split()
    idx = 0
    t = int(input[idx]); idx += 1
    results = []
    for _ in range(t):
        k = int(input[idx]); idx += 1
        a = list(map(int, input[idx:idx+7])); idx += 7
        classes_per_week = sum(a)
        if classes_per_week == 0:
            results.append(-1)
            continue

        full_weeks = k // classes_per_week
        remaining_classes = k % classes_per_week

        if remaining_classes == 0:
            full_weeks -= 1
            remaining_classes = classes_per_week

        min_extra_days = 7 * 7
        for start_day in range(7):
            classes_attended = 0
            day_count = 0
            while classes_attended < remaining_classes:
                current_day = (start_day + day_count) % 7
                if a[current_day] == 1:
                    classes_attended += 1
                day_count += 1
            if day_count < min_extra_days:
                min_extra_days = day_count
        total_days = full_weeks * 7 + min_extra_days
        results.append(total_days)
    for res in results:
        print(res)

main()