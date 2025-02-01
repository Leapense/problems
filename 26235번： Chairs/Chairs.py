def solve():
    import sys
    input_data = sys.stdin.read().strip().split()

    N = int(input_data[0]); M = int(input_data[1]); K = int(input_data[2])

    chairs = []
    idx = 3
    for _ in range(K):
        x = int(input_data[idx])
        y = int(input_data[idx + 1])
        idx += 2
        chairs.append((x, y))

    points = chairs[:]
    points.append((1,1))
    points.append((N,M))

    points.sort(key=lambda x: (x[0],x[1]))

    for i in range(len(points) - 1):
        if points[i][0] > points[i+1][0] or points[i][1] > points[i+1][1]:
            print("Impossible")
            return
        
    if points[0] != (1,1) or points[-1] != (N,M):
        print("Impossible")
        return
    
    path = []
    for i in range(len(points) - 1):
        x1, y1 = points[i]
        x2, y2 = points[i+1]
        down_moves =  x2 - x1
        right_moves = y2 - y1

        if down_moves < 0 or right_moves < 0:
            print("Impossible")
            return
        
        path.append('D' * down_moves)
        path.append('R' * right_moves)

    print("".join(path))

if __name__ == "__main__":
    solve()