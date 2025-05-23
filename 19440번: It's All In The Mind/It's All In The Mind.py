import sys
import math

def solve():
    input_data = sys.stdin.read().strip().split()
    if not input_data: 
        return
    t = int(input_data[0])
    index = 1
    output_lines = []
    
    for _ in range(t):
        n = int(input_data[index])
        m = int(input_data[index+1])
        index += 2
        
        # Prepare an array for the sequence (1-indexed for simplicity)
        a = [None] * (n + 1)
        fixed = [False] * (n + 1)
        
        # Process fixed elements
        for _ in range(m):
            pos = int(input_data[index])
            val = int(input_data[index+1])
            index += 2
            a[pos] = val
            fixed[pos] = True
        
        # Set a1 and a2: if they are not fixed, assign 100.
        if not fixed[1]:
            a[1] = 100
        if not fixed[2]:
            a[2] = 100
        
        # For indices 3 to n, if fixed use given value; if unknown assign 0 initially.
        for i in range(3, n+1):
            if not fixed[i]:
                a[i] = 0

        # Backward propagation for indices 3..n to ensure non-increasing order:
        for i in range(n-1, 2, -1):
            if a[i] < a[i+1]:
                if not fixed[i]:
                    a[i] = a[i+1]
        
        # Ensure non-increasing order between a2 and a3 (only if n >= 3)
        if n >= 3 and a[2] < a[3]:
            a[3] = a[2]
        
        # Calculate numerator and denominator.
        num = a[1] + a[2]
        total = sum(a[1: n+1])
        
        # Reduce the fraction to its irreducible form.
        g = math.gcd(num, total)
        num //= g
        total //= g
        
        output_lines.append(f"{num}/{total}")
    
    sys.stdout.write("\n".join(output_lines))


if __name__ == '__main__':
    solve()
