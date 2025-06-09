import sys

def sieve_primes(limit):
    is_prime = [False, False] + [True] * (limit - 1)
    for num in range(2, int(limit ** 0.5) + 1):
        if is_prime[num]:
            for multiple in range(num * num, limit + 1, num):
                is_prime[multiple] = False
    return [i for i, flag in enumerate(is_prime) if flag]

class DisjointSet:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a == root_b:
            return

        if self.rank[root_a] < self.rank[root_b]:
            self.parent[root_a] = root_b
        elif self.rank[root_a] > self.rank[root_b]:
            self.parent[root_b] = root_a
        else:
            self.parent[root_b] = root_a
            self.rank[root_a] += 1

def count_sets(a, b, p):
    size = b - a + 1
    dsu = DisjointSet(size)
    primes = sieve_primes(b)

    for prime in primes:
        if prime < p:
            continue

        start = ((a + prime - 1) // prime) * prime
        prev_index = None

        for value in range(start, b + 1, prime):
            idx = value - a
            if prev_index is not None:
                dsu.union(prev_index, idx)
            prev_index = idx

    roots = {dsu.find(i) for i in range(size)}
    return len(roots)

def main():
    data = sys.stdin.read().strip().split()
    t = int(data[0])
    pos = 1

    for case_number in range(1, t + 1):
        a = int(data[pos])
        b = int(data[pos + 1])
        p = int(data[pos + 2])
        pos += 3

        result = count_sets(a, b, p)
        print(f"Case #{case_number}: {result}")

if __name__ == "__main__":
    main()