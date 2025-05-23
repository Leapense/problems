def pie_chart_sectors(n, r, a):
    import math
    # Calculate the total area of the circle
    total_area = math.pi * r * r
    
    # Calculate the sum of all values
    sum_a = sum(a)
    
    # Calculate the area for each sector and output
    results = []
    for value in a:
        # Calculate sector area proportionally
        sector_area = (value / sum_a) * total_area
        results.append(sector_area)
    
    return results

# Input handling and output
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # First line
    n = int(data[0])
    r = int(data[1])
    
    # Second line contains the numbers
    a = list(map(int, data[2:2+n]))
    
    # Compute the results
    results = pie_chart_sectors(n, r, a)
    
    # Print each result
    for result in results:
        print(f"{result:.10f}")

if __name__ == "__main__":
    main()