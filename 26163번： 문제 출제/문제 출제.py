import sys
input = sys.stdin.readline

b = list(map(int, input().split()))

max_fee = 0

for a1 in range(16):
    for a2 in range(16):