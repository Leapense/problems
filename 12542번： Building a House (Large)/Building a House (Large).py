def max_rectangle_area(matrix):
    if not matrix:
        return 0
    rows = len(matrix)
    cols = len(matrix[0])

    heights = [0] * cols
    max_area = 0

    for row in range(rows):
        for col in range(cols):
            if matrix[row][col] in {'G', 'S'}:
                heights[col] += 1
            else:
                heights[col] = 0

        stack = []
        for i in range(cols + 1):
            while stack and (i == cols or heights[i] < heights[stack[-1]]):
                h = heights[stack.pop()]
                w = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, h * w)
            stack.append(i)
    return max_area

def main():
    import sys

    input = sys.stdin.read
    data = input().split()
    idx = 0
    N = int(data[idx])
    idx += 1

    for case_num in range(1, N + 1):
        L = int(data[idx])
        W = int(data[idx + 1])
        idx += 2

        matrix = []
        for _ in range(W):
            row = data[idx]
            matrix.append(list(row))
            idx += 1
        area = max_rectangle_area(matrix)
        print(f"Case #{case_num}: {area}")

if __name__ == '__main__':
    main()