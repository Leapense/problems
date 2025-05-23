k = int(input())
file_names = [input().strip() for _ in range(k)]

numbers = [int(name) for name in file_names]

min_tests = max(max(numbers), 10 ** (len(file_names[0]) - 1))
max_tests = 10 ** len(file_names[0]) - 1

print(min_tests)
print(max_tests)