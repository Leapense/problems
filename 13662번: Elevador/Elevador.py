import sys

for line in sys.stdin:
    L, C, R1, R2 = map(int, line.strip().split())
    if L == 0 and C == 0 and R1 == 0 and R2 == 0:
        break
    if 2 * R1 > L or 2 * R1 > C or 2 * R2 > L or 2 * R2 > C:
        print("N")
    else:
        distance_sq = (L - R1 - R2) ** 2 + (C - R1 - R2) ** 2
        if distance_sq >= (R1 + R2) ** 2:
            print("S")
        else:
            print("N")
            