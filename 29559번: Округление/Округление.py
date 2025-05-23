m = int(input())
k = input().strip()

if '.' in k:
    integer_part, fractional_part = k.split('.')
    d = len(fractional_part)
else:
    d = 0

m_d = m - d

result = '1' + '0' * m_d

print(result)