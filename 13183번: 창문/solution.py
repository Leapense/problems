import sys

def solve():
    MOD = 1_000_000_007
    try:
        h_str, w_str = sys.stdin.readline().split()
        h_val = int(h_str)
        w_val = int(w_str)
    except (IOError, ValueError):
        return
    
    term1 = (h_val + 2) % MOD
    term2 = (w_val + 2) % MOD
    result = (term1 * term2) % MOD
    print(result)

if __name__ == "__main__":
    solve()