def main():
    import sys
    input = sys.stdin.readline

    R, C = map(int, input().split())
    grid = [input().strip() for _ in range(R)]

    words = []

    for i in range(R):
        j = 0
        while j < C:
            if grid[i][j] != '#':
                if j == 0 or grid[i][j-1] == '#':
                    word = ""
                    k = j
                    while k < C and grid[i][k] != '#':
                        word += grid[i][k]
                        k += 1
                    if len(word) >= 2:
                        words.append(word)
                    j = k
                else:
                    j += 1
            else:
                j += 1

    for j in range(C):
        i = 0
        while i < R:
            if grid[i][j] != '#':
                if i == 0 or grid[i-1][j] == '#':
                    word = ""
                    k = i
                    while k < R and grid[k][j] != '#':
                        word += grid[k][j]
                        k += 1
                    if len(word) >= 2:
                        words.append(word)
                    i = k
                else:
                    i += 1
            else:
                i += 1

    words.sort()
    print(words[0])

if __name__ == "__main__":
    main()