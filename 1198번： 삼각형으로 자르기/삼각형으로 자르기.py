#!/usr/bin/env python3
import sys

def triangle_area(p, q, r):
    return abs(p[0]*(q[1]-r[1]) + q[0]*(r[1]-p[1]) + r[0]*(p[1]-q[1])) / 2.0

def main():
    input = sys.stdin.readline
    N = int(input().strip())
    points = []
    for _ in range(N):
        x, y = map(int, input().split())
        points.append((x, y))

    max_area = 0.0

    for i in range(N):
        for j in range(i+1, N):
            for k in range(j+1, N):
                area = triangle_area(points[i], points[j], points[k])
                if area > max_area:
                    max_area = area

    print(f"{max_area:.9f}")

if __name__ == "__main__":
    main()