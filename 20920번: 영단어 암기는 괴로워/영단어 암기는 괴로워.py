import sys
from collections import defaultdict

def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    word_count = defaultdict(int)

    for _ in range(N):
        word = input().rstrip()
        if len(word) >= M:
            word_count[word] += 1
    words = list(word_count.keys())
    words.sort(key=lambda x: (-word_count[x], -len(x), x))
    print('\n'.join(words))

if __name__ == '__main__':
    main()