#!/usr/bin/env python3
import sys, bisect

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    
    # Parse N and M.
    N = int(data[0])
    M = int(data[1])
    
    # Build set S from the next M numbers (if any).
    S = set()
    idx = 2
    for _ in range(M):
        S.add(int(data[idx]))
        idx += 1
    
    # Build the list of allowed natural numbers in [1, 1000]
    allowed = [i for i in range(1, 1001) if i not in S]
    # They are already in increasing order.
    n_allowed = len(allowed)
    
    best_diff = 10**18  # A very large number as initial best difference.
    
    # For each pair (x, y) in allowed:
    for x in allowed:
        for y in allowed:
            prod2 = x * y
            # We want to choose z such that prod2 * z is close to N.
            # That is, we want z close to T = N / prod2.
            T = N / prod2  # float value.
            pos = bisect.bisect_left(allowed, T)
            # Check candidate at pos (if exists) and pos-1.
            if pos < n_allowed:
                z = allowed[pos]
                diff = abs(N - prod2 * z)
                if diff < best_diff:
                    best_diff = diff
                    if best_diff == 0:
                        sys.stdout.write("0")
                        return
            if pos > 0:
                z = allowed[pos - 1]
                diff = abs(N - prod2 * z)
                if diff < best_diff:
                    best_diff = diff
                    if best_diff == 0:
                        sys.stdout.write("0")
                        return
    sys.stdout.write(str(best_diff))

if __name__ == '__main__':
    main()