import sys

def solve():
    input = sys.stdin.readline
    N = int(input().strip())

    F = [0] * (N + 3)
    if N >= 1:
        F[1] = 1
    if N >= 2:
        F[2] = 1
    for i in range(3, N + 1):
        F[i] = F[i - 1] + F[i - 2]

    S = sum(F[1:N+1])

    used = [True] * (N + 1)
    if S % 2 == 1:
        if N >= 2:
            used[2] = False

    used_sum = sum(F[i] for i in range(1, N + 1) if used[i])
    T = used_sum // 2

    A = []
    last_taken = -10
    k = N
    while T > 0 and k >= 1:
        if used[k]:
            if F[k] <= T and (abs(k - last_taken) != 1):
                A.append(k)
                T -= F[k]
                last_taken = k

        k -= 1

    assert T == 0, "Need to recheck the logic"

    A_set = set(A)
    B = [i for i in range(1, N + 1) if used[i] and i not in A_set]

    A.sort()
    B.sort()

    print(len(A))
    print(*A)
    print(len(B))
    print(*B)

if __name__ == "__main__":
    solve()