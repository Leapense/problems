def solve():
    import sys
    input = sys.stdin.readline
    N, m = map(int, input().split())
    cost = [N, N // 2, (N + 1) // 2, (N - 1) // 3 + 1]
    patterns = []
    for s in range(16):
        c = 0
        for i in range(4):
            if s & (1 << i):
                c += cost[i]
        if c <= m:
            patterns.append(s)
    states = set()

    for s in patterns:
        arr = [False] * N
        if s & 1:
            for i in range(N):
                arr[i] = not arr[i]
        if s & 2:
            for i in range(1,N,2):
                arr[i] = not arr[i]
        if s & 4:
            for i in range(0,N,2):
                arr[i] = not arr[i]
        if s & 8:
            i = 0
            while 3 * i + 1 <= N:
                arr[3 * i] = not arr[3 * i]
                i += 1
        states.add(tuple(arr))
    print(len(states))


if __name__ == '__main__':
    solve()