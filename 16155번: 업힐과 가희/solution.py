from fractions import Fraction
import sys

def compute_height_at(position, checkpoints):
    index = 0
    while index + 1 < len(checkpoints) and checkpoints[index + 1][0] < position:
        index += 1
    x1, h1 = checkpoints[index]
    x2, h2 = checkpoints[index + 1]
    slope = Fraction(h2 - h1, x2 - x1)
    return Fraction(h1) + slope * (position - x1)

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    points = []
    offset = 1

    for _ in range(n + 1):
        x = int(data[offset])
        h = int(data[offset + 1])
        offset += 2
        points.append((x, h))

    checkpoints = sorted(points)
    s = int(data[offset])
    e = int(data[offset + 1])

    h_s = compute_height_at(s, checkpoints)
    h_e = compute_height_at(e, checkpoints)
    raw_slope = abs(h_e - h_s) / Fraction(e - s)

    if raw_slope.denominator == 1:
        print(raw_slope.numerator)
    else:
        print(f"{raw_slope.numerator}/{raw_slope.denominator}")

if __name__ == "__main__":
    main()