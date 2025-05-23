#!/usr/bin/env python3
import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    if len(data) < 28:
        return
    
    p = [[0.0] * 8 for _ in range(8)]
    pos = 0

    for i in range(8):
        for j in range(i+1, 8):
            p[i][j] = data[pos] / 100.0
            pos += 1

    for i in range(8):
        for j in range(i):
            p[i][j] = 1.0 - p[j][i]

    P = [0.0] * 8
    P[0] = p[0][1]
    P[1] = 1.0 - p[0][1]
    P[2] = p[2][3]
    P[3] = 1.0 - p[2][3]
    P[4] = p[4][5]
    P[5] = 1.0 - p[4][5]
    P[6] = p[6][7]
    P[7] = 1.0 - p[6][7]

    L = [0.0] * 4
    L[0] = P[0] * (P[2] * p[0][2] + P[3] * p[0][3])
    L[1] = P[1] * (P[2] * p[1][2] + P[3] * p[1][3])
    L[2] = P[2] * (P[0] * p[2][0] + P[1] * p[2][1])
    L[3] = P[3] * (P[0] * p[3][0] + P[1] * p[3][1])

    R = [0.0] * 4
    R[0] = P[4] * (P[6] * p[4][6] + P[7] * p[4][7])
    R[1] = P[5] * (P[6] * p[5][6] + P[7] * p[5][7])
    R[2] = P[6] * (P[4] * p[6][4] + P[5] * p[6][5])
    R[3] = P[7] * (P[4] * p[7][4] + P[5] * p[7][5])

    ans = [0.0] * 8

    for i in range(4):
        ans[i] = L[i] * (R[0]*p[i][4] + R[1]*p[i][5] + R[2]*p[i][6] + R[3]*p[i][7])

    for j in range(4):
        ans[j+4] = R[j] * (L[0]*p[j+4][0] + L[1]*p[j+4][1] + L[2]*p[j+4][2] + L[3]*p[j+4][3])

    print(" ".join(str(x) for x in ans))

if __name__ == "__main__":
    main()