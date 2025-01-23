import sys, itertools

class InconstantOrdering:
    def __init__(self):
        self.T = 0
        self.test_cases = []
    
    def read_input(self):
        input = sys.stdin.read().split()
        idx = 0
        self.T = int(input[idx]); idx +=1
        for _ in range(self.T):
            N = int(input[idx]); idx +=1
            L = list(map(int, input[idx:idx+N])); idx +=N
            self.test_cases.append((N, L))
    
    def solve(self):
        for tc, (N, L) in enumerate(self.test_cases, 1):
            current_dp = {65: 'A'}
            for i in range(1, N+1):
                next_dp = {}
                Li = L[i-1]
                for last_letter, s in current_dp.items():
                    if i %2 ==1:
                        start = last_letter +1
                        end = 90
                        if Li >0:
                            end = 90 - (Li -1)
                        for comb in itertools.combinations(range(start, 91), Li):
                            letters = ''.join(chr(c) for c in comb)
                            new_last = comb[-1]
                            new_s = s + letters
                            if new_last not in next_dp or new_s < next_dp[new_last]:
                                next_dp[new_last] = new_s
                    else:
                        p1_min = 65 + Li -1
                        p1_max = last_letter -1
                        for p1 in range(p1_min, p1_max+1):
                            new_last = p1 - (Li -1)
                            if new_last <65:
                                continue
                            letters = ''.join(chr(p1 - j) for j in range(Li))
                            new_s = s + letters
                            if new_last not in next_dp or new_s < next_dp[new_last]:
                                next_dp[new_last] = new_s
                current_dp = next_dp
            result = min(current_dp.values())
            print(f"Case #{tc}: {result}")

if __name__ == "__main__":
    solver = InconstantOrdering()
    solver.read_input()
    solver.solve()
