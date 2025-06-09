import sys
from itertools import permutations

def main():
    data = sys.stdin.read().strip().split()
    t = int(data[0])
    idx = 1

    for case in range(1, t + 1):
        n = int(data[idx])
        idx += 1
        coords = list(map(int, data[idx : idx + n]))
        idx += n
        fuel_limit = int(data[idx])
        idx += 1

        others = [x for x in coords if x != 0]
        best = -1

        for order in permutations(others):
            cost = 0
            cost += abs(order[0] - 0)
            for i in range(1, len(order)):
                cost += abs(order[i] - order[i - 1])

            cost += abs(order[-1] - 0)

            if cost <= fuel_limit and cost > best:
                best = cost

        if best < 0:
            result = "NO SOLUTION"
        else:
            result = str(best)

        print(f"Case #{case}: {result}")

if __name__ == "__main__":
    main()