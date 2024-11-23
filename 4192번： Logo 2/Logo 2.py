import sys
import math

def parse_commands(N, command_lines):
    commands = []
    missing_idx = -1

    for i in range(N):
        parts = command_lines[i].split()
        cmd = parts[0]
        arg = parts[1]
        if arg == '?':
            commands.append((cmd, None))
            missing_idx = i
        else:
            commands.append((cmd, int(arg)))
    return commands, missing_idx

def simulate(commands, missing_idx, missing_value = None):
    x, y = 0.0, 0.0
    direction = 0.0

    for i, (cmd, arg) in enumerate(commands):
        if i == missing_idx:
            if missing_value is None:
                raise ValueError("Missing value not provided for simulation.")
            arg = missing_value

        if cmd == 'fd':
            rad = math.radians(direction)
            x += arg * math.cos(rad)
            y += arg * math.sin(rad)
        elif cmd == 'bk':
            rad = math.radians(direction)
            x -= arg * math.cos(rad)
            y -= arg * math.sin(rad)
        elif cmd == 'lt':
            direction = (direction + arg) % 360
        elif cmd == 'rt':
            direction = (direction - arg) % 360
        else:
            pass
    return x, y

def find_missing_movement(commands, missing_idx):
    x, y = 0.0, 0.0
    direction = 0.0

    for i in range(missing_idx):
        cmd, arg = commands[i]
        if cmd == 'fd':
            rad = math.radians(direction)
            x += arg * math.cos(rad)
            y += arg * math.sin(rad)
        elif cmd == 'bk':
            rad = math.radians(direction)
            x -= arg * math.cos(rad)
            y -= arg * math.sin(rad)
        elif cmd == 'lt':
            direction = (direction + arg) % 360
        elif cmd == 'rt':
            direction = (direction - arg) % 360

    missing_direction = direction
    remaining_commands = commands[missing_idx + 1 : ]
    rem_x, rem_y = 0.0, 0.0
    rem_direction = missing_direction
    
    for cmd, arg in remaining_commands:
        if cmd == 'fd':
            rad = math.radians(rem_direction)
            rem_x += arg * math.cos(rad)
            rem_y += arg * math.sin(rad)
        elif cmd == 'bk':
            rad = math.radians(rem_direction)
            rem_x -= arg * math.cos(rad)
            rem_y -= arg * math.sin(rad)
        elif cmd == 'lt':
            rem_direction = (rem_direction + arg) % 360
        elif cmd == 'rt':
            rem_direction = (rem_direction - arg) % 360

    target_x = -(x + rem_x)
    target_y = -(y + rem_y)

    theta = math.radians(missing_direction)

    epsilon = 1e-6
    m1 = m2 = None
    if abs(math.cos(theta)) > epsilon:
        m1 = target_x / math.cos(theta)
    if abs(math.sin(theta)) > epsilon:
        m2 = target_y / math.sin(theta)

    if m1 is not None and m2 is not None:
        if abs(m1 - m2) > epsilon:
            pass
        m = m1
    elif m1 is not None:
        m = m1
    elif m2 is not None:
        m = m2
    else:
        m = 0

    m_int = int(round(m))
    return m_int

def find_missing_rotation(commands, missing_idx, N):
    for a in range(360):
        test_commands = list(commands)
        test_commands[missing_idx] = (test_commands[missing_idx][0], a)
        final_x, final_y = simulate(test_commands, -1)
        if abs(final_x) < 1e-3 and abs(final_y) < 1e-3:
            return a
        
    return 0

def simulate_full(commands):
    x, y = 0.0, 0.0
    direction = 0.0

    for cmd, arg in commands:
        if cmd == 'fd':
            rad = math.radians(direction)
            x += arg * math.cos(rad)
            y += arg * math.sin(rad)
        elif cmd == 'bk':
            rad = math.radians(direction)
            x -= arg * math.cos(rad)
            y -= arg * math.sin(rad)
        elif cmd == 'lt':
            direction = (direction + arg) % 360
        elif cmd == 'rt':
            direction = (direction - arg) % 360

    return x, y

def main():
    input_lines = sys.stdin.read().splitlines()
    ptr = 0
    T = int(input_lines[ptr].strip())
    ptr += 1

    for _ in range(T):
        if ptr >= len(input_lines):
            break
        N_line = input_lines[ptr].strip()
        while N_line == '':
            ptr += 1
            if ptr >= len(input_lines):
                break
            N_line = input_lines[ptr].strip()
        if N_line == '':
            N = 0
        else:
            N = int(N_line)
            ptr +=1
        command_lines = []
        for _ in range(N):
            if ptr >= len(input_lines):
                break
            cmd_line = input_lines[ptr].strip()
            command_lines.append(cmd_line)
            ptr +=1
        commands, missing_idx = parse_commands(N, command_lines)
        missing_cmd, _ = commands[missing_idx]
        if missing_cmd in ['fd', 'bk']:
            m = find_missing_movement(commands, missing_idx)
            print(m)
        elif missing_cmd in ['lt', 'rt']:
            a = find_missing_rotation(commands, missing_idx, N)
            print(a)
        else:
            print(0)

if __name__ == '__main__':
    main()