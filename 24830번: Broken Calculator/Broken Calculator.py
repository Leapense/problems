def broken_calculator(n, operations):
    previous_result = 1
    results = []

    for operation in operations:
        a, op, b = operation
        if op == '+':
            current_result = a + b
            current_result -= previous_result
        elif op == '-':
            current_result = a - b
            current_result *= previous_result
        elif op == '*':
            current_result = a * b
            current_result **= 2
        elif op == '/':
            if a % 2 == 0:
                current_result = a // 2
            else:
                current_result = (a + 1) // 2
        
        results.append(current_result)
        previous_result = current_result

    return results

n = int(input())
operations = []

for _ in range(n):
    a, op, b = input().split()
    a = int(a)
    b = int(b)
    operations.append((a, op, b))

results = broken_calculator(n, operations)
for result in results:
    print(result)
