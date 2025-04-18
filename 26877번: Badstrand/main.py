import sys

def max_segment_length(n, b, prices):
    left = 0
    s = 0
    best = 0
    for right, cost in enumerate(prices):
        s += cost
        while s > b:
            s -= prices[left]
            left += 1
        length = right - left + 1
        if length > best:
            best = length
    return best

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    n, b = data[0], data[1]
    prices = data[2:]
    print(max_segment_length(n, b, prices))

if __name__ == "__main__":
    main()
