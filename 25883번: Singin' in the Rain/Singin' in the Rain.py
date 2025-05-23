n = int(input())
for _ in range(n):
    t, s = map(int, input().split())
    seq = list(map(int, input().split()))
    total = 0
    for i in range(1, s):
        a = seq[i - 1]
        b = seq[i]
        default_next = (a % t) + 1
        forward = (b - default_next) % t
        backward = (default_next - b) % t
        total += min(forward, backward)

    print(total)