import math

SQRT2 = math.sqrt(2)
INV_SQRT2 = 1.0 / SQRT2

direction_factors = {
    "N": (0.0, 1.0),
    "NE": (INV_SQRT2, INV_SQRT2),
    "E": (1.0, 0.0),
    "SE": (INV_SQRT2, -INV_SQRT2),
    "S": (0.0, -1.0),
    "SW": (-INV_SQRT2, -INV_SQRT2),
    "W": (-1.0, 0.0),
    "NW": (-INV_SQRT2, INV_SQRT2),
}

def solve():
    map_number = 1
    while True:
        line = input()
        if line == "END":
            break

        instructions_str = line[:-1]
        instruction_parts = instructions_str.split(",")

        current_x = 0.0
        current_y = 0.0

        for part in instruction_parts:
            direction_str = ""
            length_str = ""

            if part[-2].isalpha():
                direction_str = part[-2:]
                length_str = part[:-2]
            else:
                direction_str = part[-1:]
                length_str = part[:-1]
            
            length = int(length_str)

            dx_factor, dy_factor = direction_factors[direction_str]

            delta_x = length * dx_factor
            delta_y = length * dy_factor

            current_x += delta_x
            current_y += delta_y
        distance = math.sqrt(current_x ** 2 + current_y ** 2)

        final_x_rounded = round(current_x, 3)
        final_y_rounded = round(current_y, 3)
        distance_rounded = round(distance, 3)

        if final_x_rounded == 0.0:
            final_x_rounded = 0.0
        if final_y_rounded == 0.0:
            final_y_rounded = 0.0

        print(f"Map #{map_number}")
        print(f"The treasure is located at ({final_x_rounded:.3f},{final_y_rounded:.3f}).")
        print(f"The distance to the treasure is {distance_rounded:.3f}.")
        print()

        map_number += 1

if __name__ == "__main__":
    solve()