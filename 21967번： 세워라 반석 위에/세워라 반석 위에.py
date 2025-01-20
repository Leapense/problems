import sys
from collections import defaultdict

def main():
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])
    A = list(map(int, data[1:]))
    freq = [0] * 11
    left = 0
    max_length = 0
    current_min = A[0]
    current_max = A[0]

    for right in range(N):
        freq[A[right]] += 1
        if A[right] < current_min:
            current_min = A[right]
        if A[right] > current_max:
            current_max = A[right]
        while current_max - current_min > 2:
            freq[A[left]] -= 1
            if A[left] == current_min or A[left] == current_max:
                while current_min <= 10 and freq[current_min] == 0:
                    current_min += 1
                while current_max >= 1 and freq[current_max] == 0:
                    current_max -= 1

            left += 1
        max_length = max(max_length, right - left + 1)
    print(max_length)

if __name__ == "__main__":
    main()