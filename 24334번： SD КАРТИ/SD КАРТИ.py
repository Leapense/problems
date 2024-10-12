def calculate_minimal_cost(n, durations):
    # Convert each duration to total minutes
    total_minutes = sum(hours * 60 + minutes for hours, minutes in durations)

    # Costs in stotinki
    cost_240 = 1090
    cost_180 = 915

    # Card capacities
    capacity_240 = 240
    capacity_180 = 180

    # Let's define a large number for initial high cost (in stotinki)
    min_cost = float('inf')

    # Check all possible combinations of 240 and 180 cards
    # Maximum number of 240 cards needed if we used only 240-min cards
    max_240_cards = (total_minutes + capacity_240 - 1) // capacity_240
    
    for num_240 in range(max_240_cards + 1):
        remaining_minutes = total_minutes - num_240 * capacity_240
        if remaining_minutes > 0:
            num_180 = (remaining_minutes + capacity_180 - 1) // capacity_180
            cost = num_240 * cost_240 + num_180 * cost_180
        else:
            cost = num_240 * cost_240
        
        min_cost = min(min_cost, cost)

    # Also consider only using 180-min cards
    max_180_cards = (total_minutes + capacity_180 - 1) // capacity_180
    cost = max_180_cards * cost_180
    min_cost = min(min_cost, cost)
    
    # Convert minimal cost in stotinki to leva and stotinki output
    leva = min_cost // 100
    stotinki = min_cost % 100

    return f"{leva}.{stotinki:02d}"

n = int(input())
durations = [map(int, input().split()) for _ in range(n)]

print(calculate_minimal_cost(n, durations))