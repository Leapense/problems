import sys
from typing import List, Tuple

def solve_block(n: int, m: int, orders: List[Tuple[int, int, int]]) -> int:
    orders.sort(key=lambda x: (x[0], -(x[2] * (x[1] - x[0]))))
    k = len(orders)

    suffix_potential = [0] * (k + 1)
    for i in range(k-1, -1, -1):
        s, t, p = orders[i]
        fare = p * (t - s)
        suffix_potential[i] = suffix_potential[i+1] + fare

    load = [0] * m
    best_revenue = 0

    def dfs(idx: int, current_revenue: int):
        nonlocal best_revenue

        if current_revenue + suffix_potential[idx] <= best_revenue:
            return
        
        if idx == k:
            best_revenue = max(best_revenue, current_revenue)
            return
        
        s, t, p = orders[idx]
        feasible = True
        for seg in range(s, t):
            if load[seg] + p > n:
                feasible = False
                break

        if feasible:
            for seg in range(s, t):
                load[seg] += p
            dfs(idx + 1, current_revenue + p * (t - s))

            for seg in range(s, t):
                load[seg] -= p

        dfs(idx + 1, current_revenue)

    dfs(0, 0)
    return best_revenue

def main():
    data = sys.stdin.read().strip().split()
    it = iter(data)
    out_lines = []

    while True:
        n = int(next(it))
        m = int(next(it))
        k = int(next(it))
        if n == 0 and m == 0 and k == 0:
            break

        orders = []
        for _ in range(k):
            s = int(next(it))
            t = int(next(it))
            p = int(next(it))
            orders.append((s, t, p))

        result = solve_block(n, m, orders)
        out_lines.append(str(result))

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()