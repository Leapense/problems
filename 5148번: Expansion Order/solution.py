def process_data_set(n, m, routes):
    connected = set([1])
    remaining = [(i, set(route)) for i, route in enumerate(routes)]
    order = []
    for _ in range(m):
        found = False
        for idx, (route_idx, stations) in enumerate(remaining):
            if stations & connected:
                found = True
                break
        if not found:
            return None
        order.append(route_idx + 1)
        connected |= stations
        del remaining[idx]
    return order

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    K = int(data[0])
    res = []
    line = 1

    for data_set_number in range(1, K + 1):
        n, m = map(int, data[line].split())
        routes = []
        for i in range(m):
            route = list(map(int, data[line + 1 + i].split()))
            routes.append(route)
        order = process_data_set(n, m, routes)
        res.append(f"Data Set {data_set_number}:")
        if order is None:
            res.append("Impossible")
        else:
            for idx in order:
                res.append(str(idx))
        line += 1 + m
    print('\n'.join(res))

if __name__ == "__main__":
    main()