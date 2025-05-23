def find_cheapest_tariff(n, m, tariffs, call_durations):
    # Conversion factor: 1 ruble = 100 kopecks
    RUB_TO_KOP = 100
    import math
    
    # Initial minimum cost setup
    min_cost = float('inf')
    min_cost_tariff_index = -1
    
    # Process each tariff
    for i in range(n):
        ci, ti, pi = tariffs[i]
        
        # Convert subscription fee to kopecks
        monthly_fee = ci * RUB_TO_KOP
        
        # Calculate the total cost for this tariff
        total_cost = monthly_fee
        
        for call_duration in call_durations:
            if call_duration >= ti:
                # Calculate the minimum number of full increments needed
                k = math.ceil(call_duration / ti)
                # Calculate the cost of this particular call
                call_cost = k * pi
            else:
                call_cost = 0
                
            total_cost += call_cost
        
        # Update the minimum cost and corresponding tariff index
        if total_cost < min_cost:
            min_cost = total_cost
            min_cost_tariff_index = i + 1  # tariffs are 1-indexed
    
    return min_cost_tariff_index

n, m = map(int, input().split())
tariffs = [list(map(int, input().split())) for _ in range(n)]
call_durations = list(map(int, input().split()))
result = find_cheapest_tariff(n, m, tariffs, call_durations)
print(result)