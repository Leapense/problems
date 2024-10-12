def find_sword_origins(n, k, ages):
    # Pair each age with its original index
    swords = [(ages[i], i + 1) for i in range(n)]
    # Sort swords by age
    swords.sort()

    # Result array to store the parent index for each sword
    parent = [-1] * n
    # Queue to keep track of potential parents
    from collections import deque
    queue = deque()
    
    for age, idx in swords:
        if not queue:
            # The first sword must be the original one (has no parent)
            parent[idx - 1] = 0
        else:
            while queue:
                parent_age, parent_idx, child_count = queue.popleft()
                if age >= parent_age + k:
                    # We found a valid parent
                    parent[idx - 1] = parent_idx
                    if child_count < 2:
                        queue.appendleft((parent_age, parent_idx, child_count + 1))
                    break
            else:
                # If we exhausted the queue and didn't find a valid parent
                return -1
        # Add current sword to queue as potential parent
        queue.append((age, idx, 0))
    
    return parent

# Input reading
import sys
input = sys.stdin.read
data = input().split()

n = int(data[0])
k = int(data[1])
ages = list(map(int, data[2:]))

result = find_sword_origins(n, k, ages)

if result == -1:
    print(-1)
else:
    print(' '.join(map(str, result)))
