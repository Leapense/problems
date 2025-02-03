import sys
input_data = sys.stdin.read().split()
n = int(input_data[0])
a = list(map(int, input_data[1:n+1]))
m = int(input_data[n+1])
b = list(map(int, input_data[n+2:]))
ones_suffix_a = [0] * (n+1)
ones_suffix_b = [0] * (m+1)

for i in range(n-1, -1, -1):
    ones_suffix_a[i] = ones_suffix_a[i+1] + (1 if a[i] == 1 else 0)
for i in range(m-1, -1, -1):
    ones_suffix_b[i] = ones_suffix_b[i+1] + (1 if b[i] == 1 else 0)
zeros_a = [i for i in range(n) if a[i] == 0]
zeros_b = [i for i in range(m) if b[i] == 0]
max_length = min(ones_suffix_a[0], ones_suffix_b[0])
for k in range(1, min(len(zeros_a), len(zeros_b)) + 1):
    pos_a = zeros_a[k - 1]
    pos_b = zeros_b[k - 1]
    t = min(ones_suffix_a[pos_a+1], ones_suffix_b[pos_b+1])
    max_length = max(max_length, k+t)

sys.stdout.write(str(max_length))