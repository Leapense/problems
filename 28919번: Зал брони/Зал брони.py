n = int(input())
a = list(map(int, input().split()))
x = list(map(int, input().split()))
total = sum(a)

threshold = (total + 1) // 2
s = 0

for ai, xi in zip(a, x):
    s += ai
    if s >= threshold:
        print(xi)
        break