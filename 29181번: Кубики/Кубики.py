n, *rest = map(int, open(0).read().split())
a = rest[:n]

min_h = min(a)
max_h = max(a)

min_actions = float('inf')

for h in range(min_h, max_h + 1):
    s_rem = sum(x - h for x in a if x > h)
    s_add = sum(h - x for x in a if x < h)
    actions = max(s_rem, s_add)
    if actions < min_actions:
        min_actions = actions

print(min_actions)