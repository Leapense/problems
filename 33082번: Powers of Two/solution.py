import sys
from heapq import heappush, heappop

def main() -> None:
    input = sys.stdin.readline

    Q = int(input().strip())
    MAXX = 200_000
    SHIFT = 21
    LIMIT = MAXX + SHIFT

    cnt = [0] * (LIMIT + 5)
    nonzero = 0
    heap = []
    out_lines = []
    
    for _ in range(Q):
        t, sx = input().split()
        x = int(sx)
        delta = 1 if t == '+' else -1

        old = cnt[x]
        new = old + delta
        cnt[x] = new

        if old == 0 and new != 0:
            nonzero += 1
        elif old != 0 and new == 0:
            nonzero -= 1

        if abs(cnt[x]) >= 2:
            heappush(heap, x)
        
        while heap:
            i = heappop(heap)
            if abs(cnt[i]) < 2:
                continue
            if cnt[i] > 0:
                k = cnt[i] // 2
                old_i = cnt[i]
                cnt[i] = old_i - 2 * k
                if old_i == 0 and cnt[i] != 0:
                    nonzero += 1
                elif old_i != 0 and cnt[i] == 0:
                    nonzero -= 1

                j = i + 1
                old_j = cnt[j]
                cnt[j] = old_j + k
                if old_j == 0 and cnt[j] != 0:
                    nonzero += 1
                elif old_j != 0 and cnt[j] == 0:
                    nonzero -= 1
                if abs(cnt[i]) >= 2:
                    heappush(heap, i)
                if abs(cnt[j]) >= 2:
                    heappush(heap, j)

            else:
                k = (-cnt[i]) // 2

                old_i = cnt[i]
                cnt[i] = old_i + 2 * k
                if old_i == 0 and cnt[i] != 0:
                    nonzero += 1
                elif old_i != 0 and cnt[i] == 0:
                    nonzero -= 1
                j = i + 1
                old_j = cnt[j]
                cnt[j] = old_j - k
                if old_j == 0 and cnt[j] != 0:
                    nonzero += 1
                elif old_j != 0 and cnt[j] == 0:
                    nonzero -= 1
                
                if abs(cnt[i]) >= 2:
                    heappush(heap, i)
                if abs(cnt[j]) >= 2:
                    heappush(heap, j)
        out_lines.append("YES" if nonzero == 0 else "NO")
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()