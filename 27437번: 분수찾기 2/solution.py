import math

def find_fraction(X: int) -> str:
    k = int((math.isqrt(8 * X - 7) - 1) // 2) + 1

    prev = k * (k - 1) // 2
    pos = X - prev

    if k % 2 == 1:
        numerator = k - pos + 1
        denominator = pos
    else:
        numerator = pos
        denominator = k - pos + 1
    
    return f"{numerator}/{denominator}"

X = int(input().strip())
print(find_fraction(X))