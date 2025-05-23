import sys

def main():
    cntH = [[0] * 26 for _ in range(3)]
    cntV = [[0] * 26 for _ in range(3)]

    for r in range(6):
        line = sys.stdin.readline().strip()
        for c in range(9):
            color_index = ord(line[c]) - ord('A')
            cntH[r // 2][color_index] += 1
            cntV[c // 3][color_index] += 1

    best = 0
    for i in range(26):
        for j in range(26):
            if i == j:
                continue
            for k in range(26):
                if j == k:
                    continue
                sumH = cntH[0][i] + cntH[1][j] + cntH[2][k]
                sumV = cntV[0][i] + cntV[1][j] + cntV[2][k]
                if sumH > best:
                    best = sumH
                if sumV > best:
                    best = sumV

    total_cells = 6 * 9
    min_changes = total_cells - best
    print(min_changes)

if __name__ == '__main__':
    main()