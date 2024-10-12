def min_steps_greedy(N, K, heights):
    # Calculate total stairs in the building
    total_stairs = sum(heights)

    # Find the maximum sum of K consecutive floors where the lift can be used
    max_lift_covered = sum(heights[:K])  # Initial window
    current_lift_covered = max_lift_covered

    for i in range(1, N - K + 1):
        # Slide the window one floor up
        current_lift_covered = current_lift_covered - heights[i - 1] + heights[i + K - 1]
        max_lift_covered = max(max_lift_covered, current_lift_covered)

    # The minimum stairs Rusnė has to walk is the total stairs minus the stairs covered by the lift
    min_walk_stairs = total_stairs - max_lift_covered
    return min_walk_stairs

N, K = map(int, input().split())
heights = []
for _ in range(N):
    heights.append(int(input()))

print(min_steps_greedy(N, K, heights))