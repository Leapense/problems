import sys

def main():
    input = sys.stdin.readline

    N, X = map(int, sys.stdin.readline().split())
    visitors = list(map(int, sys.stdin.readline().split()))

    current_sum = sum(visitors[:X])
    max_sum = current_sum
    count = 1

    for i in range(X, N):
        current_sum += visitors[i] - visitors[i - X]
        if current_sum > max_sum:
            max_sum = current_sum
            count = 1
        elif current_sum == max_sum:
            count += 1

    if max_sum > 0:
        print(max_sum)
        print(count)
    else:
        print("SAD")

if __name__ == "__main__":
    main()