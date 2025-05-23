import sys

class BizMarket:
    def __init__(self):
        self.N = 0
        self.M = 0
        self.A = []
        self.B = []
    def read_input(self):
        input = sys.stdin.read().split()
        ptr = 0
        self.N = int(input[ptr])
        self.M = int(input[ptr + 1])
        ptr += 2
        self.A = list(map(int, input[ptr:ptr + self.N]))
        ptr += self.N
        self.B = list(map(int, input[ptr:ptr + self.M]))

    def compute_max_satisfaction(self):
        self.A.sort(reverse=True)
        self.B.sort()
        prefix_A = [0] * (self.N + 1)
        for i in range(1, self.N + 1):
            prefix_A[i] = prefix_A[i - 1] + self.A[i - 1]
        prefix_B = [0] * (self.M + 1)
        for i in range(1, self.M + 1):
            prefix_B[i] = prefix_B[i - 1] + self.B[i - 1]
        
        max_sum = 0
        max_k = min(self.N, self.M)
        for k in range(1, max_k + 1):
            if self.A[k - 1] >= self.B[k - 1]:
                current_sum = prefix_A[k] - prefix_B[k]
                if current_sum > max_sum:
                    max_sum = current_sum
        return max_sum
    def solve(self):
        self.read_input()
        result = self.compute_max_satisfaction()
        print(result)

if __name__ == "__main__":
    BizMarket().solve()