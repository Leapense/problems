#!/usr/bin/env python3
import argparse
import random
import sys

def gen_word(length: int) -> str:
    chars = [random.choice(['a', 'b', '?']) for _ in range(length)]
    if '?' not in chars:
        idx = random.randrange(length)
        chars[idx] = '?'
    return ''.join(chars)

def main():
    parser = argparse.ArgumentParser(
        description="주어진 조건에 맞는 랜덤 테스트 케이스 생성기"
    )
    parser.add_argument('--n', type=int, default=10, help="생성할 단어 개수 (기본 10)")
    parser.add_argument('--max_total_len', type=int, default=200000, help="단어 총 길이 한도 (기본 200000)")
    parser.add_argument('--min_len', type=int, default=2, help="개별 단어 최소 길이 (짝수, 기본 2)")
    parser.add_argument('--max_len', type=int, default=100, help="개별 단어 최대 길이 (짝수, 기본 100)")
    parser.add_argument('--seed', type=int, default=42, help="랜덤 시드 (기본 42)")
    args = parser.parse_args()
    random.seed(args.seed)

    boundary_min = gen_word(args.min_len)
    max_word_len = min(args.max_len, args.max_total_len - args.min_len)
    boundary_max = gen_word(max_word_len if max_word_len % 2 == 0 else max_word_len - 1)

    words = [boundary_min]
    total_len = len(boundary_min)
    for i in range(args.n - 2):
        remain = args.max_total_len - total_len - len(boundary_max)
        if remain < args.min_len:
            break
        max_l = min(args.max_len, remain)
        length = random.randrange(args.min_len // 2, max_l // 2 + 1) * 2
        w = gen_word(length)
        words.append(w)
        total_len += length
    words.append(boundary_max)
    total_len += len(boundary_max)

    sys.stdout.write(f"{len(words)}\n")
    for w in words:
        sys.stdout.write(w + "\n")

if __name__ == "__main__":
    main()