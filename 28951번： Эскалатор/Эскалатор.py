def sum_digits_count(m):
    total = 0
    d = 1
    lower = 1
    while lower <= m:
        upper = min(m, 10 ** d - 1)
        total += (upper - lower + 1) * d
        d += 1
        lower = 10 ** (d - 1) * 10
    return total

n = int(input().strip())
m = n // 10
result = sum_digits_count(m) + m + 1
if n != 1 and n % 10 != 0:
    result += len(str(n))
print(result)