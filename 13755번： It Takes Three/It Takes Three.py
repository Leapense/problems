import math, sys
from itertools import product

rects = [tuple(map(int, sys.stdin.readline().split())) for _ in range(3)]
total_area = sum(w * h for w, h in rects)
s = int(math.sqrt(total_area))
if s * s != total_area:
    print(0)
    sys.exit()
for rotations in product([False, True], repeat=3):
    oriented = []
    for i in range(3):
        if rotations[i]:
            oriented.append((rects[i][1], rects[i][0]))
        else:
            oriented.append(rects[i])
    r1, r2, r3 = oriented

    if (r1[0] + r2[0] + r3[0] == s and r1[1] == r2[1] == r3[1] == s):
        print(1)
        sys.exit()
    if (r1[1] + r2[1] + r3[1] == s and r1[0] == r2[0] == r3[0] == s):
        print(1)
        sys.exit()
    for i in range(3):
        a, b, c = oriented[i], oriented[(i + 1) % 3], oriented[(i + 2) % 3]
        if a[0] == s:
            if b[0] + c[0] == s and max(b[1], c[1]) + a[1] == s:
                print(1)
                sys.exit()
        if a[1] == s:
            if b[1] + c[1] == s and max(b[0], c[0]) + a[0] == s:
                print(1)
                sys.exit()
    for i in range(3):
        a, b, c = oriented[i], oriented[(i + 1) % 3], oriented[(i + 2) % 3]
        if a[1] == s:
            if b[0] + c[0] == s and max(b[1], c[1]) <= s - a[1]:
                print(1)
                sys.exit()
        if a[0] == s:
            if b[1] + c[1] == s and max(b[0], c[0]) <= s - a[0]:
                print(1)
                sys.exit()
print(0)