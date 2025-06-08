from typing import Tuple

def floor_log2(x: int) -> int:
    return x.bit_length() - 1

def solve_case(n: int, p: int) -> Tuple[int, int]:
    total = 1 << n
    guaranteed_max = -1
    for k in range(total):
        l = floor_log2(k + 1)
        worst_rank = total - (1 << (n - l))
        if worst_rank < p:
            guaranteed_max = k
        else:
            break

    possible_max = -1
    for k in range(total):
        bigger = total - k - 1
        w = floor_log2(bigger + 1)
        best_rank = (1 << (n - w)) - 1
        if best_rank < p:
            possible_max = k

    return guaranteed_max, possible_max

def main() -> None:
    import sys
    t = int(sys.stdin.readline().strip())
    for case_id in range(1, t + 1):
        n_str, p_str = sys.stdin.readline().split()
        n, p = int(n_str), int(p_str)
        y, z = solve_case(n, p)
        print(f"Case #{case_id}: {y} {z}")

if __name__ == "__main__":
    main()