import math

def count_functioning_universes(n):
    return math.isqrt(n)

if __name__ == '__main__':
    import sys
    input = sys.stdin.read
    n = int(input())
    print(count_functioning_universes(n))