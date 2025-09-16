import sys

def solve():
    data = sys.stdin.read().strip().split()
    n, a, b = map(int, data)
    vdir = 'U' if a * 2 <= n else 'D'
    hdir = 'L' if b * 2 <= n else 'R'

    s = []
    for _ in range(n - 1):
        s.append(vdir)
        s.append(hdir)

    if vdir == 'U':
        s.append('D' * (a - 1))
    else:
        s.append('U' * (n - a))
    
    if hdir == 'L':
        s.append('R' * (b - 1))
    else:
        s.append('L' * (n - b))

    ans = ''.join(s)
    assert len(ans) <= 3 * (n - 1)
    print(ans)

if __name__ == "__main__":
    solve()