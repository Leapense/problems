class MetalHarvestSolver:
    def __init__(self):
        import sys
        self.input = sys.stdin.read().split()
        self.index = 0

    def read_int(self):
        val = int(self.input[self.index])
        self.index += 1
        return val

    def solve(self):
        T = self.read_int()
        for tc in range(1, T + 1):
            N = self.read_int()
            K = self.read_int()
            intervals = []
            for _ in range(N):
                S = self.read_int()
                E = self.read_int()
                intervals.append((E, S))
            intervals.sort()
            count = 0
            last_deployment_end = -1
            for E, S in intervals:
                remaining = E - max(S, last_deployment_end)
                if remaining > 0:
                    num_deployments = (remaining + K - 1) // K
                    count += num_deployments
                    last_deployment_end = max(S, last_deployment_end) + num_deployments * K
            print(f"Case #{tc}: {count}")

if __name__ == "__main__":
    MetalHarvestSolver().solve()