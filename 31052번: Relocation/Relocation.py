def process_requests(N, Q, locations, requests):
    results = []

    for request in requests:
        if request[0] == 1:
            _, C, X = request
            locations[C-1] = X
        elif request[0] == 2:
            _, A, B = request
            distance = abs(locations[A-1] - locations[B-1])
            results.append(distance)

    return results

import sys
input = sys.stdin.read
data = input().split()

N = int(data[0])
Q = int(data[1])

locations = list(map(int, data[2:N+2]))
requests = []

index = N + 2

for _ in range(Q):
    requests.append(list(map(int, data[index:index+3])))
    index += 3

results = process_requests(N, Q, locations, requests)

for result in results:
    print(result)