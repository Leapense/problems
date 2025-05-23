from collections import deque
import sys

def main():
    lines = sys.stdin.read().splitlines()
    n = int(lines[0])
    idx = 1

    for day in range(1, n + 1):
        first_line = lines[idx].rstrip('\n')
        idx += 1
        second_line = lines[idx].rstrip('\n')
        idx += 1
        c_d = first_line.strip().split()
        c = int(c_d[0])
        d = int(c_d[1])
        path = second_line.strip()
        visited = [False] * c
        queue = deque()
        queue.append((0, 0))
        visited[0] = True
        min_jumps = 0
        found = False
        while queue:
            current, jumps = queue.popleft()
            for jump_dist in range(1, d + 2):
                target = current + jump_dist
                if target >= c:
                    continue
                if target == c - 1:
                    min_jumps = jumps + 1
                    found = True
                    break
                if path[target] == '.' and not visited[target]:
                    visited[target] = True
                    queue.append((target, jumps + 1))
            if found:
                break
        if not found:
            min_jumps = 0
        print(f"Day #{day}")
        print(first_line)
        print(second_line)
        print(min_jumps)
        print()

if __name__ == '__main__':
    main()