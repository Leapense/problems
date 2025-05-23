import sys
from bisect import bisect_left

def main():
    input = sys.stdin.read
    data = list(map(int, input().split()))
    n = data[0]
    cows = data[1:]
    lis = []

    for cow in cows:
        pos = bisect_left(lis, cow)
        if pos == len(lis):
            lis.append(cow)
        else:
            lis[pos] = cow
    print(len(lis))

if __name__ == "__main__":
    main()