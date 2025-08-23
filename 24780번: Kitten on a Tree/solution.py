import sys

def solve():
    try:
        kitten_start_branch = int(sys.stdin.readline())
    except (IOError, ValueError):
        return
    
    parent_map = {}

    while True:
        line = sys.stdin.readline()
        if not line or line.strip() == '-1':
            break
        parts = list(map(int, line.split()))
        parent = parts[0]
        children = parts[1:]

        for child in children:
            parent_map[child] = parent

    path = []
    current_branch = kitten_start_branch
    path.append(current_branch)

    while current_branch in parent_map:
        current_branch = parent_map[current_branch]
        path.append(current_branch)

    print(*path)

solve()