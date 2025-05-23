import sys

def main():
    # import sys
    input = sys.stdin.readline
    N = int(input())
    points_by_color = {}

    for _ in range(N):
        x, y = map(int, input().split())
        if y not in points_by_color:
            points_by_color[y] = []
        points_by_color[y].append(x)

    total_distance = 0

    for color in points_by_color:
        x_list = points_by_color[color]
        x_list.sort()
        length = len(x_list)
        for i in range(length):
            min_distance = float('inf')
            if i > 0:
                min_distance = min(min_distance, abs(x_list[i] - x_list[i-1]))
            if i < length -1:
                min_distance = min(min_distance, abs(x_list[i] - x_list[i+1]))
            if length ==1:
                min_distance =0
            total_distance += min_distance

    print(total_distance)

if __name__ == "__main__":
    main()