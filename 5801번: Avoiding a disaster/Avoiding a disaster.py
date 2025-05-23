def parse_time(time_str):
    h, m = map(int, time_str.split(':'))
    return ((h % 12) * 60) + m

def format_time(t):
    h = (t // 60) % 12
    h = 12 if h == 0 else h
    m = t % 60
    return f"{h}:{m:02d}"

T = int(input())
for _ in range(T):
    times = input().split()
    minutes = [parse_time(t) for t in times]
    possible = set()
    for i in range(3):
        t = minutes[i]
        other = [minutes[j] for j in range(3) if j != i]
        t1, t2 = other
        x1 = (t1 - t) % 720
        x2 = (t - t2) % 720
        if x1 == x2 and 0 < x1 <= 480:
            possible.add(t)
        x1 = (t2 - t) % 720
        x2 = (t - t1) % 720
        if x1 == x2 and 0 < x1 <= 480:
            possible.add(t)
    if len(possible) == 1:
        correct_time = format_time(possible.pop())
        print(f"The correct time is {correct_time}")
    else:
        print("Look at the sun")