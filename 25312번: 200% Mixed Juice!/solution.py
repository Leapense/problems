import sys
from math import gcd

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    n = next(it)
    m = next(it)
    items = [(next(it), next(it)) for _ in range(n)]
    max_w = max(w for w, _ in items)
    K = max_w * max_w + 1
    items.sort(key=lambda t: -(t[1] * K // t[0]))
    remaining = m
    full_sum = 0
    part_num = 0
    part_den = 1
    for w, v in items:
        if remaining == 0:
            break
        if remaining >= w:
            full_sum += v
            remaining -= w
        else:
            part_num = v * remaining
            part_den = w
            remaining = 0
            break
    num = full_sum * part_den + part_num
    den = part_den
    g = gcd(num, den)
    num //= g
    den //= g
    sys.stdout.write(f"{num}/{den}\n")

if __name__ == "__main__":
    main()