def alpha_centauri_calendar(d, m, w, i, j, k):
    # Compute the total number of days before the target day
    total_days = (k - 1) * m * d + (j - 1) * d + (i - 1)
    
    # Calculate the index in the weekday cycle (0-based index)
    weekday_index = total_days % w
    
    # Get the character corresponding to this index, where `a` is 0th index
    result_day = chr(ord('a') + weekday_index)
    
    return result_day

d, m, w = map(int, input().split())
i, j, k = map(int, input().split())
result = alpha_centauri_calendar(d, m, w, i, j, k)

print(result)