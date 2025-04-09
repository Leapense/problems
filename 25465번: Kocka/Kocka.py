import sys
def main():
    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    N = int(next(it))
    Q = int(next(it))
    prednja = [[[N, 0] for _ in range(N)] for _ in range(N)]
    straznja = [[[-1, 0] for _ in range(N)] for _ in range(N)]
    lijeva = [[[N, 0] for _ in range(N)] for _ in range(N)]
    desna = [[[-1, 0] for _ in range(N)] for _ in range(N)]
    out_lines = []
    for _ in range(Q):
        typ = next(it)
        if typ == "1":
            x = int(next(it)) - 1
            y = int(next(it)) - 1
            z = int(next(it)) - 1
            c = next(it)
            if z < prednja[x][y][0]:
                prednja[x][y][0] = z
                prednja[x][y][1] = c
            elif z == prednja[x][y][0]:
                prednja[x][y][1] = c
            if z > straznja[x][y][0]:
                straznja[x][y][0] = z
                straznja[x][y][1] = c
            elif z == straznja[x][y][0]:
                straznja[x][y][1] = c
            if y < lijeva[x][z][0]:
                lijeva[x][z][0] = y
                lijeva[x][z][1] = c
            elif y == lijeva[x][z][0]:
                lijeva[x][z][1] = c
            if y > desna[x][z][0]:
                desna[x][z][0] = y
                desna[x][z][1] = c
            elif y == desna[x][z][0]:
                desna[x][z][1] = c
        else:
            side = next(it)
            if side == "prednja":
                for x in range(N):
                    row = []
                    for y in range(N):
                        if prednja[x][y][0] == N:
                            row.append("0")
                        else:
                            row.append(prednja[x][y][1])
                    out_lines.append(" ".join(row))
            elif side == "straznja":
                for x in range(N):
                    row = []
                    for j in range(N):
                        y = N - 1 - j
                        if straznja[x][y][0] == -1:
                            row.append("0")
                        else:
                            row.append(straznja[x][y][1])
                    out_lines.append(" ".join(row))
            elif side == "lijeva":
                for x in range(N):
                    row = []
                    for z in range(N):
                        if lijeva[x][z][0] == N:
                            row.append("0")
                        else:
                            row.append(lijeva[x][z][1])
                    out_lines.append(" ".join(row))
            elif side == "desna":
                for x in range(N):
                    row = []
                    for j in range(N):
                        z = N - 1 - j
                        if desna[x][z][0] == -1:
                            row.append("0")
                        else:
                            row.append(desna[x][z][1])
                    out_lines.append(" ".join(row))
    sys.stdout.write("\n".join(out_lines))
if __name__=="__main__":
    main()
