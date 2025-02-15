def solve():
    import sys
    input = sys.stdin.readline
    t = int(input())
    out_lines = []

    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        i = arr.index(min(arr))

        if i == 0 or i == n - 1:
            out_lines.append(str(sum(arr) / n))
            continue

        cur_sum = arr[i]
        cnt = 1

        left = i - 1
        right = i + 1
        cur_sum += arr[left] + arr[right]
        cnt += 2
        cur_avg = cur_sum / cnt

        while True:
            cand_left = arr[left - 1] if left - 1 >= 0 else -1
            cand_right = arr[right + 1] if right + 1 < n else -1

            best = -1
            side = None

            if left - 1 >= 0 and cand_left >= cur_avg:
                best = cand_left
                side = 'L'
            if right + 1 < n and cand_right >= cur_avg:
                if side is None or cand_right > best:
                    best = cand_right
                    side = 'R'
            if side is None:
                break
            if side == 'L':
                left -= 1
                cur_sum += arr[left]
                cnt += 1
            else:
                right += 1
                cur_sum += arr[right]
                cnt += 1
            cur_avg = cur_sum / cnt

        out_lines.append("{:.20f}".format(cur_avg))
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()