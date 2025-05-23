x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())

xA = x3 + x1 - x2
yA = y3 + y1 - y2

xB = x1 + x2 - x3
yB = y1 + y2 - y3

xC = x2 + x3 - x1
yC = y2 + y3 - y1


print(xA, yA)
print(xB, yB)
print(xC, yC)