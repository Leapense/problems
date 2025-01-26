n = int(input())
a = list(map(int, input().split()))

dead1 = []
dead2 = []
current_target = 1
output = []

for car in a:
    while True:
        moved = False
        if dead1 and dead1[-1] == current_target:
            output.append(-1)
            dead1.pop()
            current_target += 1
            moved = True
        elif dead2 and dead2[-1] == current_target:
            output.append(-2)
            dead2.pop()
            current_target += 1
            moved = True
        if not moved:
            break

    if not dead1 or (car < dead1[-1]):
        dead1.append(car)
        output.append(1)
    elif not dead2 or (car < dead2[-1]):
        dead2.append(car)
        output.append(2)
    else:
        dead1.append(car)
        output.append(1)

while True:
    moved = False
    if dead1 and dead1[-1] == current_target:
        output.append(-1)
        dead1.pop()
        current_target += 1
        moved = True
    elif dead2 and dead2[-1] == current_target:
        output.append(-2)
        dead2.pop()
        current_target += 1
        moved = True
    else:
        if current_target in dead1:
            index = dead1.index(current_target)
            for _ in range(len(dead1) - index - 1):
                output.append(12)
                car_moved = dead1.pop()
                dead2.append(car_moved)
            output.append(-1)
            dead1.pop()
            current_target += 1
            moved = True
        elif current_target in dead2:
            index = dead2.index(current_target)
            for _ in range(len(dead2) - index - 1):
                output.append(21)
                car_moved = dead2.pop()
                dead1.append(car_moved)
            output.append(-2)
            dead2.pop()
            current_target += 1
            moved = True
        else:
            break
    if not moved:
        break

for cmd in output:
    print(cmd)