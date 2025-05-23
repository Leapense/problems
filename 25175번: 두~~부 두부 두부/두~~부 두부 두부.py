def next_player(N, M, K):
    steps = K - 3
    next_position = (M - 1 + steps) % N + 1
    return next_position

N, M, K = map(int, input().split())
result = next_player(N, M, K)
print(result)