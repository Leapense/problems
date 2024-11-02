def find_floor(room_number, n, k, x, y):
    def room_count_up_to_floor(floor):
        full_k_blocks = floor // k
        non_k_blocks = floor - full_k_blocks
        return full_k_blocks * x + non_k_blocks * y
    
    # Binary search to find the floor
    low, high = 1, n
    while low < high:
        mid = (low + high) // 2
        if room_count_up_to_floor(mid) < room_number:
            low = mid + 1
        else:
            high = mid
    return low

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    k = int(data[1])
    x = int(data[2])
    y = int(data[3])
    q = int(data[4])
    room_numbers = list(map(int, data[5:5+q]))
    
    results = []
    for room_number in room_numbers:
        results.append(find_floor(room_number, n, k, x, y))
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
