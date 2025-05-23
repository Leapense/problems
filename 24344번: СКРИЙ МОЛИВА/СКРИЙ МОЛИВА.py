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
        N = self.N
        M = self.M
        H = self.H
        grid = self.grid
        left_max = [[0]*M for _ in range(N)]
        right_max = [[0]*M for _ in range(N)]
        up_max = [[0]*M for _ in range(N)]
        down_max = [[0]*M for _ in range(N)]
        for i in range(N):
            current_max = 0
            for j in range(M):
                current_max = max(current_max, grid[i][j])
                left_max[i][j] = current_max
            current_max = 0
            for j in range(M-1, -1, -1):
                current_max = max(current_max, grid[i][j])
                right_max[i][j] = current_max
        for j in range(M):
            current_max = 0
            for i in range(N):
                current_max = max(current_max, grid[i][j])
                up_max[i][j] = current_max
            current_max = 0
            for i in range(N-1, -1, -1):
                current_max = max(current_max, grid[i][j])
                down_max[i][j] = current_max
        count = 0
        for i in range(N):
            for j in range(M):
                if left_max[i][j] >= H and right_max[i][j] >= H and up_max[i][j] >= H and down_max[i][j] >= H:
                    count +=1
        print(count)

PencilCaseBundle()
