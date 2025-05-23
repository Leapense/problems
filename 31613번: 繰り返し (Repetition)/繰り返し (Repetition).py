X = int(input())
N = int(input())

count = 0
x = X

while x < N:
    remainder = x % 3
    if remainder == 0:
        x = x + 1
    elif remainder == 1:
        x = x * 2
    else:
        x = x * 3

    count = count + 1

print(count)