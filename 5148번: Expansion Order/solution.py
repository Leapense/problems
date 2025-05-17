# solution.py
from collections import deque


def solve():
    K = int(input())
    for data_set in range(1, K + 1):
        n, m = map(int, input().split())
        routes = [set(map(int, input().split())) for _ in range(m)]

        connected = set([1])
        order = []
        remaining_routes = set(range(m))

        while remaining_routes:
            progress = False

            for i in sorted(remaining_routes):
                if routes[i] & connected:
                    connected |= routes[i]
                    order.append(i + 1)  # routes are 1-indexed
                    remaining_routes.remove(i)
                    progress = True
                    break

            if not progress:
                break

        print(f"Data Set {data_set}:")
        if remaining_routes:
            print("Impossible")
        else:
            for route_id in order:
                print(route_id)


if __name__ == "__main__":
    solve()