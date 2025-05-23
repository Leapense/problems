import sys
import math

def solve_case(commands):
    angle = 0  # in degrees
    total_x = 0.0
    total_y = 0.0
    missing_cmd = None
    direction_at_missing = None  # angle in degrees at missing command

    for idx, (cmd, arg) in enumerate(commands):
        if arg != '?':
            arg = int(arg)
            if cmd == 'fd':
                rad = math.radians(angle)
                total_x += arg * math.cos(rad)
                total_y += arg * math.sin(rad)
            elif cmd == 'bk':
                rad = math.radians(angle)
                total_x -= arg * math.cos(rad)
                total_y -= arg * math.sin(rad)
            elif cmd == 'lt':
                angle += arg
                angle %= 360
            elif cmd == 'rt':
                angle -= arg
                angle %= 360
        else:
            # Missing command
            missing_cmd = (cmd, idx)
            direction_at_missing = angle % 360  # Save the angle at missing command

    if missing_cmd is None:
        # Should not happen, but handle just in case
        return 0

    cmd, idx = missing_cmd

    if cmd == 'fd' or cmd == 'bk':
        direction = 1 if cmd == 'fd' else -1
        rad = math.radians(direction_at_missing)
        cos_theta = math.cos(rad)
        sin_theta = math.sin(rad)
        n_values = []

        # Handle potential division by zero
        n_x = None
        n_y = None
        eps = 1e-8
        if abs(cos_theta) > eps:
            n_x = - total_x / (cos_theta * direction)
        if abs(sin_theta) > eps:
            n_y = - total_y / (sin_theta * direction)

        # Prefer integer solutions, so check both n_x and n_y
        n_candidates = []
        if n_x is not None:
            n_candidates.append(n_x)
        if n_y is not None:
            n_candidates.append(n_y)
        if n_x is None and n_y is None:
            # Angle is such that both cos and sin are zero (should not happen)
            return 0

        # Since there should be only one correct answer, find the integer n that satisfies both equations
        for n in n_candidates:
            n_int = int(round(n))
            if n_int < 0:
                continue
            # Check if n_int satisfies both equations
            dx = total_x + direction * n_int * cos_theta
            dy = total_y + direction * n_int * sin_theta
            if abs(dx) < 1e-6 and abs(dy) < 1e-6:
                return n_int
        # If no integer n found that satisfies both, return rounded value
        return int(round(n_candidates[0]))
    elif cmd == 'lt' or cmd == 'rt':
        # Missing angle in turn command
        # Try all possible angles from 0 to 359
        for n in range(360):
            angle = 0  # Reset angle and positions
            total_x = 0.0
            total_y = 0.0
            for c, a in commands:
                if a != '?':
                    a = int(a)
                else:
                    a = n
                if c == 'fd':
                    rad = math.radians(angle)
                    total_x += a * math.cos(rad)
                    total_y += a * math.sin(rad)
                elif c == 'bk':
                    rad = math.radians(angle)
                    total_x -= a * math.cos(rad)
                    total_y -= a * math.sin(rad)
                elif c == 'lt':
                    angle += a
                    angle %= 360
                elif c == 'rt':
                    angle -= a
                    angle %= 360
            if abs(total_x) < 1e-6 and abs(total_y) < 1e-6:
                return n
        # Should not happen, but return 0 if no angle found
        return 0

def main():
    import sys
    sys.setrecursionlimit(1000000)
    T = int(sys.stdin.readline())
    for _ in range(T):
        N = int(sys.stdin.readline())
        commands = []
        for _ in range(N):
            parts = sys.stdin.readline().split()
            cmd = parts[0]
            arg = parts[1]
            commands.append((cmd, arg))
        result = solve_case(commands)
        print(int(result))

if __name__ == "__main__":
    main()