def lexicographically_earliest_order(n, directions):
    stack = []
    result = []

    for i in range(n):
        if i < n - 1 and directions[i] == 'L':
            stack.append(i + 1)
        else:
            stack.append(i + 1)
            while stack:
                result.append(stack.pop())
    return result


import sys
input = sys.stdin.read
data = input().splitlines()

n = int(data[0])
directions = data[1]

result = lexicographically_earliest_order(n, directions)

for num in result:
    print(num)