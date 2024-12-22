def solve():
    import sys
    vals = []
    for line in sys.stdin:
        n = line.strip()
        if not n:
            continue
        num = int(n)
        if num == -1:
            break
        vals.append(num)

    s = set(vals)
    vals_len = len(vals)
    pow2 = [1 << i for i in range(18)]
    results = []

    for v in vals:
        count = 0
        for i in range(18):
            neighbor = v ^ pow2[i]
            if neighbor > v and neighbor in s:
                count += 1
        for i in range(17):
            for j in range(i + 1, 18):
                neighbor = v ^ pow2[i] ^ pow2[j]
                if neighbor > v and neighbor in s:
                    count += 1
        results.append(count)
    for v, c in zip(vals, results):
        print(f"{v}:{c}")

solve()