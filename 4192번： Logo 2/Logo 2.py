import math
def solve_logo_problem(test_cases):
    results = []
    for case in test_cases:
        n_commands, commands = case
        x, y, angle = 0, 0, 0
        missing_index = -1
        missing_type = None
        
        for i, command in enumerate(commands):
            action, value = command.split()
            if value == "?":
                missing_index = i
                missing_type = action
                continue
            value = int(value)
            if action == "fd":
                x += value * math.cos(math.radians(angle))
                y += value * math.sin(math.radians(angle))
            elif action == "bk":
                x -= value * math.cos(math.radians(angle))
                y -= value * math.sin(math.radians(angle))
            elif action == "lt":
                angle = (angle + value) % 360
            elif action == "rt":
                angle = (angle - value) % 360

        if missing_type in ("fd", "bk"):
            distance = math.sqrt(x ** 2 + y ** 2)
            results.append(round(distance))
        else:
            if missing_type == "lt":
                missing_angle = (-angle) % 360
            else:
                missing_angle = angle % 360
            results.append(round(missing_angle))
    return results

t = int(input())
test_cases = []

for _ in range(t):
    n_commands = int(input())
    commands = [input().strip() for _ in range(n_commands)]
    test_cases.append((n_commands, commands))

results = solve_logo_problem(test_cases)
for result in results:
    print(result)