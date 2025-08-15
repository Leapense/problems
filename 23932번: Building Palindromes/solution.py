import sys
from typing import List, Tuple

ASCII_A = ord('A')

def build_prefix_parity(s: str) -> List[int]:
    n = len(s)
    prefix = [0] * (n + 1)
    mask = 0
    for i in range(1, n + 1):
        mask ^= 1 << (ord(s[i - 1]) - ASCII_A)
        prefix[i] = mask
    return prefix

def can_form_palindrome(mask: int) -> bool:
    return mask == 0 or (mask & (mask - 1)) == 0

def solve_case(n: int, q: int, s: str, queries: List[Tuple[int, int]]) -> int:
    prefix = build_prefix_parity(s)
    yes_count = 0
    for l, r in queries:
        odd_mask = prefix[r] ^ prefix[l - 1]
        if can_form_palindrome(odd_mask):
            yes_count += 1
    return yes_count

def read_all_tokens() -> List[str]:
    data = sys.stdin.buffer.read().split()
    return [d.decode() for d in data]

def main() -> None:
    tokens = read_all_tokens()
    it = iter(tokens)
    t = int(next(it))
    outputs: List[str] = []
    for case_index in range(1, t + 1):
        n = int(next(it))
        q = int(next(it))
        s = next(it)
        queries: List[Tuple[int, int]] = []
        for _ in range(q):
            l = int(next(it))
            r = int(next(it))
            queries.append((l, r))
        y = solve_case(n, q, s, queries)
        outputs.append(f"Case #{case_index}: {y}")
    sys.stdout.write("\n".join(outputs))

if __name__ == "__main__":
    main()