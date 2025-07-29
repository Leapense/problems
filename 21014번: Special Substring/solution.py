import sys

def main():
    input = sys.stdin.readline
    n, k = map(int, input().split())
    s = input().strip()
    counts = [0] * 26
    for i in range(k):
        counts[ord(s[i]) - 65] += 1
    best = max(counts)
    for i in range(k, n):
        counts[ord(s[i - k]) - 65] -= 1
        counts[ord(s[i]) - 65] += 1
        if counts[ord(s[i]) - 65] > best:
            best = counts[ord(s[i]) - 65]

    print(k - best)

if __name__ == "__main__":
    main()