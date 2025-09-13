import sys

def solve():
    input_data = sys.stdin.read().strip().split()
    n = int(input_data[0])
    c = int(input_data[1])
    a = list(map(int, input_data[2:2+n]))

    S = [0] * n
    s = 0
    for i, x in enumerate(a):
        s += x
        S[i] = s
    best_w = None
    best_t = -1

    for t in range(n):
        prev_sum = S[t-1] if t > 0 else 0
        Q = prev_sum - c * t
        if Q < 0:
            Q = 0
        p = Q + a[t] + 1
        D_need = (p + c - 1) // c
        D_rem = n - t
        if D_need <= D_rem:
            w = D_need - 1
            if best_w is None or w < best_w or (w == best_w and t < best_t):
                best_w = w
                best_t = t

    if best_w is None:
        print("impossible")
    else:
        print(best_t)

if __name__ == "__main__":
    solve()