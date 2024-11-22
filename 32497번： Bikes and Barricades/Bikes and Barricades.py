import sys
import math
def main():
    def readints():
        return list(map(int, sys.stdin.readline().split()))
    
    n_and_rest = sys.stdin.read().splitlines()
    if not n_and_rest:
        print(-1.0)
        return
    n = int(n_and_rest[0])
    y_values = []
    for i in range(1, n+1):
        tokens = n_and_rest[i].strip().split()
        if len(tokens) !=4:
            continue
        x1, y1, x2, y2 = map(int, tokens)
        if x1 * x2 >=0:
            # Does not cross Y-axis
            continue
        dx = x2 - x1
        dy = y2 - y1
        t = -x1 / dx

        if t <0 or t >1:
            continue
        y = y1 + dy * t
        if y >=0:
            y_values.append(y)
    if y_values:
        min_y = min(y_values)
        # To ensure precision, format with enough decimal places
        print(min_y)
    else:
        print(-1.0)

if __name__ == '__main__':
    main()