import sys

def solve():
    input = sys.stdin.readline
    N, T = map(int, input().split())
    A = [0] + list(map(int, input().split()))

    seq = [1]
    pos = {1: 0}

    x = 1
    while True:
        x = A[x]
        if x in pos:
            mu = pos[x]
            lam = len(seq) - mu
            break
        pos[x] = len(seq)
        seq.append(x)

    if T < len(seq):
        print(seq[T])
    else:
        if T <= mu:
            print(seq[T])
        else:
            idx = mu + (T - mu) % lam
            if idx >= len(seq):
                cycle_nodes = []
                cur = seq[-1]
                cycle_nodes = seq[mu:]
                while len(seq) <= idx:
                    seq.append(cycle_nodes[(len(seq) - mu) % lam])
            print(seq[idx])

if __name__ == "__main__":
    solve()
