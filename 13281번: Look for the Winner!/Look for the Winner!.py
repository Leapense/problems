import sys
for line in sys.stdin:
    n = int(line.strip())
    if n ==0:
        break
    votes = []
    while len(votes) < n:
        votes += sys.stdin.readline().strip().split()
    unique = set(votes)
    if len(unique)==1:
        for c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
            if c not in unique:
                unique.add(c)
                break
    counts = {c:0 for c in unique}
    winner = None
    winner_k = 0
    for k in range(1, n+1):
        vote = votes[k-1]
        counts[vote] +=1
        lead = max(counts.values())
        leaders = [c for c, v in counts.items() if v == lead]
        remaining = n -k
        if len(leaders)==1:
            c = leaders[0]
            can_lose = False
            for other in counts:
                if other !=c and counts[other] + remaining >= counts[c]:
                    can_lose = True
                    break
            if not can_lose and not winner:
                winner = c
                winner_k = k
    if winner:
        print(f"{winner} {winner_k}")
    else:
        final_max = max(counts.values())
        final_leaders = [c for c, v in counts.items() if v == final_max]
        if len(final_leaders) >1:
            print("TIE")
        else:
            print(f"{final_leaders[0]} {n}")