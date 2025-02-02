class CowLaundrySolver:
    def __init__(self, n, wires):
        self.n = n
        self.top = []
        self.bottom = []
        for t, b in wires:
            self.top.append(t)
            self.bottom.append(b)

    def solve(self):
        pos_in_bottom = [0] * (self.n + 1)
        for i in range(self.n):
            pos_in_bottom[self.bottom[i]] = i + 1

        sequence = []
        for i in range(self.n):
            sequence.append(pos_in_bottom[self.top[i]])
        return self.count_inversions(sequence)
    
    def count_inversions(self, arr):
        inversions = 0
        for i in range(len(arr)):
            for j in range(i + 1, len(arr)):
                if arr[i] > arr[j]:
                    inversions += 1
        return inversions
    
if __name__ == "__main__":
    n = int(input())
    wires = []
    for _ in range(n):
        t, b = map(int, input().split())
        wires.append((t, b))
    solver = CowLaundrySolver(n, wires)
    print(solver.solve())