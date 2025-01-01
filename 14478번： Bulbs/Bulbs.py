def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    idx = 0
    T = int(data[idx]); idx +=1
    for _ in range(T):
        m = int(data[idx]); n = int(data[idx+1]); idx +=2
        grid = []
        for _ in range(m):
            grid.append(list(data[idx])); idx +=1
        covered = [[False]*n for _ in range(m)]
        count =0
        for i in range(m):
            for j in range(n-1,-1,-1):
                if grid[i][j] == '0' and not covered[i][j]:
                    count +=1
                    for k in range(j+1):
                        if grid[i][k] == '0':
                            covered[i][k] = True
                    for k in range(i, m):
                        if grid[k][j] == '0':
                            covered[k][j] = True
        print(count)

if __name__ == "__main__":
    main()