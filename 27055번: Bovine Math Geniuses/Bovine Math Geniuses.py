class BovineMath:
    def __init__(self, start):
        self.start = start

    def next_num(self, x):
        s = f"{x:06d}"
        mid = int(s[1:5])
        sq = mid * mid
        return sq % 1000000
    
    def solve(self):
        visited = [-1] * 1000000
        n = self.start
        visited[n] = 0
        iteration = 0
        while True:
            iteration += 1
            n = self.next_num(n)
            if visited[n] == -1:
                visited[n] = iteration
            else:
                first_loop_num = n
                loop_length = iteration - visited[n]
                print(first_loop_num, loop_length, iteration)
                break

if __name__ == "__main__":
    start_number = int(input().strip())
    solver = BovineMath(start_number)
    solver.solve()