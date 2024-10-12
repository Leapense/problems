def find_jinju_info(N, transport_info):
    # Initialize variables
    jinju_cost = 0
    count_more_expensive = 0
    
    # Iterate through the transport info
    for dest, cost in transport_info:
        if dest == 'jinju':
            jinju_cost = cost
            break
    
    # Count how many transports are more expensive than the cost to jinju
    for dest, cost in transport_info:
        if cost > jinju_cost:
            count_more_expensive += 1
    
    # Output the results
    print(jinju_cost)
    print(count_more_expensive)

# Example usage
N = int(input())
transport_info = [input().split() for _ in range(N)]
transport_info = [(dest, int(cost)) for dest, cost in transport_info]
find_jinju_info(N, transport_info)