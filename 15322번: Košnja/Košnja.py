def minimal_mowing_turns(K, dimensions):
    results = []
    for N, M in dimensions:
        if N == 1 or M == 1:
            results.append(0)
        else:
            results.append(2 * (min(N, M) - 1))
    return results

K = int(input().strip())
dimensions = [tuple(map(int, input().strip().split())) for _ in range(K)]

for result in minimal_mowing_turns(K, dimensions):
    print(result)