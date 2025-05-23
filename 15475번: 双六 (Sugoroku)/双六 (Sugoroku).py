from collections import deque

def find_min_dice(N, A):
    goal = N + 1  # Goal is at index N+1 (0-indexed would be N+1)
    
    for dice_faces in range(1, N + 2):  # Check dice from 1 face up to N+1 faces
        reachable = [False] * (N + 2)  # Track which squares are reachable
        queue = deque([0])  # Start BFS from the start square, index 0
        reachable[0] = True
        
        while queue:
            current = queue.popleft()
            
            # Try every roll from 1 to dice_faces
            for roll in range(1, dice_faces + 1):
                next_position = current + roll
                if next_position > goal:  # If we surpass the goal, this dice is valid
                    return dice_faces
                if next_position <= N and A[next_position - 1] == 1:
                    continue  # If the next position is dangerous, skip it
                if next_position <= goal and not reachable[next_position]:
                    reachable[next_position] = True
                    queue.append(next_position)
    
    # Fallback, though we should have returned from within the loop
    return N + 1

# Reading input data
import sys
input = sys.stdin.read
data = input().split()
N = int(data[0])
A = list(map(int, data[1:]))

# Getting the result
result = find_min_dice(N, A)
print(result)
