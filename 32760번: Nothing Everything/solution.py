import sys

def solve():
    data = sys.stdin.read().strip().split()
    if not data:
        return

    it = iter(data)
    N = int(next(it))
    M = int(next(it))

    c = [0] * (N + 1)

    for _ in range(M):
        a = int(next(it))
        b = int(next(it))
        if a == b:
            print(-1)
            return
        if a > b:
            a, b = b, a

        c[b] += 1

    ans = []
    for j in range(2, N + 1):
        if c[j] == 0:
            ans.append('N')
        elif c[j] == j - 1:
            ans.append('E')
        else:
            print(-1)
            return
    print(''.join(ans))

if __name__ == '__main__':
    solve()