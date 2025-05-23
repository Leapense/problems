import sys
input_data = sys.stdin.read().strip().split()
T = int(input_data[0])
Ns = list(map(int, input_data[1:]))

def num_digits(n):
    return len(str(n))

results = []
for N in Ns:
    if N < 10:
        results.append(0)
        continue
    L = num_digits(N)
    total = 0

    for P in range(2, L):
        power = 10**(P-1)
        T_threshold = (4 * power + 5) // 9
        full_block = power - T_threshold
        total += full_block

    power = 10**(L-1)
    T_threshold = (4 * power + 5) // 9
    block_start = 4 * power + T_threshold
    block_end = 5 * power - 1

    if N >= block_start:
        cnt = min(block_end, N) - block_start + 1
        total += cnt
    results.append(total)

sys.stdout.write("\n".join(str(r) for r in results))