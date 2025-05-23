def kletki(N, K):
    d = (N - 1) // (K - 1)
    extra = (N - 1) % (K - 1)

    pairs_with_d = (K - 1) - extra
    print(pairs_with_d)

N, K = map(int, input().split())
kletki(N, K)