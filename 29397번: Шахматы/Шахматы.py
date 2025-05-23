from collections import deque

def pos_to_coords(pos):
    col = ord(pos[0]) - ord('a') + 1
    row = int(pos[1])
    return (col, row)

def is_valid(x, y):
    return 1 <= x <= 8 and 1 <= y <= 8

def can_capture(start, target):
    if start == target:
        return True
    
    moves = [
        (2, 0), (-2, 0),
        (0, 2), (0, -2),
        (1, 1), (1, -1),
        (-1, 1), (-1, -1)
    ]

    visited = [[False] * 9 for _ in range(9)]
    queue = deque()
    queue.append(start)

    visited[start[0]][start[1]] = True

    while queue:
        x, y = queue.popleft()
        for dx, dy in moves:
            nx, ny = x + dx, y + dy
            if is_valid(nx, ny) and not visited[nx][ny]:
                if (nx, ny) == target:
                    return True
                visited[nx][ny] = True
                queue.append((nx, ny))
    return False

def main():
    start_pos = input().strip()
    target_pos = input().strip()
    start = pos_to_coords(start_pos)
    target = pos_to_coords(target_pos)

    if can_capture(start, target):
        print("YES")
    else:
        print("NO")

if __name__ == '__main__':
    main()