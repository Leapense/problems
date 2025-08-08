import sys

def solve() -> None:
    a_str = sys.stdin.read().strip().split()
    a, d, k = map(int, a_str)
    p = d / 100.0
    g = 1.0 + k / 100.0
    survival = 1.0
    expected_games = 0.0
    while True:
        expected_games += survival
        if p >= 1.0 - 1e-15:
            break
        survival *= 1.0 - p
        p *= g
        if p > 1.0:
            p = 1.0
    result = a * expected_games
    print(f"{result:.7f}")

if __name__ == "__main__":
    solve()