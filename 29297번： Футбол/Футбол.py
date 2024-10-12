def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])
    results = data[1:]
    
    outputs = []
    
    for result in results:
        a, b = map(int, result.split(':'))
        
        LAG_wins = 0
        DCU_wins = 0
        
        # Possible scores for the second match
        for c in range(10):  # DCU's home goals in second match
            for d in range(10):  # LAG's away goals in second match
                total_LAG = a + d
                total_DCU = b + c
                
                if total_LAG > total_DCU:
                    LAG_wins += 1
                elif total_DCU > total_LAG:
                    DCU_wins += 1
                else:  # total_LAG == total_DCU
                    # Check away goals, a:b first match, c:d second match
                    # Away goals: LAG has 'd' away goals, DCU has 'b' away goals
                    if d > b:
                        LAG_wins += 1
                    elif b > d:
                        DCU_wins += 1
                    # If even away goals are equal, it's a draw, count none
        
        outputs.append(f"{LAG_wins} {DCU_wins}")
    
    for output in outputs:
        print(output)

solve()