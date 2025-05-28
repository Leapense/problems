import sys
from typing import List

MOD: int = 10 ** 9 + 7

def count_konkotenations(word: str) -> int:
    n: int = len(word)
    separators: List[int] = []
    for i in range(1, n - 3):
        if word[i:i+3] == "kot":
            separators.append(i)

    m: int = len(separators)
    dp: List[int] = [0] * (m + 1)
    dp[0] = 1

    left: int = 0
    for k in range(1, m + 1):
        dp[k] = dp[k - 1]
        curr_pos = separators[k - 1]
        threshold = curr_pos - 4

        while left < k and separators[left] <= threshold:
            left += 1

        dp[k] = (dp[k] + dp[left]) % MOD
    
    return dp[m]

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1
    out = []

    for _ in range(t):
        w = data[idx]
        idx += 1
        out.append(str(count_konkotenations(w)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()