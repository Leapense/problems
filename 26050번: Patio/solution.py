import sys

def count_patios(n: int, s: str) -> int:
    pref = [0] * (n + 1)
    for i in range(1, n + 1):
        pref[i] = pref[i - 1] + (1 if s[i - 1] == 'X' else 0)
    ans = 0
    max_side = int(n ** 0.5)
    for side in range(3, max_side + 1):
        length = side * side
        inner = (side - 2) * (side - 2)
        border = 4 * side - 4
        target_a = inner
        target_b = border
        for r in range(length, n + 1):
            cnt_x = pref[r] - pref[r - length]
            if cnt_x == target_a or cnt_x == target_b:
                ans += 1

    return ans

def main() -> None:
    data = sys.stdin.read().strip().split()
    n = int(data[0])
    s = data[1]
    print(count_patios(n, s))

if __name__ == "__main__":
    main()