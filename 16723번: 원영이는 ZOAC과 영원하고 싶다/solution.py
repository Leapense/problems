import sys

def main() -> None:
    n_str: str | None = sys.stdin.readline()
    if not n_str:
        return

    n: int = int(n_str.strip())
    partial_sum: int = 0
    k: int = 0

    while (1 << k) <= n:
        cnt: int = (n + (1 << k)) >> (k + 1)
        partial_sum += (1 << k) * cnt
        k += 1

    result: int = partial_sum << 1
    print(result)

if __name__ == '__main__':
    main()