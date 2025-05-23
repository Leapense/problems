def solve():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    inventors = []
    
    # Read all inventor data
    for i in range(0, 12, 2):
        N = int(data[i])
        M = int(data[i+1])
        inventors.append((N, M))
    
    weeks = 10
    # Calculate the total number of inventions after 10 weeks
    totals = [(N + M * weeks) for N, M in inventors]
    
    adalbert_total = totals[0]  # Adalbert's total inventions after 10 weeks
    max_competitor = max(totals[1:])  # Maximum inventions by any competitor
    
    # Calculate the minimum gadgets needed for Adalbert to be in the lead
    if adalbert_total > max_competitor:
        print(0)  # Adalbert is already winning
    else:
        # Otherwise, calculate how many more he needs to have at least one more than the best competitor
        K = max_competitor + 1 - adalbert_total
        print(K)


solve()