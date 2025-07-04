import sys

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    sequence = map(int, data[1:])
    dp = {}
    result = 0
    for value in sequence:
        length = dp.get(value - 1, 0) + 1
        if length > dp.get(value, 0):
            dp[value] = length
        if length > result:
            result = length
    print(result)

if __name__ == "__main__":
    main()