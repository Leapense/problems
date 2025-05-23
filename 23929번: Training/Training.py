import sys

class Solution:
    def run(self):
        input = sys.stdin.read().split()
        idx = 0
        T = int(input[idx]); idx += 1
        for tc in range(1, T + 1):
            N, P = int(input[idx]), int(input[idx + 1]); idx += 2
            S = list(map(int, input[idx:idx+N])); idx += N
            S.sort()
            prefix = [0] * (N + 1)
            for i in range(N):
                prefix[i + 1] = prefix[i] + S[i]
            min_coach = float('inf')
            for i in range(P, N + 1):
                total = P * S[i - 1] - (prefix[i] - prefix[i - P])
                if total < min_coach:
                    min_coach = total
            print(f"Case #{tc}: {min_coach}")
Solution().run()