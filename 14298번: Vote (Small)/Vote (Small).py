T = int(input())
for tc in range(1, T + 1):
    N, M = map(int, input().split())
    if M == 0:
        prob = 1.0
    else:
        prob = (N - M) / (N + M)
    print(f"Case #{tc}: {prob:.8f}")