import sys

input_data = sys.stdin.read().split()
m = int(input_data[0])
weights = list(map(int, input_data[1:]))

max_weight = 20000
freq = [0] * (max_weight + 1)
for w in weights:
    freq[w] += 1

total = sum(w * freq[w] for w in range(max_weight + 1))
prefix = 0

for t in range(1, max_weight + 2):
    if t - 1 >= 0:
        prefix += (t - 1) * freq[t - 1]
    if 2 * prefix + t * freq[t] == total:
        sys.stdout.write(str(t))
        break