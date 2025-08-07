def P4(x,y):
    a, b = -2 * y, 2 * x
    digits = []

    while a or b:
        r = a % 4
        digits.append(r)
        a, b = b // 2, -(a - r) // 2

    if not digits:
        digits.append(0)

    right = str(digits[0])
    left_digits = digits[::-1][:-1]
    if not left_digits:
        left_digits = [0]

    while len(left_digits) > 1 and left_digits[0] == 0:
        left_digits.pop(0)

    return "".join(map(str, left_digits)) + "." + right

############### SUBMIT THE CODE ABOVE ONLY ###############

print(P4(1,6)) # '31.0'
