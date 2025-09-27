import sys
from collections import defaultdict, deque

def solve():
    input = sys.stdin.readline

    n_line = input().strip()
    while n_line == "":
        n_line = input().strip()
    n = int(n_line)

    root = input().strip()
    while root == "":
        root = input().strip()

    children = defaultdict(list)
    names_seen = set([root])

    for _ in range(n - 1):
        line = input().strip()
        while line == "":
            line = input().strip()
        if '-' in line:
            parent, child = [s.strip() for s in line.split('-', 1)]
        else:
            parts = line.split()
            if len(parts) >= 3 and parts[1] == '-':
                parent, child = parts[0], parts[2]
            else:
                raise ValueError("Wrong input format: {}".format(line))

        children[parent].append(child)
        names_seen.add(parent)
        names_seen.add(child)
        if child not in children:
            children[child] = children[child]

    if root not in children:
        children[root] = children[root]

    q = deque()
    q.append((root, 0))
    visited = set([root])

    level_count = defaultdict(int)
    while q:
        u, d = q.popleft()
        level_count[d] += 1
        for v in children[u]:
            if v not in visited:
                visited.add(v)
                q.append((v, d + 1))

    answer = max(level_count.values()) if level_count else 0
    print(answer)

if __name__ == "__main__":
    solve()
                
