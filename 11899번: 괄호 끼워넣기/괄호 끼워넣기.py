def min_additions(s):
    front_add = 0
    stack = []
    for char in s:
        if char == '(':
            stack.append(char)
        elif char == ')':
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                front_add += 1
    end_add = len(stack)
    return front_add + end_add

# Read input
S = input().strip()
print(min_additions(S))