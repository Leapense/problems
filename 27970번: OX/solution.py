import sys

MOD = 10 ** 9 + 7

def solve():
    s = sys.stdin.readline().strip()
    ans = 0
    for ch in reversed(s):
        ans = (ans * 2 + (1 if ch == 'O' else 0)) % MOD
    print(ans % MOD)

if __name__ == "__main__":
    solve()