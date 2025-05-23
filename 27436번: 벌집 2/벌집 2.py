class Beehive:
    def __init__(self, N):
        self.N = N

    def solve(self):
        if self.N == 1:
            return 1
        left, right = 1, 2000000000
        while left < right:
            mid = (left + right) // 2
            if 1 + 3 * mid * (mid - 1) >= self.N:
                right = mid
            else:
                left = mid + 1
        return left
    
def main():
    import sys
    N = int(sys.stdin.readline().strip())
    beehive = Beehive(N)
    print(beehive.solve())

if __name__ == "__main__":
    main()