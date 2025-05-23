def find_earliest_escape_time(N, M, schedules):
    for time in range(M):
        can_escape = True
        for teacher in range(N):
            if schedules[teacher][time] == 'O':
                can_escape = False
                break
        if can_escape:
            return time + 1
    return "ESCAPE FAILED"

N, M = map(int, input().strip().split())
schedules = [input().strip() for _ in range(N)]

result = find_earliest_escape_time(N, M, schedules)

print(result)