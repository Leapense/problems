import sys
from collections import defaultdict

def longest_subarray(n: int, k: int, arr: list[int]) -> int:
    freq = defaultdict(int)
    left = 0
    best = 0
    for right, value in enumerate(arr):
        freq[value] += 1
        while freq[value] > k:
            freq[arr[left]] -= 1
            left += 1
        best = max(best, right - left + 1)
    return best

def main() -> None:
    data = sys.stdin.buffer.read().split()
    n, k = map(int, data[:2])
    arr = list(map(int, data[2:2+n]))
    print(longest_subarray(n, k, arr))

if __name__ == "__main__":
    main()