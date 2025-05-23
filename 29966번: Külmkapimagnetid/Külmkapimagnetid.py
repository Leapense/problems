def min_expression_value(N, magnets):
    magnets = sorted(magnets)
    num1, num2 = "", ""

    for i in range(N):
        if i % 2 == 0:
            num1 += magnets[i]
        else:
            num2 += magnets[i]

    result = int(num1) + int(num2)

    return result

N = int(input())
magnets = input()
print(min_expression_value(N, magnets))