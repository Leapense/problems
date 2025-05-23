import sys

def main():
    import sys

    sys.setrecursionlimit(1 << 25)
    n, k = map(int, sys.stdin.readline().split())
    passengers = []
    for _ in range(k):
        x, y = map(int, sys.stdin.readline().split())
        passengers.append((x, y))

    # Initialize variables
    row_taken = {}  # key: row number, value: set of taken seats
    red_candidates = []
    blue_candidates = []
    black_candidates = []
    yellow_candidates = []
    pink_candidates = list(range(1, k+1))  # All passengers can be Pink Ranger

    current_min = 1
    current_max = n

    for i, (x, y) in enumerate(passengers):
        # Update current_min
        while current_min <= n:
            if current_min not in row_taken or len(row_taken[current_min]) < 2:
                break
            current_min +=1

        # Update current_max
        while current_max >=1:
            if current_max not in row_taken or len(row_taken[current_max]) <2:
                break
            current_max -=1

        # Determine Red Ranger's choice
        red_choice = None
        if current_min <=n:
            if current_min not in row_taken or len(row_taken[current_min]) ==0:
                red_choice = (current_min, 1)  # Left seat
            elif len(row_taken[current_min]) ==1:
                if 1 not in row_taken[current_min]:
                    red_choice = (current_min,1)
                else:
                    red_choice = (current_min,2)

        # Determine Blue Ranger's choice
        blue_choice = None
        if current_min <=n:
            if current_min not in row_taken or len(row_taken[current_min]) ==0:
                blue_choice = (current_min, 2)  # Right seat
            elif len(row_taken[current_min]) ==1:
                if 2 not in row_taken[current_min]:
                    blue_choice = (current_min,2)
                else:
                    blue_choice = (current_min,1)

        # Determine Black Ranger's choice
        black_choice = None
        if current_max >=1:
            if current_max not in row_taken or len(row_taken[current_max]) ==0:
                black_choice = (current_max,1)  # Left seat
            elif len(row_taken[current_max]) ==1:
                if 1 not in row_taken[current_max]:
                    black_choice = (current_max,1)
                else:
                    black_choice = (current_max,2)

        # Determine Yellow Ranger's choice
        yellow_choice = None
        if current_max >=1:
            if current_max not in row_taken or len(row_taken[current_max]) ==0:
                yellow_choice = (current_max,2)  # Right seat
            elif len(row_taken[current_max]) ==1:
                if 2 not in row_taken[current_max]:
                    yellow_choice = (current_max,2)
                else:
                    yellow_choice = (current_max,1)

        # Compare with actual passenger's choice
        if red_choice and (x, y) == red_choice:
            red_candidates.append(i+1)
        if blue_choice and (x, y) == blue_choice:
            blue_candidates.append(i+1)
        if black_choice and (x, y) == black_choice:
            black_candidates.append(i+1)
        if yellow_choice and (x, y) == yellow_choice:
            yellow_candidates.append(i+1)
        # Pink Ranger: all passengers are candidates

        # Update seat availability
        if x not in row_taken:
            row_taken[x] = set()
        row_taken[x].add(y)
        # If row is fully taken, update current_min and current_max in next iterations

    # Print results
    print(len(red_candidates), *red_candidates)
    print(len(blue_candidates), *blue_candidates)
    print(len(black_candidates), *black_candidates)
    print(len(yellow_candidates), *yellow_candidates)
    print(len(pink_candidates), *pink_candidates)

if __name__ == "__main__":
    main()
