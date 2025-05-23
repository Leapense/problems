import sys
import bisect

class Solution:
    def __init__(self):
        self.T = 0
        self.test_cases = []

    def read_input(self):
        lines = sys.stdin.read().splitlines()
        self.T = int(lines[0])
        self.test_cases = lines[1:self.T + 1]

    def find_substring_positions(self, S, sub):
        positions = []
        start = 0
        while True:
            pos = S.find(sub, start)
            if pos == -1:
                break
            positions.append(pos)
            start = pos + 1
        return positions

    def solve(self):
        self.read_input()
        for idx, S in enumerate(self.test_cases, 1):
            kick_positions = self.find_substring_positions(S, 'KICK')
            start_positions = self.find_substring_positions(S, 'START')
            start_positions_sorted = sorted(start_positions)
            count = 0
            for kp in kick_positions:
                target = kp + 4
                idx_start = bisect.bisect_left(start_positions_sorted, target)
                count += len(start_positions_sorted) - idx_start
            print(f"Case #{idx}: {count}")

if __name__ == "__main__":
    Solution().solve()