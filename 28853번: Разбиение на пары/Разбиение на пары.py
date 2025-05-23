def minimize_discomfort(a, b, c, d):
    discomfort = abs(a - c) + abs(b - d)
    return discomfort

a, b, c, d = map(int, input().split())

print(minimize_discomfort(a, b, c, d))