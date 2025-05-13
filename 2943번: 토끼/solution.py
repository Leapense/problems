import sys
import math

def main() -> None:
    input = sys.stdin.readline
    N, M = map(int, input().split())
    K = int(math.isqrt(N))
    if K == 0:
        K = 1
    B = (N + K - 1) // K

    box = [0] * (N + 1)
    cup = [0] * B

    out_lines = []

    for _ in range(M):
        S, A = map(int, input().split())
        L = A
        R = A + S - 1

        lb = (L - 1) // K
        rb = (R - 1) // K

        ans = 0

        def b_start(b : int) -> int:
            return b * K + 1
        def b_end(b : int) -> int:
            return min(N, (b + 1) * K)
        
        if lb == rb:
            if L == b_start(lb) and R == b_end(lb):
                cup[lb] += 1
                ans += cup[lb]
            else:
                for r in range(L, R + 1):
                    box[r] += 1
                    ans += box[r]
        else:
            if L == b_start(lb):
                cup[lb] += 1
                ans += cup[lb]
            else:
                for r in range(L, b_end(lb) + 1):
                    box[r] += 1
                    ans += box[r]
            for b in range(lb + 1, rb):
                cup[b] += 1
                ans += cup[b]

            if R == b_end(rb):
                cup[rb] += 1
                ans += cup[rb]
            else:
                for r in range(b_start(rb), R + 1):
                    box[r] += 1
                    ans += box[r]

        out_lines.append(str(ans))

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()