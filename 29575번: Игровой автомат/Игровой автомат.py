def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    # First line contains number of payout entries
    n = int(data[0])
    
    # Create a dictionary for payout table
    payouts = {}
    
    # Read the payout information
    index = 1
    for i in range(n):
        ci, wi = data[index].split()
        wi = int(wi)
        payouts[ci] = wi
        index += 1
    
    # Read the number of attempts Afanasy made
    m = int(data[index])
    index += 1
    
    # Total cost for playing m games
    total_cost = 10 * m
    
    # Read each result and calculate total winnings
    total_winnings = 0
    for i in range(m):
        result = data[index]
        if result in payouts:
            total_winnings += payouts[result]
        index += 1
    
    # Net change in Afanasy's capital
    capital_change = total_winnings - total_cost
    
    # Print the result
    print(capital_change)

if __name__ == '__main__':
    main()