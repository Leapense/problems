def simulate_walk(m, n, tiles):
    # Find the start position and direction
    start_index = None
    direction = None
    
    for i in range(m):
        if tiles[i] == 2:
            start_index = i
            direction = 1  # right
        elif tiles[i] == 3:
            start_index = i
            direction = -1  # left

    yellow_count = 0
    current_index = start_index
    
    for _ in range(n):
        current_index += direction
        
        # Check if we hit a wall and need to turn around
        if current_index < 0:
            current_index = 1
            direction = 1
        elif current_index >= m:
            current_index = m - 2
            direction = -1
        
        # Check if the tile is yellow
        if tiles[current_index] == 0:
            yellow_count += 1

    return yellow_count

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    T = int(data[0])
    results = []
    index = 1
    
    for _ in range(T):
        m, n = map(int, data[index].split())
        tiles = list(map(int, data[index + 1].split()))
        index += 2
        
        result = simulate_walk(m, n, tiles)
        results.append(result)
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()