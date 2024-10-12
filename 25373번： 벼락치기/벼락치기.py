def solve(N):
    if N <= 28:
        for i in range(1, 8):
            if N <= sum(range(1, i + 1)):
                return i
    else:
        return (N - 29) // 7 + 8

N = int(input())
print(solve(N))