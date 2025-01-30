t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    critics = []
    possible = True
    for _ in range(m):
        r, w = map(int, input().split())
        l = r + w
        if l > n:
            possible = False
        critics.append((r, w))
    if not possible:
        print("IMPOSSIBLE")
        continue
    found = False
    for x in range(n + 1):
        valid = True
        for (r, w) in critics:
            l = r + w
            a = max(0, x - (n - l))
            b = min(x, l)
            if not (a <= r <= b):
                valid = False
                break
        if valid:
            print('R' * x + 'W' * (n - x))
            found = True
            break
    if not found:
        print("IMPOSSIBLE")
        