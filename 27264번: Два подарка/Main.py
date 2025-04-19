import sys

def max_pair_sum(prices, x):
    prices.sort()
    l, r = 0, len(prices) - 1
    best = 0
    while l < r:
        s = prices[l] + prices[r]
        if s > x:
            r -= 1
        else:
            if s > best:
                best = s
            l += 1
    return best

def main():
    data = sys.stdin.read().split()
    n, x = map(int, data[:2])
    prices = list(map(int, data[2:2+n]))
    print(max_pair_sum(prices, x))

if __name__ == "__main__":
    main()