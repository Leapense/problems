import sys

def main():
    input = sys.stdin.readline
    n = int(input().strip())
    INF = -10**18
    best_pos = INF
    best_neg = INF
    ans = 0
    for _ in range(n):
        v = int(input().strip())
        npos = max(best_pos, v, best_neg + v)
        nneg = max(best_neg, best_pos - v)
        best_pos, best_neg = npos, nneg
        if best_pos > ans:
            ans = best_pos

    print(ans)

if __name__ == "__main__":
    main()
