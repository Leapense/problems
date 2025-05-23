def time_to_seconds(t):
    h, m, s = map(int, t.split(":"))
    return h * 3600 + m * 60 + s

import sys
N, *lines = sys.stdin.read().splitlines()
N = int(N)
events = []
for line in lines:
    entry, exit = line.split()
    events.append((time_to_seconds(entry), 0))
    events.append((time_to_seconds(exit), 1))

events.sort()
current = max_count = 0

for time, typ in events:
    if typ == 0:
        current += 1
        if current > max_count:
            max_count = current
    else:
        current -= 1

print(max_count)