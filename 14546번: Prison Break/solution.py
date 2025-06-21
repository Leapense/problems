import sys
from collections import deque

def solve():
    try:
        l, w, entry_col, entry_row, exit_col, exit_row = map(int, sys.stdin.readline().split())
        start_pos = (entry_row - 1, entry_col - 1)
        exit_pos = (exit_row - 1, exit_col - 1)

        prison_map = [sys.stdin.readline().strip() for _ in range(w)]
        start_type = prison_map[start_pos[0]][start_pos[1]]
        exit_type = prison_map[exit_pos[0]][exit_pos[1]]

        if start_type != exit_type:
            print("NO")
            return
        
        queue = deque([start_pos])
        visited = [[False] * l for _ in range(w)]
        visited[start_pos[0]][start_pos[1]] = True
        
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]

        path_found = False
        while queue:
            current_row, current_col = queue.popleft()
            if (current_row, current_col) == exit_pos:
                path_found = True
                break

            for i in range(4):
                next_row, next_col = current_row + dr[i], current_col + dc[i]
                if 0 <= next_row < w and 0 <= next_col < l and \
                   prison_map[next_row][next_col] == start_type and \
                   not visited[next_row][next_col]:
                    visited[next_row][next_col] = True
                    queue.append((next_row, next_col))

        if path_found:
            print("YES")
        else:
            print("NO")
    except (IOError, ValueError) as e:
        print(f"An error occurred: {e}", file=sys.stderr)

def main():
    try:
        num_cases = int(sys.stdin.readline())
        for _ in range(num_cases):
            solve()
    except (IOError, ValueError) as e:
        print(f"Invalid input format: {e}", file=sys.stderr)

if __name__ == "__main__":
    main()