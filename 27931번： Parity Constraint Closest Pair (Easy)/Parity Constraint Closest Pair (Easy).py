import sys

class Solution:
    def solve(self):
        input_data = sys.stdin.read().split()
        n = int(input_data[0])
        coords = list(map(int, input_data[1:]))
        coords.sort()
        evens = []
        odds = []

        for c in coords:
            if c % 2 == 0:
                evens.append(c)
            else:
                odds.append(c)
        min_even = float('inf')
        if len(evens) >= 2:
            for i in range(1, len(evens)):
                diff = evens[i] - evens[i - 1]
                if diff < min_even:
                    min_even = diff
        if len(odds) >= 2:
            for i in range(1, len(odds)):
                diff = odds[i] - odds[i - 1]
                if diff < min_even:
                    min_even = diff
        if min_even == float('inf'):
            min_even = -1
        min_odd = float('inf')
        for i in range(1, n):
            if (coords[i] % 2) != (coords[i - 1] % 2):
                diff = coords[i] - coords[i - 1]
                if diff < min_odd:
                    min_odd = diff
        if min_odd == float('inf'):
            min_odd = -1
        sys.stdout.write(f"{min_even} {min_odd}")

if __name__ == "__main__":
    Solution().solve()