import sys

input = sys.stdin.readline

n = int(input().strip())
levels = [int(input().strip()) for _ in range(n)]
children = [0] * n
stack = []

for i, level in enumerate(levels):
    if level == 1:
        stack.clear()
        stack.append((1, i))
    else:
        if not stack or level > stack[-1][0] + 1:
            print(-1)
            sys.exit(0)
        while stack and stack[-1][0] >= level:
            stack.pop()
        if not stack or stack[-1][0] != level - 1:
            print(-1)
            sys.exit(0)
        parent_level, parent_idx = stack[-1]
        children[parent_idx] += 1
        stack.append((level, i))

for c in children:
    print(c)