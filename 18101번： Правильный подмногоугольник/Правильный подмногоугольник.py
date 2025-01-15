import math

def find_minimum_M(N):
    if N < 3:
        return N
    max_check = int(math.isqrt(N)) + 1
    for i in range(3, max_check, 2):
        if N % i == 0:
            return i
    return N

N = int(input())
print(find_minimum_M(N))