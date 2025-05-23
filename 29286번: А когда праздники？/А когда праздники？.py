day_to_num = {
    'monday': 0,
    'tuesday': 1,
    'wednesday': 2,
    'thursday': 3,
    'friday': 4,
    'saturday': 5,
    'sunday': 6
}

month_to_num = {
    'january': 1,
    'february': 2,
    'march': 3,
    'april': 4,
    'may': 5,
    'june': 6,
    'july': 7,
    'august': 8,
    'september': 9,
    'october': 10,
    'november': 11,
    'december': 12
}

month_days = {
    1: 31,
    2: 28,
    3: 31,
    4: 30,
    5: 31,
    6: 30,
    7: 31,
    8: 31,
    9: 30,
    10: 31,
    11: 30,
    12: 31
}

def is_leap_year(leap_str):
    return leap_str == 'yes'

def main():
    import sys
    n = int(sys.stdin.readline())
    first_day_str, leap_str = sys.stdin.readline().strip().split()
    leap = is_leap_year(leap_str)

    if leap:
        month_days[2] = 29

    first_day = day_to_num[first_day_str]

    first_days = [0] * 13
    first_days[1] = first_day

    for m in range(2, 13):
        prev_month = m - 1
        first_days[m] = (first_days[prev_month] + month_days[prev_month]) % 7

    for _ in range(n):
        line = sys.stdin.readline().strip().split()
        which = line[0]
        weekday_str = line[1]
        month_str = line[3]

        weekday = day_to_num[weekday_str]
        month = month_to_num[month_str]
        total_days = month_days[month]

        if which == 'first':
            diff = (weekday - first_days[month] + 7) % 7
            date = 1 + diff
        else:
            last_day_weekday = (first_days[month] + total_days - 1) % 7
            diff = (last_day_weekday - weekday + 7) % 7
            date = total_days - diff

        print(date)

if __name__ == '__main__':
    main()