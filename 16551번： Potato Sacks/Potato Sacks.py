def can_fill_potato_sack():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    P = int(data[0])

    for i in range(1, P + 1):
        line = list(map(int, data[i].split()))
        K = line[0]
        C = line[1]
        weights = line[2:]

        possible = False
        for mask in range(1 << 10):
            total_weight = 0
            for j in range(10):
                if mask & (1 << j):
                    total_weight += weights[j]
            if total_weight == C:
                possible = True
                break
        if possible:
            print(f"{K} YES")
        else:
            print(f"{K} NO")

can_fill_potato_sack()