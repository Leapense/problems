n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
challenges = sorted([(a, b) for a, b in zip(A, B) if b - a >= 0], key=lambda x : x[0])
current = m
for a, b in challenges:
    if current >= a:
        current += b - a

print(current)