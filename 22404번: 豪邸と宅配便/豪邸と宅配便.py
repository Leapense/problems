def max_study_time(N, M, T, delivery_times):
    max_time = 0
    current_time = 0  # start at time = 0

    for a in delivery_times:
        leave_time = a - M
        if leave_time > current_time:
            max_time += leave_time - current_time
        current_time = a + M
    
    # After the last delivery, add time until T if possible
    if current_time < T:
        max_time += T - current_time
    
    return max_time

N, M, T = map(int, input().split())
delivery_times = list(map(int, input().split()))
result = max_study_time(N, M, T, delivery_times)
print(result)