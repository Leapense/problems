T = int(input())
for test_case in range(1, T + 1):
    L, N = map(int, input().split())
    runs = []
    for _ in range(N):
        D_i_str, C_i = input().split()
        D_i = int(D_i_str)
        runs.append((D_i, C_i))

    position = 0  # Starting position
    lap_count = 0
    last_direction_at_starting_line = runs[0][1]  # Initial direction

    for D_i, C_i in runs:
        if C_i == 'C':
            total_distance = position + D_i
            crossings = total_distance // L
            position = total_distance % L
        else:  # C_i == 'A'
            total_distance = (L - position) + D_i
            crossings = total_distance // L
            position = (position - D_i) % L

        if crossings == 0:
            laps_added = 0
        else:
            if C_i == last_direction_at_starting_line:
                laps_added = crossings
            else:
                laps_added = max(0, crossings - 1)
            last_direction_at_starting_line = C_i

        lap_count += laps_added

    print(f"Case #{test_case}: {lap_count}")