def can_form_parallelepiped(matchsticks):
    # Count frequency of each matchstick length
    length_counts = {}
    for length in matchsticks:
        if length in length_counts:
            length_counts[length] += 1
        else:
            length_counts[length] = 1

    # Collect the counts in a list
    counts = list(length_counts.values())

    # Check if we have exactly three lengths each occurring 4 times
    if sorted(counts) == [4, 4, 4]:
        return "yes"
    else:
        return "no"

def main():
    import sys
    input = sys.stdin.read
    
    data = input().strip().split('\n')
    results = []
    
    for line in data:
        matchsticks = list(map(int, line.split()))
        if all(x == 0 for x in matchsticks):
            break
        results.append(can_form_parallelepiped(matchsticks))
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()