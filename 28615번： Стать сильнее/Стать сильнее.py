import sys
import bisect

def main():
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    a = list(map(int, data[1:n+1]))

    a_sorted = sorted(a, reverse=True)
    devices = []

    for a_j in a_sorted:
        index = bisect.bisect_left(devices, a_j + 2)
        if index < len(devices):
            devices.pop(index)
        bisect.insort(devices, a_j)
    print(len(devices))

if __name__ == '__main__':
    main()