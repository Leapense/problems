import sys

class PencilHider:
    def __init__(self):        
        self.read_input()

    def read_input(self):
        input = sys.stdin.read
        data = input().split()
        self.N = int(data[0])
        self.M = int(data[1])
        self.H = int(data[2])
        self.grid = []
        index = 3

        for _ in range(self.N):
            row = list(map(int, data[index:index+self.M]))
            self.grid.append(row)
            index += self.M

    def has_tall_enough_left(self, i, j):
        for col in range(j-1, -1, -1):
            if self.grid[i][col] >= self.H:
                return True
        return False

    def has_tall_enough_right(self, i, j):
        for col in range(j+1, self.M):
            if self.grid[i][col] >= self.H:
                return True
        return False
    
    def has_tall_enough_up(self, i, j):
        for row in range(i-1, -1, -1):
            if self.grid[row][j] >= self.H:
                return True
        return False
    
    def has_tall_enough_down(self, i, j):
        for row in range(i+1, self.N):
            if self.grid[row][j] >= self.H:
                return True
        return False
    
    def count_hidden_columns(self):
        count = 0
        for i in range(self.N):
            for j in range(self.M):
                current_height = self.grid[i][j]
                if self.H <= current_height:
                    count += 1
                else:
                    left = self.has_tall_enough_left(i, j)
                    right = self.has_tall_enough_right(i, j)
                    up = self.has_tall_enough_up(i, j)
                    down = self.has_tall_enough_down(i, j)
                    if left and right and up and down:
                        count += 1
        return count
    
    def process(self):
        result = self.count_hidden_columns()
        print(result)

if __name__ == "__main__":
    hider = PencilHider()
    hider.process()