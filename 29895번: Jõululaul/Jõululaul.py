def calculate_gifts(N):
    results = []
    for k in range(1, N + 1):
        total_gifts = k * (N - k + 1)
        results.append(total_gifts)
    return results

# Read input
N = int(input().strip())

# Calculate and print the results
gifts = calculate_gifts(N)
for gift in gifts:
    print(gift)