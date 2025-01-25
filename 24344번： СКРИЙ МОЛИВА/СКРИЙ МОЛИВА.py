class PencilCaseBundle:
    def __init__(self):
        import sys
        data = sys.stdin.read().split()
        self.N = int(data[0])
        self.M = int(data[1])
        self.H = int(data[2])
        self.grid = []
        idx = 3
        for _ in range(self.N):
            row = list(map(int, data[idx:idx+self.M]))
            self.grid.append(row)
            idx += self.M
        self.solve()
        
    def solve(self):
        left_max = [[0]*self.M for _ in range(self.N)]
        right_max = [[0]*self.M for _ in range(self.N)]
        up_max = [[0]*self.M for _ in range(self.N)]
        down_max = [[0]*self.M for _ in range(self.N)]
        for i in range(self.N):
            current_max = 0
            for j in range(self.M):
                current_max = max(current_max, self.grid[i][j])
                left_max[i][j] = current_max
            current_max = 0
            for j in range(self.M-1, -1, -1):
                current_max = max(current_max, self.grid[i][j])
                right_max[i][j] = current_max
        for j in range(self.M):
            current_max = 0
            for i in range(self.N):
                current_max = max(current_max, self.grid[i][j])
                up_max[i][j] = current_max
            current_max = 0
            for i in range(self.N-1, -1, -1):
                current_max = max(current_max, self.grid[i][j])
                down_max[i][j] = current_max
        count = 0
        for i in range(self.N):
            for j in range(self.M):
                if left_max[i][j] >= self.H and right_max[i][j] >= self.H and up_max[i][j] >= self.H and down_max[i][j] >= self.H:
                    count +=1
        print(count)

PencilCaseBundle()
