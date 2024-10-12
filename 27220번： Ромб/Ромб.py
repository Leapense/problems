def draw_rhombus(n, a, b):
    k = (n - 1) // 2
    for i in range(n):
        row = ""
        for j in range(n):
            # Расстояние от текущей клетки до центра
            distance = abs(i - k) + abs(j - k)
            if a <= distance <= b:
                row += "*"
            else:
                row += "."
        print(row)

# Чтение входных данных
n = int(input())
a = int(input())
b = int(input())

# Рисуем ромб
draw_rhombus(n, a, b)