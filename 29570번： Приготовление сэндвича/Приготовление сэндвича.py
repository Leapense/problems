import sys
import itertools

def read_rectangles():
    rectangles = []
    for _ in range(4):
        x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
        rectangles.append((x1, y1, x2, y2))
    return rectangles

def intersection_area(rects):
    if not rects:
        return 0
    x1 = max(rect[0] for rect in rects)
    y1 = max(rect[1] for rect in rects)
    x2 = min(rect[2] for rect in rects)
    y2 = min(rect[3] for rect in rects)

    if x1 < x2 and y1 < y2:
        return (x2 - x1) * (y2 - y1)
    else:
        return 0

def main():
    rectangles = read_rectangles()
    total = 0
    for k in range(1, 5):
        combis = itertools.combinations(rectangles, k)
        sum_area = sum(intersection_area(comb1) for comb1 in combis)
        if k % 2 == 1:
            total += sum_area
        else:
            total -= sum_area
    print(total)

if __name__ == '__main__':
    main()