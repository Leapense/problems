import sys
from typing import List, Optional

INF = 10 ** 9

def min_segments(z: str, words: List[str]) -> Optional[int]:
    n = len(z)
    dp = [INF] * (n + 1)
    dp[0] = 0

    buckets = {}
    for w in words:
        buckets.setdefault(w[0], []).append(w)

    for i in range(n):
        if dp[i] == INF:
            continue
        for w in buckets.get(z[i], []):
            L = len(w)
            if i + L <= n and z.startswith(w, i):
                if dp[i] + 1 < dp[i + L]:
                    dp[i + L] = dp[i] + 1
    return None if dp[n] == INF else dp[n]

def _read_int(f):
    return int(f.readline().strip())

def main() -> None:
    it = sys.stdin
    K = _read_int(it)
    for case in range(1, K + 1):
        m = _read_int(it)
        z = it.readline().strip()
        words = [it.readline().strip() for _ in range(m)]
        ans = min_segments(z, words)
        print(f"Data Set {case}:")
        print(ans if ans is not None else "Impossible")

if __name__ == "__main__":
    main()