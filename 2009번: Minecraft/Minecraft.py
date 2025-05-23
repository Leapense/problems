def solve():
    import sys
    input = sys.stdin.readline

    n = int(input().strip())
    H = [list(input().strip()) for _ in range(n)]
    R = [list(input().strip()) for _ in range(n)]
    C = [list(input().strip()) for _ in range(n)]

    H = [[int(ch) for ch in row] for row in H]
    R = [[int(ch) for ch in row] for row in R]
    C = [[int(ch) for ch in row] for row in C]

    M = [[[0] * n for _ in range(n)] for _ in range(n)]

    for i in range(n):
        req_rows = [j for j in range(n) if C[i][j] == 1]
        req_cols = [k for k in range(n) if R[i][k] == 1]

        if req_rows and not req_cols:
            print("NO")
            return
        if req_cols and not req_rows:
            print("NO")
            return
        
        row_covered = [False] * n
        col_covered = [False] * n

        for j in req_rows:
            found = False
            for k in req_cols:
                if H[j][k] == 1:
                    if M[i][j][k] == 0:
                        M[i][j][k] = 1
                    row_covered[j] = True
                    col_covered[k] = True
                    found = True
                    break
            if not found:
                print("NO")
                return
        for k in req_cols:
            if not col_covered[k]:
                found = False
                for j in req_rows:
                    if H[j][k] == 1:
                        if M[i][j][k] == 0:
                            M[i][j][k] = 1
                        row_covered[j] = True
                        col_covered[k] = True
                        found = True
                        break
                if not found:
                    print("NO")
                    return
    for j in range(n):
        for k in range(n):
            if H[j][k] == 1:
                ok = False
                for i in range(n):
                    if M[i][j][k] == 1:
                        ok = True
                        break
                if not ok:
                    placed = False
                    for i in range(n):
                        if R[i][k] == 1 and C[i][j] == 1:
                            M[i][j][k] = 1
                            placed = True
                            break
                    if not placed:
                        print("NO")
                        return
            else:
                for i in range(n):
                    if M[i][j][k] == 1:
                        print("NO")
                        return
    print("YES")
    for i in range(n):
        for j in range(n):
            print("".join(str(x) for x in M[i][j]))

if __name__ == "__main__":
    solve()