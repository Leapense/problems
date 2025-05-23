def main():
    import sys

    input = sys.stdin.read
    data = input().split()

    N = int(data[0])
    S = data[1]
    D = int(data[2])
    M = int(data[3])

    wanted = set(['H', 'Y', 'U'])
    total_cost = 0
    i = 0
    count_H = count_Y = count_U = 0

    while i < N:
        if S[i] in wanted:
            if S[i] == 'H':
                count_H += 1
            elif S[i] == 'Y':
                count_Y += 1
            elif S[i] == 'U':
                count_U += 1
            i += 1
        else:
            start = i
            while i < N and S[i] not in wanted:
                i += 1
            end = i
            L = end - start
            cost_individual = D * L
            cost_substring = M + D
            min_cost = min(cost_individual, cost_substring)
            total_cost += min_cost

    if total_cost == 0:
        print("Nalmeok")
    else:
        print(total_cost)

    hyu_count = min(count_H, count_Y, count_U)
    if hyu_count == 0:
        print("I love HanYang University")
    else:
        print(hyu_count)

if __name__ == '__main__':
    main()