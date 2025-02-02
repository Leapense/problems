class ChampernowneCounter:
    def __init__(self, n, k):
        self.n = n
        self.k = k
        self.pow10 = [1] * 7
        for i in range(1, 7):
            self.pow10[i] = (self.pow10[i-1] * 10) % self.k

    def digit_length(self, x):
        if x < 10:
            return 1
        elif x < 100:
            return 2
        elif x < 1000:
            return 3
        elif x < 10000:
            return 4
        elif x < 100000:
            return 5
        else:
            return 6

    def count_divisible(self):
        champer_mod = 0
        count = 0
        for i in range(1, self.n + 1):
            d = self.digit_length(i)
            champer_mod = (champer_mod * self.pow10[d] + i) % self.k
            if champer_mod == 0:
                count += 1
        return count

def solve():
    import sys
    data = sys.stdin.read().strip().split()
    n, k = map(int, data)
    counter = ChampernowneCounter(n, k)
    print(counter.count_divisible())

if __name__ == "__main__":
    solve()