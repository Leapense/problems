N, m = map(int, input().split())
t2 = N // 2
t3 = (N + 1) // 2
if N <= 2:
    actions = [t2, t3]
else:
    t4 = (N - 1) // 3 + 1
    actions = [t2, t3, t4]
count = 0
num_actions = len(actions)
for s in range(1 << num_actions):
    sum_time = 0
    for i in range(num_actions):
        if (s >> i) & 1:
            sum_time += actions[i]
    if sum_time <= m:
        count +=1
print(count)