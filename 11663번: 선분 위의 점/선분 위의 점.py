import sys, bisect
def main():
    input = sys.stdin.read().split()
    N, M = int(input[0]), int(input[1])
    points = sorted(map(int, input[2:2+N]))
    output = []
    idx = 2 + N
    for _ in range(M):
        L, R = int(input[idx]), int(input[idx + 1])
        idx += 2
        left = bisect.bisect_left(points, min(L, R))
        right = bisect.bisect_right(points, max(L, R))
        output.append(str(right - left))

    print('\n'.join(output))
if __name__ == '__main__':
    main()