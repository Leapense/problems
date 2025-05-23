import math

def find_treasure(a, b):
    treasure = math.sqrt(a * b)
    return treasure, treasure

if __name__ == "__main__":
    a, b = map(int, input().split())
    x, y = find_treasure(a, b)
    print(f"{x:.10f} {y:.10f}")