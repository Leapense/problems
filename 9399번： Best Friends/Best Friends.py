import sys
from collections import deque

def build_num_to_coord(max_num):
    num_to_coord = {}
    coord_to_num = {}
    num_to_coord[1] = (0, 0, 0)
    coord_to_num[(0, 0, 0)] = 1
    queue = deque([(0, 0, 0)])
    current_num = 1
    directions = [
        (1, 0, -1),
        (1, -1, 0),
        (0, -1, 1),
        (-1, 0, 1),
        (-1, 1, 0),
        (0, 1, -1)
    ]
    
    while current_num < max_num:
        current_pos = queue.popleft()
        for d in directions:
            neighbor = (current_pos[0] + d[0], current_pos[1] + d[1], current_pos[2] + d[2])
            if neighbor not in coord_to_num:
                current_num += 1
                num_to_coord[current_num] = neighbor
                coord_to_num[neighbor] = current_num
                queue.append(neighbor)
                if current_num >= max_num:
                    break
    return num_to_coord

def hex_distance(coord1, coord2):
    x1, y1, z1 = coord1
    x2, y2, z2 = coord2
    return max(abs(x1 - x2), abs(y1 - y2), abs(z1 - z2))

def main():
    input_lines = sys.stdin.read().strip().split('\n')
    test_cases = []
    max_num = 1
    for line in input_lines:
        a, b = map(int, line.strip().split())
        if a ==0 and b ==0:
            break
        test_cases.append((a, b))
        max_num = max(max_num, a, b)
    
    num_to_coord = build_num_to_coord(max_num)
    
    for a, b in test_cases:
        coord_a = num_to_coord[a]
        coord_b = num_to_coord[b]
        distance = hex_distance(coord_a, coord_b)
        print(distance)

if __name__ == "__main__":
    main()
