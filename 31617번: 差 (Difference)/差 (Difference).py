K = int(input())
N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))

count = 0

for a in A:
    if (a + K) in B:
        count += B.count(a + K)

print(count)