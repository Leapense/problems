T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    P = list(map(int, input().split()))
    parties = []

    for i in range(N):
        parties.append([P[i], chr(ord('A') + i)])
    plan = []

    while sum(p[0] for p in parties) > 0:
        parties.sort(reverse=True)
        step = ''
        parties[0][0] -= 1
        step += parties[0][1]
        total = sum(p[0] for p in parties)
        majority = False
        for p in parties:
            if p[0] > total / 2:
                majority = True
                break
        if majority:
            parties[1][0] -= 1
            step += parties[1][1]
        plan.append(step)
    print(f"Case #{tc}: {' '.join(plan)}")