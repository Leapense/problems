def solve():
    import sys
    s = sys.stdin.readline().strip()
    
    runs = []
    prev = s[0]
    count = 1
    for c in s[1:]:
        if c == prev:
            count += 1
        else:
            runs.append((prev, count))
            prev = c
            count = 1
    runs.append((prev, count))
    
    new_runs = []
    for char, length in runs:
        if char == '+':
            new_runs.append(('+', length))
        else:
            plus_count = length // 2
            leftover = length % 2
            if plus_count > 0:
                new_runs.append(('+', plus_count))
            if leftover == 1:
                new_runs.append(('-', 1))
    
    merged_runs = []
    for char, length in new_runs:
        if not merged_runs:
            merged_runs.append((char, length))
        else:
            last_char, last_len = merged_runs[-1]
            if char == '+' and last_char == '+':
                merged_runs[-1] = (last_char, last_len + length)
            else:
                merged_runs.append((char, length))
    
    answer = 0
    for char, length in merged_runs:
        if char == '+':
            if length > answer:
                answer = length
    
    print(answer)

if __name__ == "__main__":
    solve()