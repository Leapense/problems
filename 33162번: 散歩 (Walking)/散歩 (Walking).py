def calculate_distance(x):
    forward_distance = 3
    backward_distance = 2

    distance = 0
    for i in range(x):
        if i % 2 == 0:
            distance += forward_distance
        else:
            distance -= backward_distance

    return distance

if __name__ == '__main__':
    x = int(input().strip())
    print(calculate_distance(x))