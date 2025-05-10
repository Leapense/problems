import sys

KEEP_DIGIT = 10
MOD = 10 ** KEEP_DIGIT

def last_five_nonzero(n: int) -> int:
    prod = 1
    cnt2 = cnt5 = 0

    for i in range(2, n + 1):
        x = i
        while x % 2 == 0:
            x //= 2
            cnt2 += 1
        while x % 5 == 0:
            x //= 5
            cnt5 += 1
        prod = (prod * x) % MOD

    diff = cnt2 - cnt5
    if diff:
        prod = (prod * pow(2, diff, MOD)) % MOD

    return prod % 100_000

def main() -> None:
    n_str = sys.stdin.readline().strip()
    n = int(n_str)
    result = last_five_nonzero(n)
    print(f"{result:05d}")

if __name__ == "__main__":
    main()