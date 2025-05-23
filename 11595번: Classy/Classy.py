n = int(input())
data = []
max_len = 0

for _ in range(n):
    line = input().strip()
    name, cl = line.split(': ')
    cl = cl[:-6]
    levels = cl.split()[::-1]
    max_len = max(max_len, len(levels))
    data.append((name, levels))

mapping = {'upper': 0, 'middle': 1, 'lower': 2}
result = []

for name, levels in data:
    levels += ["middle"] * (max_len - len(levels))
    numeric = [mapping[level] for level in levels]
    result.append((numeric, name))

result.sort(key=lambda x: (x[0], x[1]))

for _, name in result:
    print(name)