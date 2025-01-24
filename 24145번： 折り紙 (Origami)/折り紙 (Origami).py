import sys
from collections import defaultdict

def main():
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    a = int(data[1])
    b = int(data[2])
    idx = 3

    cell_counts = defaultdict(int)

    for _ in range(n):
        p, q, r, s = map(int, data[idx:idx+4])
        idx += 4
        for x in range(p, r + 1):
            for y in range(q, s + 1):
                key = x * (b + 1) + y
                cell_counts[key] += 1

    max_overlap = 0
    area = 0

    for count in cell_counts.values():
        if count > max_overlap:
            max_overlap = count
            area = 1
        elif count == max_overlap:
            area += 1

    print(max_overlap)
    print(area)

if __name__ == "__main__":
    main()