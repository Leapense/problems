def solve():
    import sys
    data = sys.stdin.read().strip().split()
    if not data: 
        return
    t = int(data[0])
    out_lines = []
    index = 1
    for case in range(1, t + 1):
        D = int(data[index]); index += 1
        K = int(data[index]); index += 1
        N = int(data[index]); index += 1
        k = N // 2
        i0 = K - 1
        if N % 2 == 0:
            pos = (i0 + 2 * k) % D if i0 % 2 == 0 else (i0 - 2 * k) % D
        else:
            pos = (i0 + (2 * k + 1)) % D if i0 % 2 == 0 else (i0 - (2 * k + 1)) % D
        pos_left = (pos + 1) % D
        pos_right = (pos - 1) % D
        if N % 2 == 0:
            orig_left = (pos_left - 2 * k) % D if pos_left % 2 == 0 else (pos_left + 2 * k) % D
            orig_right = (pos_right - 2 * k) % D if pos_right % 2 == 0 else (pos_right + 2 * k) % D
        else:
            orig_left = (pos_left - (2 * k + 1)) % D if pos_left % 2 == 1 else (pos_left + (2 * k + 1)) % D
            orig_right = (pos_right - (2 * k + 1)) % D if pos_right % 2 == 1 else (pos_right + (2 * k + 1)) % D
        left_dancer = orig_left + 1
        right_dancer = orig_right + 1
        out_lines.append(f"Case #{case}: {left_dancer} {right_dancer}")
    sys.stdout.write("\n".join(out_lines))
    
if __name__ == '__main__':
    solve()
