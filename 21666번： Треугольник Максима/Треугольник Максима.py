def find_triangle_frequency_range(n, records):
    # Initial range for the frequency
    low, high = 30.0, 4000.0
    
    prev_freq = records[0][0]
    
    for i in range(1, n):
        current_freq = records[i][0]
        comparison = records[i][1]
        
        if comparison == 'closer':
            if current_freq > prev_freq:
                high = min(high, (prev_freq + current_freq) / 2)
            else:
                low = max(low, (prev_freq + current_freq) / 2)
        elif comparison == 'further':
            if current_freq > prev_freq:
                low = max(low, prev_freq + abs(current_freq - prev_freq) / 2)
            else:
                high = min(high, prev_freq - abs(current_freq - prev_freq) / 2)
        
        prev_freq = current_freq
    
    return low, high

# Reading input
def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split('\n')
    
    n = int(data[0])
    records = []
    
    for i in range(1, n + 1):
        parts = data[i].split()
        freq = float(parts[0])
        if len(parts) > 1:
            comparison = parts[1]
            records.append((freq, comparison))
        else:
            records.append((freq, None))
    
    low, high = find_triangle_frequency_range(n, records)
    
    # Print the result
    print(f"{low:.1f} {high:.1f}")

# Running the main function
if __name__ == "__main__":
    main()
