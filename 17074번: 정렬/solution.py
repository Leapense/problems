import sys
input = sys.stdin.readline

def main():
    N = int(input())
    a = list(map(int, input().split()))
    prefix_ok = [True] * N
    for i in range(1, N):
        if not prefix_ok[i - 1] or a[i - 1] > a[i]:
            prefix_ok[i] = False
    suffix_ok = [True] * N
    for i in range(N - 2, -1, -1):
        if not suffix_ok[i + 1] or a[i] > a[i + 1]:
            suffix_ok[i] = False
    count = 0
    for i in range(N):
        left_ok = (i == 0) or prefix_ok[i - 1]
        right_ok = (i == N - 1) or suffix_ok[i + 1]
        if not (left_ok and right_ok):
            continue
        if i == 0 or i == N - 1 or a[i - 1] <= a[i + 1]:
            count += 1
    print(count)

if __name__ == "__main__":
    main()