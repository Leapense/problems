import sys
from itertools import permutations

def can_realize(order, adj):
    stack = [order[0]]
    for city in order[1:]:
        while stack and city not in adj[stack[-1]]:
            stack.pop()
        if not stack:
            return False
        stack.append(city)
    return True

def solve_one_case(zips, adj):
    n = len(zips)
    best = None

    for order in permutations(range(n)):
        if can_realize(order, adj):
            concat = "".join(zips[i] for i in order)
            if best is None or concat < best:
                best = concat
    return best

def main():
    data = sys.stdin.read().strip().split()
    t = int(data[0])
    idx = 1
    for case in range(1, t+1):
        n, m = map(int, data[idx:idx+2])
        idx += 2

        zips = data[idx:idx+n]
        idx += n

        adj = [set() for _ in range(n)]
        for _ in range(m):
            u, v = map(int, data[idx:idx+2])
            idx += 2
            u -= 1
            v -= 1
            adj[u].add(v)
            adj[v].add(u)

        result = solve_one_case(zips, adj)
        print(f"Case #{case}: {result}")

if __name__ == "__main__":
    main()
