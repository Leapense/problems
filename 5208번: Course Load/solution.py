def solve():
    import sys
    input_str = sys.stdin.read
    data = input_str().split()
    idx = 0
    K = int(data[idx])
    idx += 1
    results = []

    for data_set in range(1, K + 1):
        n, m, C = map(int, data[idx:idx+3])
        idx += 3
        classes = []
        for _ in range(n):
            u = int(data[idx])
            w = int(data[idx+1])
            mi = int(data[idx+2])
            slots = set(map(lambda x: int(x) - 1, data[idx+3:idx+3+mi]))
            idx += 3 + mi
            slot_mask = 0
            for s in slots:
                slot_mask |= (1 << s)
            classes.append((u, w, slot_mask))

        max_utility = 0

        for mask in range(1 << n):
            total_u = 0
            total_w = 0
            used_slots = 0
            valid = True

            for i in range(n):
                if (mask >> i) & 1:
                    u, w, s_mask = classes[i]
                    if used_slots & s_mask:
                        valid = False
                        break
                    used_slots |= s_mask
                    total_u += u
                    total_w += w
            if valid and total_w <= C:
                max_utility = max(max_utility, total_u)

        results.append(f"Data Set {data_set}:\n{max_utility}")
    
    print("\n".join(results))

if __name__ == "__main__":
    solve()