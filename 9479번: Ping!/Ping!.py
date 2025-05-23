import sys

for line in sys.stdin:
    line = line.strip()
    if line == "0":
        break
    P = list(map(int, line))
    N = len(P)

    S = [0] * N
    for i in range(1, N):
        xor_val = 0

        for d in range(1, int(i ** 0.5) + 1):
            if i % d == 0:
                if d < i:
                    xor_val ^= S[d]
                div = i // d
                if div != d and div < i:
                    xor_val ^= S[div]

        S[i] = P[i] ^ xor_val
    result = [str(i) for i in range(1, N) if S[i] == 1]
    print(" ".join(result))