class MBTIFinder:
    def __init__(self, grid, n, m):
        self.grid = grid
        self.n = n
        self.m = m
        self.mbti_types = {
            "ISTJ", "ISFJ", "INFJ", "INTJ",
            "ISTP", "ISFP", "INFP", "INTP",
            "ESTP", "ESFP", "ENFP", "ENTP",
            "ESTJ", "ESFJ", "ENFJ", "ENTJ"
        }
        self.directions = [
            (-1, 0),
            (1, 0),
            (0, -1),
            (0, 1),
            (-1, -1),
            (-1, 1),
            (1, -1),
            (1, 1)
        ]

    def count_mbti(self):
        count = 0
        for i in range(self.n):
            for j in range(self.m):
                for dr, dc in self.directions:
                    ni = i + 3 * dr
                    nj = j + 3 * dc
                    if 0 <= ni < self.n and 0 <= nj < self.m:
                        s = ''.join(self.grid[i + k * dr][j + k * dc] for k in range(4))
                        if s in self.mbti_types:
                            count += 1
        return count
    
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    N, M = int(data[0]), int(data[1])
    grid = data[2:N+2]
    finder = MBTIFinder(grid, N, M)
    print(finder.count_mbti())

if __name__ == "__main__":
    main()