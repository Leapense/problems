import sys
import bisect

def main():
    input = sys.stdin.readline

    N, Q = map(int, input().split())
    B = [int(input()) for _ in range(N)]

    prefix = [0]
    for b in B:
        prefix.append(prefix[-1] + b)

    for _ in range(Q):
        T = int(input())
        note_idx = bisect.bisect_right(prefix, T)
        print(note_idx)

if __name__ == "__main__":
    main()