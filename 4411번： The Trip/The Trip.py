def calculate_min_exchange(trips):
    results = []
    for trip in trips:
        n, expenses = trip
        total_expense = sum(expenses)
        average_expense = total_expense / n
        
        give = 0
        take = 0
        for expense in expenses:
            difference = round(expense - average_expense, 2)
            if difference > 0:
                give += difference
            else:
                take -= difference
        
        results.append(round(min(give, take), 2))
    return results

def main():
    trips = []
    while True:
        n = int(input().strip())
        if n == 0:
            break
        expenses = [float(input().strip()) for _ in range(n)]
        trips.append((n, expenses))
    
    results = calculate_min_exchange(trips)
    for result in results:
        print(f"${result:.2f}")

main()