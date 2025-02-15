def solve():
    import sys, bisect
    input = sys.stdin.readline
    N = int(input().strip())
    A = list(map(int, input().split()))

    bad_list = []
    for i in range(0, N, 2):
        if i + 2 < N:
            if abs(A[i + 2] - A[i]) > 2:
                bad_list.append(i)

    max_len = 1
    for L in range(N):
        idx = bisect.bisect_left(bad_list, L)
        if idx < len(bad_list):
            b = bad_list[idx]
            R_max = min(N - 1, b + 1)
        else:
            R_max = N - 1

        curr_len = R_max - L + 1
        if curr_len > max_len:
            max_len = curr_len
        if max_len == N:
            break
    print(max_len)

if __name__ == "__main__":
    solve()