import sys
import math
sys.setrecursionlimit(10000)
input = sys.stdin.readline

def is_prime(n):
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    r = int(math.isqrt(n))
    for i in range(3, r + 1, 2):
        if n % i == 0:
            return False
    return True

t = int(input())
for _ in range(t):
    data = list(map(int, input().split()))
    n = data[0]
    arr = data[1:]
    prefix = [0] * (n + 1)
    for i in range(n):
        prefix[i+1] = prefix[i] + arr[i]
    found = False
    for length in range(2, n+1):
        for i in range(n - length + 1):
            s = prefix[i+length] - prefix[i]
            if is_prime(s):
                print("Shortest primed subsequence is length {}: {}".format(length, " ".join(map(str, arr[i:i+length]))))
                found = True
                break
        if found:
            break
    if not found:
        print("This sequence is anti-primed.")
