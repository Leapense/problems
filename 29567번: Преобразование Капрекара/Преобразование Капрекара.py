def kaprekar_transform(x):
    digits = list(str(x))
    M = int(''.join(sorted(digits, reverse=True)))
    m = int(''.join(sorted(digits)))

    K = M - m
    result = str(K).zfill(len(digits))
    return result

x = int(input().strip())
print(kaprekar_transform(x))