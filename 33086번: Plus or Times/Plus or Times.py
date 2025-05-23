def main():
    import sys
    input = sys.stdin.readline

    N, P = map(int, input().split())
    dp_max = P
    dp_min = P

    for _ in range(N):
        parts = input().split()
        op1, c1, op2, c2 = parts[0], int(parts[1]), parts[2], int(parts[3])
        candidates = []

        if op1 == '+':
            cand_max = dp_max + c1
            cand_min = dp_min + c1
        else:
            if c1 >= 0:
                cand_max = dp_max * c1
                cand_min = dp_min * c1
            else:
                cand_max = dp_min * c1
                cand_min = dp_max * c1
        candidates.append((cand_max, cand_min))

        if op2 == '+':
            cand_max = dp_max + c2
            cand_min = dp_min + c2
        else:
            if c2 >= 0:
                cand_max = dp_max * c2
                cand_min = dp_min * c2
            else:
                cand_max = dp_min * c2
                cand_min = dp_max * c2
        candidates.append((cand_max, cand_min))

        new_dp_max = max(cand[0] for cand in candidates)
        new_dp_min = min(cand[1] for cand in candidates)
        dp_max, dp_min = new_dp_max, new_dp_min

    print(dp_max)

if __name__ == "__main__":
    main()