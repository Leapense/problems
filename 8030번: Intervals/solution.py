import sys
input_ = sys.stdin.readline

def merge_intervals(intervals):
    intervals.sort(key=lambda x: x[0])
    merged = []
    current_start, current_end = intervals[0]

    for a, b in intervals[1:]:
        if a <= current_end:
            if b > current_end:
                current_end = b
        else:
            merged.append((current_start, current_end))
            current_start, current_end = a, b

    merged.append((current_start, current_end))
    return merged

def main():
    n = int(input_().strip())
    intervals = [tuple(map(int, input().split())) for _ in range(n)]

    result = merge_intervals(intervals)
    out = []
    for a, b in result:
        out.append(f"{a} {b}")
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()