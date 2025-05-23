def count_digits(x):
    return len(str(x))

def sum_digits_multiples(m):
    total = 0
    d = 1
    start = 1
    while start <= m:
        end = min(m, 10**d - 1)
        count = end - start + 1
        total += count * (d + 1)
        d += 1
        start *= 10
    return total

n = int(input().strip())
m = n // 10
result = sum_digits_multiples(m)
result += count_digits(1)
if n % 10 != 0 and n != 1:
    result += count_digits(n)
print(result)