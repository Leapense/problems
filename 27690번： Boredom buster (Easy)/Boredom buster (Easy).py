class BoredomBuster:
    def __init__(self):
        import sys
        self.input_data = sys.stdin.read().split()
        self.t = int(self.input_data[0])
        self.results = []

    def solve(self):
        index = 1
        for _ in range(self.t):
            n = int(self.input_data[index])
            index += 1
            self.results.append(str((n * (n - 1)) // 2))
        print("\n".join(self.results))

if __name__ == "__main__":
    BoredomBuster().solve()