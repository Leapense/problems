import sys
sequence = sys.stdin.read().strip()
max_stars = {rank: 5 if 1 <= rank <=10 else 4 if 11<= rank <=15 else 3 if 16<= rank <=20 else 2 for rank in range(1,26)}
rank =25
stars=0
consec_wins=0
legend=False
for game in sequence:
    if legend:
        continue
    if game=='W':
        consec_wins+=1
        bonus=1 if rank>=6 and consec_wins>=3 else 0
        stars +=1 + bonus
        while rank >1 and stars > max_stars[rank]:
            stars -= max_stars[rank]
            rank -=1
        if rank ==1 and stars > max_stars[rank]:
            legend=True
    else:
        consec_wins=0
        if 1 <= rank <=20:
            if stars >0:
                stars -=1
            else:
                if rank <20:
                    rank +=1
                    stars = max_stars[rank]-1
if legend:
    print("Legend")
else:
    print(rank)