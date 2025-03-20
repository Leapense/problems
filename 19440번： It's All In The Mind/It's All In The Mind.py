import sys
import math

def main():
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    t = int(input_data[0])
    index = 1
    results = []
    for _ in range(t):
        n = int(input_data[index]); index += 1
        m = int(input_data[index]); index += 1
        
        # Create a list to hold fixed values; use None for free positions.
        fixed = [None] * (n + 1)  # 1-indexed
        
        for _ in range(m):
            pos = int(input_data[index]); index += 1
            val = int(input_data[index]); index += 1
            fixed[pos] = val
        
        # We'll construct the sequence 'seq' that maximizes the ratio.
        seq = [0] * (n + 1)  # 1-indexed
        
        # For positions 1 and 2: if free assign 100, else use the fixed value.
        for i in [1, 2]:
            if fixed[i] is None:
                seq[i] = 100
            else:
                seq[i] = fixed[i]
        
        # Precompute the lower bound L for positions 3 to n via backward pass.
        # L[i] = if fixed then fixed value, else L[i+1] (or 0 for the last element if free)
        L = [0] * (n + 2)  # extra index to avoid boundary issues, 1-indexed
        # For position n:
        if fixed[n] is not None:
            L[n] = fixed[n]
        else:
            L[n] = 0
        
        for i in range(n - 1, 2, -1):
            if fixed[i] is not None:
                L[i] = fixed[i]
            else:
                L[i] = L[i+1]
        
        # Now fill positions 3 to n
        for i in range(3, n + 1):
            if fixed[i] is not None:
                seq[i] = fixed[i]
            else:
                # The minimal possible value is L[i]. 
                # Also, it must be <= seq[i-1] (which is guaranteed by problem consistency).
                seq[i] = L[i]
                
        total = sum(seq[1:])
        numerator = seq[1] + seq[2]
        
        # Reduce the fraction numerator/total
        g = math.gcd(numerator, total)
        p = numerator // g
        q = total // g
        
        results.append(f"{p}/{q}")
    
    sys.stdout.write("\n".join(results))

if __name__ == '__main__':
    main()
