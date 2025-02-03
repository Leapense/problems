class ParityConstraintClosestPair:
    def __init__(self, points):
        self.points = points

    def solve(self):
        self.points.sort()
        min_even = float('inf')
        min_odd = float('inf')

        for i in range(1, len(self.points)):
            diff = self.points[i] - self.points[i - 1]
            if diff % 2 == 0:
                if diff < min_even:
                    min_even = diff
            else:
                if diff < min_odd:
                    min_odd = diff
        if min_even == float('inf'):
            min_even = -1
        if min_odd == float('inf'):
            min_odd = -1
        return min_even, min_odd
    
if __name__ == "__main__":
    import sys
    input_data = sys.stdin.read().split()
    n = int(input_data[0])
    points = list(map(int, input_data[1:]))
    solver = ParityConstraintClosestPair(points)
    even, odd = solver.solve()
    sys.stdout.write(f"{even} {odd}")