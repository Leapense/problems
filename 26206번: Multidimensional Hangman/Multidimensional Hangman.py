import sys
input_data = sys.stdin.read().strip().split()
N = int(input_data[0])
C = int(input_data[1])
patterns = input_data[2:]

from collections import defaultdict
counts = defaultdict(int)

for pattern in patterns:
    unknown_idx = pattern.find('*')
    base = list(pattern)
    for c in range(ord('a'), ord('z') + 1):
        base[unknown_idx] = chr(c)
        word = ''.join(base)
        counts[word] += 1
    base[unknown_idx] = '*'

max_count = 0
best_word = None
for w, cnt in counts.items():
    if cnt > max_count or (cnt == max_count and w < best_word):
        max_count = cnt
        best_word = w

sys.stdout.write(best_word + ' ' + str(max_count) + '\n')
