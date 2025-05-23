def calculate_total_run_duration():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    total_seconds = 0

    for i in range(1, n + 1):
        mm_ss = data[i]
        minutes, seconds = map(int, mm_ss.split(':'))
        total_seconds += minutes * 60 + seconds

    hours = total_seconds // 3600
    total_seconds %= 3600
    minutes = total_seconds // 60
    seconds = total_seconds % 60

    print(f'{hours:02}:{minutes:02}:{seconds:02}')

calculate_total_run_duration()