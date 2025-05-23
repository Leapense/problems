import sys, heapq

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    idx = 1
    heap = []
    output = []
    for _ in range(n):
        a = int(data[idx])
        idx += 1
        if a == 0:
            if heap:
                val = -heapq.heappop(heap)
                output.append(str(val))
            else:
                output.append("-1")
        else:
            for _ in range(a):
                val = int(data[idx])
                heapq.heappush(heap, -val)
                idx += 1
    print("\n".join(output))

if __name__ == '__main__':
    main()