import sys
import bisect

class FenwickTree:
    def __init__(self, size):
        self.N = size
        self.tree = [0] * (self.N + 2)  # 1-based indexing

    def update(self, index, delta=1):
        while index <= self.N:
            self.tree[index] += delta
            index += index & -index

    def query(self, index):
        res = 0
        while index > 0:
            res += self.tree[index]
            index -= index & -index
        return res

    def range_query(self, left, right):
        return self.query(right) - self.query(left - 1)
    
def main():
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])
    K = int(data[1])
    a = list(map(int, data[2:2+N]))

    sorted_a = sorted(list(set(a)))
    mapping = {num: idx + 1 for idx, num in enumerate(sorted_a)}
    M = len(sorted_a)
    ft = FenwickTree(M)

    dp = [0] * N
    dp[0] = 1
    ft.update(mapping[a[0]])

    for i in range(1, N):
        lower = a[i] - K
        upper = a[i] + K

        left = bisect.bisect_left(sorted_a, lower)
        right = bisect.bisect_right(sorted_a, upper) - 1

        if left <= right:
            sum_range = ft.range_query(left + 1, right + 1)

            if sum_range > 0:
                dp[i] = 1
                ft.update(mapping[a[i]])
    print(' '.join(map(str, dp)))

if __name__ == '__main__':
    main()