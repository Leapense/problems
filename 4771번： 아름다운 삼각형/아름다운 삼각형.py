import sys
import math

def is_triangle(p1, p2, p3):
    area = abs(
        (p1[0]*(p2[1]-p3[1]) +
         p2[0]*(p3[1]-p1[1]) +
         p3[0]*(p1[1]-p2[1])) / 2.0)
    return area > 1e-8

def distance(p1, p2):
    return math.hypot(p1[0] - p2[0], p1[1] - p2[1])

def classify_sides(a, b, c):
    eps = 1e-6
    if abs(a - b) < eps and abs(b - c) < eps:
        return "Equilateral"
    elif abs(a - b) < eps or abs(b - c) < eps or abs(c - a) < eps:
        return "Isosceles"
    else:
        return "Scalene"
    
def classify_angles(a, b, c):
    angles = []

    angle_A = math.acos((b ** 2 + c ** 2 - a ** 2) / (2 * b * c)) * (180 / math.pi)
    angle_B = math.acos((a ** 2 + c ** 2 - b ** 2) / (2 * a * c)) * (180 / math.pi)
    angle_C = 180 - angle_A - angle_B
    angles.extend([angle_A, angle_B, angle_C])

    max_angle = max(angles)
    if 88 <= max_angle <= 92:
        return "Right"
    elif max_angle > 90:
        return "Obtuse"
    else:
        return "Acute"

lines = sys.stdin.read().splitlines()
i = 0
while i < len(lines):
    line = lines[i]
    if line.strip() == '-1':
        break
    else:
        data = []
        while len(data) < 6:
            tokens = line.strip().split()
            data.extend(map(float, tokens))
            i += 1
            if len(data) < 6 and i < len(lines):
                line = lines[i]
            elif len(data) < 6:
                break
        if len(data) < 6:
            break
        x1, y1, x2, y2, x3, y3 = data
        p1 = (x1, y1)
        p2 = (x2, y2)
        p3 = (x3, y3)

        if not is_triangle(p1, p2, p3):
            print("Not a Triangle")
        else:
            a = distance(p2, p3)
            b = distance(p1, p3)
            c = distance(p1, p2)

            side_class = classify_sides(a, b, c)
            angle_class = classify_angles(a, b, c)
            print(f"{side_class} {angle_class}")
    if i >= len(lines):
        break