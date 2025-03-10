def is_possible(messages, D):
    l, r = messages[0][0] - D, messages[0][0] + D
    prev_time = messages[0][1]
    for pos, t in messages[1:]:
        dt = t - prev_time
        l -= dt
        r += dt
        nl = pos - D
        nr = pos + D
        l = max(l, nl)
        r = min(r, nr)
        if l > r:
            return False
        prev_time = t
    return True

def solve_case():
    import sys
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    it = iter(input_data)
    t = int(next(it))
    results = []

    for case in range(1, t + 1):
        n = int(next(it))
        messages = []
        for _ in range(n):
            p = int(next(it))
            time = int(next(it))
            messages.append((p, time))

        messages.sort(key=lambda x: x[1])
        lo, hi = 0.0, 2000.0

        for _ in range(60):
            mid = (lo + hi) / 2.0
            if is_possible(messages, mid):
                hi = mid
            else:
                lo = mid
        ans = hi
        results.append(f"Case #{case}: {ans:.9f}")
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    solve_case()