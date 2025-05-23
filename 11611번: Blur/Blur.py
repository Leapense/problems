import sys
import math

def main():
    input_data = sys.stdin.read().strip().split()
    w = int(input_data[0])
    h = int(input_data[1])
    b = int(input_data[2])
    idx = 3
    image = []

    for i in range(h):
        row = []
        for j in range(w):
            row.append(int(input_data[idx]))
            idx += 1
        image.append(row)

    for _ in range(b):
        new_image = [[0] * w for _ in range(h)]
        for i in range(h):
            for j in range(w):
                total = 0
                for di in (-1, 0, 1):
                    for dj in (-1, 0, 1):
                        ni = (i + di) % h
                        nj = (j + dj) % w
                        total += image[ni][nj]
                new_image[i][j] = total
        image = new_image

    denom = 9 ** b
    distinct = set()
    for i in range(h):
        for j in range(w):
            num = image[i][j]
            g = math.gcd(num, denom)
            simplified = (num // g, denom // g)
            distinct.add(simplified)
    print(len(distinct))

if __name__ == "__main__":
    main()