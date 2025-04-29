import sys
inp = sys.stdin.readline

MOD = 10**9 + 7

def solve():
    n = int(inp().strip())
    if n == 2:
        print(1)
        return
    
    result = n * pow(2, n-3, MOD) % MOD
    print(result)

if __name__ == "__main__":
    solve()