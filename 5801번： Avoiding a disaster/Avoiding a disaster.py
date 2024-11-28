def time_to_minutes(time_str):
    H, M = map(int, time_str.split(':'))
    if H == 12:
        H_m = 0
    else:
        H_m = H * 60
    return H_m + M

def minutes_to_time(total):
    total = total % 720
    if total == 0:
        H = 12
        M = 0
    else:
        H = (total // 60) % 12
        if H == 0:
            H = 12
        M = total % 60
    return f"{H}:{M:02d}"

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    T = int(data[0])
    for i in range(1, T + 1):
        line = data[i].strip()
        times = line.split()
        if len(times) != 3:
            print("Look at the sun")
            continue
        m1 = time_to_minutes(times[0])
        m2 = time_to_minutes(times[1])
        m3 = time_to_minutes(times[2])

        time_list = [m1, m2, m3]

        possible_correct_times = set()
        for T_candidate in time_list:
            for t_min in time_list:
                if t_min == T_candidate:
                    continue
                x = (T_candidate - t_min) % 720
                if x == 0 or x > 480:
                    continue
                t_plus = (T_candidate + x) % 720
                if t_plus in time_list and t_plus != T_candidate and t_plus != t_min:
                    possible_correct_times.add(T_candidate)
        if len(possible_correct_times) == 1:
            correct_time = possible_correct_times.pop()
            print(f"The correct time is {minutes_to_time(correct_time)}")
        else:
            print("Look at the sun")
if __name__ == '__main__':
    main()