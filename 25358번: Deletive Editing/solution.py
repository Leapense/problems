from typing import List

ALPHABET = 26
ASCII_A = ord('A')

def can_get_final(s: str, t: str) -> bool:
    count_s = [0] * ALPHABET
    count_t = [0] * ALPHABET
    for ch in s:
        count_s[ord(ch) - ASCII_A] += 1
    for ch in t:
        count_t[ord(ch) - ASCII_A] += 1
    for i in range(ALPHABET):
        if count_t[i] > count_s[i]:
            return False
    deletions = [count_s[i] - count_t[i] for i in range(ALPHABET)]
    kept: List[str] = []
    for ch in s:
        idx = ord(ch) - ASCII_A
        if deletions[idx] > 0:
            deletions[idx] -= 1
        else:
            kept.append(ch)
    return ''.join(kept) == t

def solve() -> None:
    n = int(input().strip())
    for _ in range(n):
        s, t = input().strip().split()
        print('YES' if can_get_final(s, t) else 'NO')

if __name__ == "__main__":
    solve()