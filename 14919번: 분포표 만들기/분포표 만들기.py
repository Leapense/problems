def solve():
    import sys

    input_data = sys.stdin.read().strip().split()
    m = int(input_data[0])
    a_values = list(map(float, input_data[1:]))
    counts = [0] * m
    for a in a_values:
        idx = int(a * m)
        if idx == m:
            idx = m - 1
        counts[idx] += 1
    
    print(" ".join(map(str, counts)))

if __name__ == '__main__':
    solve()