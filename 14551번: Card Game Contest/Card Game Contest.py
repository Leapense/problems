def count_distinct_ways(N, M, A):    
    ans = 1
    for a in A:
        if a == 0:
            ans = (ans * 1) % M
        else:
            ans = (ans * a) % M

    return ans % M


# Reading input
import sys
input = sys.stdin.read
data = input().split()
N = int(data[0])
M = int(data[1])
A = list(map(int, data[2:]))

# Calculating the result
result = count_distinct_ways(N, M, A)
print(result)