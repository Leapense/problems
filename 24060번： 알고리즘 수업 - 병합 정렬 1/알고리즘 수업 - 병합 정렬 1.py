import sys
sys.setrecursionlimit(10 ** 7)

class MergeSortCounter:
    def __init__(self, array, k):
        self.A = array
        self.k = k
        self.count = 0
        self.result = -1
        self.found = False
        self.tmp = [0] * len(array)

    def sort(self):
        self.merge_sort(0, len(self.A) - 1)

    def merge_sort(self, p, r):
        if p < r and not self.found:
            q = (p + r) // 2
            self.merge_sort(p, q)
            self.merge_sort(q + 1, r)
            self.merge(p, q, r)

    def merge(self, p, q, r):
        i = p
        j = q + 1
        t = 0

        while i <= q and j <= r and not self.found:
            if self.A[i] <= self.A[j]:
                self.tmp[t] = self.A[i]
                i += 1
            else:
                self.tmp[t] = self.A[j]
                j += 1
            t += 1

        while i <= q and not self.found:
            self.tmp[t] = self.A[i]
            i += 1
            t += 1
        
        while j <= r and not self.found:
            self.tmp[t] = self.A[j]
            j += 1
            t += 1

        i = p
        t = 0
        while i <= r and not self.found:
            self.A[i] = self.tmp[t]
            self.count += 1
            if self.count == self.k:
                self.result = self.A[i]
                self.found = True
                return
            i += 1
            t += 1

def main():
    input = sys.stdin.read
    data = input().split()

    N = int(data[0])
    K = int(data[1])
    A = list(map(int, data[2:2 + N]))

    sorter = MergeSortCounter(A, K)
    sorter.sort()

    print(sorter.result)

if __name__ == "__main__":
    main()