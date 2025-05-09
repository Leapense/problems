import sys

class Platform:
    def __init__(self, y, x1, x2):
        self.y = y
        self.x1 = x1
        self.x2 = x2

def calculate_total_pillar_length(platforms_coords):
    N = len(platforms_coords)
    if N == 0:
        return 0
    
    platforms = []
    for y, x1, x2 in platforms_coords:
        platforms.append(Platform(y, x1, x2))

    total_pillar_length = 0

    for i in range(N):
        current_platform = platforms[i]
        pillar_x_left = current_platform.x1 + 0.5
        support_y_left = 0

        for j in range(N):
            if i == j:
                continue
            other_platform = platforms[j]
            if other_platform.y < current_platform.y:
                if other_platform.x1 < pillar_x_left < other_platform.x2:
                    support_y_left = max(support_y_left, other_platform.y)

        total_pillar_length += (current_platform.y - support_y_left)

        pillar_x_right = current_platform.x2 - 0.5
        support_y_right = 0

        for j in range(N):
            if i == j:
                continue
            other_platform = platforms[j]
            if other_platform.y < current_platform.y:
                if other_platform.x1 < pillar_x_right < other_platform.x2:
                    support_y_right = max(support_y_right, other_platform.y)

        total_pillar_length += (current_platform.y - support_y_right)

    return total_pillar_length

def main():
    N = int(sys.stdin.readline())
    platforms_input_data = []
    for _ in range(N):
        y, x1, x2 = map(int, sys.stdin.readline().split())
        platforms_input_data.append((y, x1, x2))

    result = calculate_total_pillar_length(platforms_input_data)
    print(result)


if __name__ == "__main__":
    main()