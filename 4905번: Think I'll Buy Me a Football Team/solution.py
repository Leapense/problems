import sys

def solve(nums : list[int]) -> list[str]:
    out, idx, tc = [], 0, 1
    while True:
        n = nums[idx]
        idx += 1
        if n == 0:
            break

        balance = [0] * n
        before = 0

        for i in range(n):
            for j in range(n):
                val = nums[idx]
                idx += 1
                before += val
                balance[i] -= val
                balance[j] += val

        after = sum(b for b in balance if b > 0)
        out.append(f"{tc}. {before} {after}")
        tc += 1

    return out

def main() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    print("\n".join(solve(data)))

if __name__ == "__main__":
    main()