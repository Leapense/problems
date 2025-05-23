def decimal_to_ternary(num):
    if num == 0:
        return "0"
    ternary = []
    while num > 0:
        ternary.append(str(num % 3))
        num //= 3

    return ''.join(reversed(ternary))

def convert_numbers(n, numbers):
    results = [decimal_to_ternary(num) for num in numbers]
    return results

import sys
input = sys.stdin.read
data = input().strip().split()

n = int(data[0])
numbers = list(map(int, data[1:n+1]))

results = convert_numbers(n, numbers)
for result in results:
    print(result)