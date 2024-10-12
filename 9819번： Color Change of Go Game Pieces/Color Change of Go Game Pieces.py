import sys

def count_whites(n, m, k):
    mask = ((1 << m) -1) << (n - m)
    for _ in range(k):
        new_mask = 0
        for i in range(n):
            a = (mask >> (n-1-i)) &1
            if i < n-1:
                b_pos = n-2-i
            else:
                b_pos = n-1
            b = (mask >> b_pos) &1
            newi = a ^ b
            new_mask |= (newi << (n-1-i))
        mask = new_mask
    return bin(mask).count('1')

for line in sys.stdin:
    line = line.strip()
    if line == "-1":
        break
    parts = line.split(',')
    n, m, k = map(int, parts)
    result = count_whites(n, m, k)
    print(f"{n},{m},{k}: {result}")