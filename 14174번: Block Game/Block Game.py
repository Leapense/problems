from collections import Counter

def calculate_min_blocks(N, boards):
    # Initialize the count of maximum blocks needed for each letter
    max_blocks = [0] * 26  # One entry for each letter from 'a' to 'z'
    
    for i in range(N):
        # Count letter frequencies for both sides of the board
        side1_count = Counter(boards[i][0])
        side2_count = Counter(boards[i][1])
        
        # Calculate maximum counts of each letter from either side
        for letter in range(26):
            char = chr(ord('a') + letter)
            max_blocks[letter] += max(side1_count.get(char, 0), side2_count.get(char, 0))
    
    return max_blocks

def main():
    N = int(input())  # Number of boards
    boards = [input().split() for _ in range(N)]  # Read each pair of words
    
    # Calculate the required blocks for each letter
    result = calculate_min_blocks(N, boards)
    
    # Print the number of blocks required for each letter 'a' to 'z'
    for count in result:
        print(count)

# Example usage
if __name__ == "__main__":
    main()