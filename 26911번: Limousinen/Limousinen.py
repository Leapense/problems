class Solver:
    def __init__(self):
        pass

    def solve(self):
        import sys
        input_data = sys.stdin.read().strip().split()
        N = int(input_data[0])
        T = int(input_data[1])
        coords = input_data[2:]

        costs = []
        index = 0

        for _ in range(N):
            x = int(coords[index]); y = int(coords[index + 1])
            index += 2
            cost = 2 * (abs(x) + abs(y))
            costs.append(cost)

        costs.sort()

        time_sum = 0
        count = 0
        for c in costs:
            time_sum += c
            if time_sum > T:
                break
            count += 1
        print(count)

def main():
    solver = Solver()
    solver.solve()

if __name__ == '__main__':
    main()