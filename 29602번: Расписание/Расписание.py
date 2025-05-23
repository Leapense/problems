def schedule_documents(n, deadlines):
    indexed_deadlines = [(deadlines[i], i) for i in range(n)]

    indexed_deadlines.sort()

    result = [0] * n
    current_day = 1

    for deadline, original_index in indexed_deadlines:
        result[original_index] = current_day
        current_day += 1
    
    return result


n = int(input())
deadlines = list(map(int, input().split()))
schedule = schedule_documents(n, deadlines)

print(" ".join(map(str, schedule)))