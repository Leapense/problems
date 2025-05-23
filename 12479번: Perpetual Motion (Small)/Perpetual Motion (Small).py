def main():
    import sys
    input_data = sys.stdin.read().split()
    t = int(input_data[0])
    index = 1
    MOD = 1000003
    results = []

    for case in range(1, t+1):
        R = int(input_data[index]); C = int(input_data[index+1])
        index += 2
        grid = []
        for _ in range(R):
            grid.append(input_data[index])
            index += 1

        n = R * C
        dest = [None] * n
        for r in range(R):
            for c in range(C):
                ch = grid[r][c]
                idx = r * C + c
                if ch == '|':
                    d0 = ((r-1)%R, c)
                    d1 = ((r+1)%R, c)
                elif ch == '-':
                    d0 = (r, (c-1)%C)
                    d1 = (r, (c+1)%C)
                elif ch == '/':
                    d0 = ((r-1)%R, (c+1)%C)
                    d1 = ((r+1)%R, (c-1)%C)
                elif ch == '\\':
                    d0 = ((r-1)%R, (c-1)%C)
                    d1 = ((r+1)%R, (c+1)%C)
                dest[idx] = (d0[0] * C + d0[1], d1[0] * C + d1[1])
        count = 0
        total = 1 << n
        for mask in range(total):
            used = [False] * n
            valid = True
            for i in range(n):
                choice = (mask >> i) & 1
                target = dest[i][choice]
                if used[target]:
                    valid = False
                    break
                used[target] = True
            if valid:
                count = (count + 1) % MOD
        results.append(f"Case #{case}: {count}")
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    main()