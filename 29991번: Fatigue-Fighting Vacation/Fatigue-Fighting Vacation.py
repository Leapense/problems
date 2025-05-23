def count_activities(D, C, R, tiring_activities, invigorating_activities):
    total_activities = 0
    t_idx = 0
    r_idx = 0
    
    while t_idx < C or r_idx < R:
        if t_idx < C and tiring_activities[t_idx] <= D:
            D -= tiring_activities[t_idx]
            t_idx += 1
            total_activities += 1
        elif r_idx < R:
            D += invigorating_activities[r_idx]
            r_idx += 1
            total_activities += 1
        else:
            break
    
    return total_activities

D, C, R = map(int, input().split())
tiring_activities = []
invigorating_activities = []

for _ in range(C):
    tiring_activities.append(int(input()))

for _ in range(R):
    invigorating_activities.append(int(input()))

print(count_activities(D, C, R, tiring_activities, invigorating_activities))