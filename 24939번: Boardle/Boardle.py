import sys

class BoardleSolver:
    def __init__(self, N, M, Q, queries):
        self.N = N
        self.M = M
        self.Q = Q
        self.queries = queries
        
        self.x_eq = None
        self.y_eq = None
        self.x_low = 1
        self.x_high = N
        self.y_low = 1
        self.y_high = M
        
    def solve(self):
        for query in self.queries:
            x_i, y_i, d_i = query
            if not self.process_query(x_i, y_i, d_i):
                return 0
        
        # Check if final x_eq and y_eq are within grid
        if self.x_eq is not None:
            if self.x_eq < 1 or self.x_eq > self.N:
                return 0
        if self.y_eq is not None:
            if self.y_eq < 1 or self.y_eq > self.M:
                return 0
        
        # Compute count based on constraints
        if self.x_eq is not None and self.y_eq is not None:
            return 1
        elif self.x_eq is not None:
            if self.y_low > self.y_high or self.y_low < 1 or self.y_high > self.M:
                return 0
            return self.y_high - self.y_low + 1
        elif self.y_eq is not None:
            if self.x_low > self.x_high or self.x_low < 1 or self.x_high > self.N:
                return 0
            return self.x_high - self.x_low + 1
        else:
            if (self.x_low > self.x_high) or (self.y_low > self.y_high):
                return 0
            return (self.x_high - self.x_low + 1) * (self.y_high - self.y_low + 1)
    
    def process_query(self, x_i, y_i, d_i):
        if d_i == 1:  # east, y must equal y_i, x > x_i
            if self.y_eq is not None:
                if self.y_eq != y_i:
                    return False
            else:
                self.y_eq = y_i
            
            if self.x_eq is not None:
                if self.x_eq <= x_i:
                    return False
            else:
                new_x_low = max(self.x_low, x_i + 1)
                if new_x_low > self.x_high:
                    return False
                self.x_low = new_x_low
        
        elif d_i == 2:  # west, y must equal y_i, x < x_i
            if self.y_eq is not None:
                if self.y_eq != y_i:
                    return False
            else:
                self.y_eq = y_i
            
            if self.x_eq is not None:
                if self.x_eq >= x_i:
                    return False
            else:
                new_x_high = min(self.x_high, x_i - 1)
                if new_x_high < self.x_low:
                    return False
                self.x_high = new_x_high
        
        elif d_i == 3:  # south, x must equal x_i, y < y_i
            if self.x_eq is not None:
                if self.x_eq != x_i:
                    return False
            else:
                self.x_eq = x_i
            
            if self.y_eq is not None:
                if self.y_eq >= y_i:
                    return False
            else:
                new_y_high = min(self.y_high, y_i - 1)
                if new_y_high < self.y_low:
                    return False
                self.y_high = new_y_high
        
        elif d_i == 4:  # north, x must equal x_i, y > y_i
            if self.x_eq is not None:
                if self.x_eq != x_i:
                    return False
            else:
                self.x_eq = x_i
            
            if self.y_eq is not None:
                if self.y_eq <= y_i:
                    return False
            else:
                new_y_low = max(self.y_low, y_i + 1)
                if new_y_low > self.y_high:
                    return False
                self.y_low = new_y_low
        
        elif d_i == 5:  # northeast: x > x_i, y > y_i
            if self.x_eq is not None:
                if self.x_eq <= x_i:
                    return False
            else:
                new_x_low = max(self.x_low, x_i + 1)
                if new_x_low > self.x_high:
                    return False
                self.x_low = new_x_low
            
            if self.y_eq is not None:
                if self.y_eq <= y_i:
                    return False
            else:
                new_y_low = max(self.y_low, y_i + 1)
                if new_y_low > self.y_high:
                    return False
                self.y_low = new_y_low
        
        elif d_i == 6:  # northwest: x < x_i, y > y_i
            if self.x_eq is not None:
                if self.x_eq >= x_i:
                    return False
            else:
                new_x_high = min(self.x_high, x_i - 1)
                if new_x_high < self.x_low:
                    return False
                self.x_high = new_x_high
            
            if self.y_eq is not None:
                if self.y_eq <= y_i:
                    return False
            else:
                new_y_low = max(self.y_low, y_i + 1)
                if new_y_low > self.y_high:
                    return False
                self.y_low = new_y_low
        
        elif d_i == 7:  # southeast: x > x_i, y < y_i
            if self.x_eq is not None:
                if self.x_eq <= x_i:
                    return False
            else:
                new_x_low = max(self.x_low, x_i + 1)
                if new_x_low > self.x_high:
                    return False
                self.x_low = new_x_low
            
            if self.y_eq is not None:
                if self.y_eq >= y_i:
                    return False
            else:
                new_y_high = min(self.y_high, y_i - 1)
                if new_y_high < self.y_low:
                    return False
                self.y_high = new_y_high
        
        elif d_i == 8:  # southwest: x < x_i, y < y_i
            if self.x_eq is not None:
                if self.x_eq >= x_i:
                    return False
            else:
                new_x_high = min(self.x_high, x_i - 1)
                if new_x_high < self.x_low:
                    return False
                self.x_high = new_x_high
            
            if self.y_eq is not None:
                if self.y_eq >= y_i:
                    return False
            else:
                new_y_high = min(self.y_high, y_i - 1)
                if new_y_high < self.y_low:
                    return False
                self.y_high = new_y_high
        
        elif d_i == 9:  # exact match
            if self.x_eq is not None and self.x_eq != x_i:
                return False
            if self.y_eq is not None and self.y_eq != y_i:
                return False
            
            prev_x_eq = self.x_eq is not None
            prev_y_eq = self.y_eq is not None
            
            self.x_eq = x_i
            self.y_eq = y_i
            
            if not prev_x_eq:
                if x_i < self.x_low or x_i > self.x_high:
                    return False
            if not prev_y_eq:
                if y_i < self.y_low or y_i > self.y_high:
                    return False
        
        return True

def main():
    input = sys.stdin.read().split()
    ptr = 0
    N = int(input[ptr])
    ptr +=1
    M = int(input[ptr])
    ptr +=1
    Q = int(input[ptr])
    ptr +=1
    queries = []
    for _ in range(Q):
        x = int(input[ptr])
        ptr +=1
        y = int(input[ptr])
        ptr +=1
        d = int(input[ptr])
        ptr +=1
        queries.append( (x, y, d) )
    
    solver = BoardleSolver(N, M, Q, queries)
    print(solver.solve())

if __name__ == "__main__":
    main()