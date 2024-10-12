import heapq
import sys

def main():
    import sys
    import math

    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    a = list(map(float, data[1:n+1]))

    if n == 1:
        print(a[0])
        return
    
    heapq.heapify(a)

    while len(a) > 1:
        x = heapq.heappop(a)
        y = heapq.heappop(a)
        avg = (x + y) / 2
        heapq.heappush(a, avg)

    print("{0:.10f}".format(a[0]).rstrip('0').rstrip('.') if '.' in "{0:.10f}".format(a[0]) else "{0:.10f}".format(a[0]))

if __name__ == "__main__":
    main()