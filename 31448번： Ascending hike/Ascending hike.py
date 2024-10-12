def max_upward_slope(altitudes):
    max_gain = 0
    current_gain = 0
    for i in range(1, len(altitudes)):
        if altitudes[i] > altitudes[i - 1]:
            current_gain += altitudes[i] - altitudes[i - 1]
            max_gain = max(max_gain, current_gain)
        else:
            current_gain = 0
    return max_gain

# Read the number of altitudes
N = int(input())

# Read the altitudes
altitudes = list(map(int, input().split()))

# Find and print the maximum elevation gain
print(max_upward_slope(altitudes))