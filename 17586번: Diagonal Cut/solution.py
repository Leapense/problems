import math

def solve():
    try:
        m, n = map(int, input().split())
    except (IOError, ValueError) as e:
        print(f"Invalid input: {e}")
        return
    
    if (m & -m) != (n & -n):
        print(0)
    else:
        result = math.gcd(m, n)
        print(result)

if __name__ == '__main__':
    solve()