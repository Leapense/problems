#!/usr/bin/env python3
import sys
from collections import defaultdict

def get_canonical(word):
    mapping = {}
    pattern = []
    next_num = 0
    for ch in word:
        if ch not in mapping:
            mapping[ch] = next_num
            next_num += 1
        pattern.append(mapping[ch])
    return tuple(pattern)

def main():
    input = sys.stdin.readline
    N = int(input().strip())
    pattern_count = defaultdict(int)

    for _ in range(N):
        word = input().strip()
        canonical_pattern = get_canonical(word)
        pattern_count[canonical_pattern] += 1

    similar_pairs = 0

    for count in pattern_count.values():
        similar_pairs += count * (count - 1) // 2

    print(similar_pairs)

if __name__ == '__main__':
    main()