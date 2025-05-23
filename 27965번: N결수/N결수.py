class N결수모듈러:
    def __init__(self, N, K):
        self.N = N
        self.K = K

    def solve(self):
        res = 0
        digit_length = 1
        next_threshold = 10
        mod10 = pow(10, digit_length, self.K)
        for i in range(1, self.N + 1):
            if i == next_threshold:
                digit_length += 1
                next_threshold *= 10
                mod10 = pow(10, digit_length, self.K)
            res = (res * mod10 + i) % self.K
        return res
    
if __name__ == "__main__":
    import sys
    input_data = sys.stdin.read().split()
    N = int(input_data[0])
    K = int(input_data[1])
    solver = N결수모듈러(N, K)
    result = solver.solve()
    sys.stdout.write(str(result))