import sys

def main():
    from bisect import bisect_right

    sys.setrecursionlimit(1 << 25)
    input = sys.stdin.read
    data = input().split()

    idx = 0
    n = int(data[idx]); idx +=1
    a = []
    for _ in range(n):
        a.append((int(data[idx]), _+1))  # (value, original index)
        idx +=1
    m = int(data[idx]); idx +=1
    b = []
    for _ in range(m):
        b.append(int(data[idx]))
        idx +=1

    # Separate negative and non-negative a_i's
    negatives = []
    non_negatives = []
    for value, original_idx in a:
        if value <0:
            negatives.append( (value, original_idx) )
        else:
            non_negatives.append( (value, original_idx) )
    
    # Sort negatives in ascending order (most negative first)
    negatives.sort()
    
    # Sort non_negatives in ascending order
    non_negatives.sort()
    
    # Combine the order: negatives first, then non_negatives
    ordered = negatives + non_negatives
    
    # Compute cumulative sums and find the maximum sum
    cumulative = 0
    max_sum = -float('inf')
    for value, _ in ordered:
        cumulative += value
        if cumulative > max_sum:
            max_sum = cumulative
    
    # Sort b for efficient counting
    b_sorted = sorted(b)
    
    # Count number of b_i's <= max_sum
    # Using bisect_right to find the first index where b_i > max_sum
    k = bisect_right(b_sorted, max_sum)
    
    # Extract the order of indices
    order = [idx for (_, idx) in ordered]
    
    # Output
    print(k)
    print(' '.join(map(str, order)))

if __name__ == "__main__":
    main()