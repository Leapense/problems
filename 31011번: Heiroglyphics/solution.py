#!/usr/bin/env python3
import sys
input = sys.stdin.readline

# Known vowel and consonant patterns
VOWELS = {
    "110101",
    "101101",
    "010101",
    "111011",
}
ALL_KNOWN = VOWELS | {
    "110111","110011","110000",
    "101111","101011","101000",
    "010111","010011","010000",
    "111101","111111","111000",
}

MAX_DECIPHER = 10000

def count_matches(pattern: str, candidates: set) -> int:
    """Count how many bit-strings in candidates match the pattern (0,1,?)."""
    cnt = 0
    for cand in candidates:
        for pc, cc in zip(pattern, cand):
            if pc != '?' and pc != cc:
                break
        else:
            cnt += 1
    return cnt

def solve():
    N = int(input())
    for _ in range(N):
        S = int(input())
        # Precompute for each position i: v[i], c[i]
        vs = [0]*S
        cs = [0]*S
        for i in range(S):
            pat = input().strip()
            v_i = count_matches(pat, VOWELS)
            c_i = count_matches(pat, ALL_KNOWN - VOWELS)
            vs[i], cs[i] = v_i, c_i

        # DP arrays: ways ending in C / V
        dp_c, dp_v = 1, 0
        zero_all_cons = 1  # ways with zero vowels (all consonants)
        for i in range(S):
            v_i, c_i = vs[i], cs[i]

            # update zero-only consonants
            zero_all_cons = min(MAX_DECIPHER+1, zero_all_cons * c_i)

            # transitions
            new_dp_c = min(
                MAX_DECIPHER+1,
                (dp_c + dp_v) * c_i
            )
            new_dp_v = min(
                MAX_DECIPHER+1,
                dp_c * v_i
            )
            dp_c, dp_v = new_dp_c, new_dp_v

        total = dp_c + dp_v
        valid = total - zero_all_cons
        if valid > MAX_DECIPHER:
            print("CANNOT DECIPHER")
        else:
            print(valid)

if __name__ == "__main__":
    solve()
