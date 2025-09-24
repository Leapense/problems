import sys

def solve():
    input = sys.stdin.readline
    N = int(input().strip())
    T = list(map(int, input().split()))
    B = list(map(int, input().split()))

    dpT = max(T[0], T[0] + B[0])
    dpB = T[0] + B[0]

    for j in range(1, N):
        t, b = T[j], B[j]
        best_prev = dpT if dpT > dpB else dpB

        next_dpT = max(dpT + t, best_prev + t + b)
        next_dpB = max(dpB + b, best_prev + t + b)

        dpT, dpB = next_dpT, next_dpB

    print(dpB)

if __name__ == "__main__":
    solve()