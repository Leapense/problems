import math

n, m = map(int, input().split())

result = math.ceil(n / 2) * math.ceil(m / 2)

print(result)