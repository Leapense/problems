import sys
from functools import lru_cache

def main():
    T = int(sys.stdin.readline())
    for _ in range(T):
        S = sys.stdin.readline().strip()
        n = len(S)
        @lru_cache(None)
        def dfs(i, prev):
            if i == n:
                return 1
            total = 0

            for j in range(i + 1, n + 1):
                substr = S[i:j]
                current = int(substr, 16)
                if prev is None or current >= prev:
                    total += dfs(j, current)
            return total
        print(dfs(0, None))

if __name__ == "__main__":
    main()