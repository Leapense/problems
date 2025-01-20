import math

def P3(x, y, z):
    min_dist = float('inf')
    cube_size = 100
    faces = []

    if z == 0 or z == cube_size:
        faces.append('z')
    if x == 0 or x == cube_size:
        faces.append('x')
    if y == 0 or y == cube_size:
        faces.append('y')

    for face in faces:
        if face == 'z':
            if z == 0:
                unfolded = []
                unfolded.append(((x, y), (cube_size, cube_size, cube_size)))
                for direction in ['x+', 'x-', 'y+', 'y-']:
                    if direction == 'x+':
                        px, py = x, y
                        tx, ty, tz = cube_size, cube_size, cube_size
                        dist = math.sqrt((cube_size - px) ** 2 + (cube_size - py) ** 2)
                        min_dist = min(min_dist, dist)
                    elif direction == 'x-':
                        px, py = x, y
                        tx, ty, tz = cube_size, cube_size, cube_size
                        dist = math.sqrt((cube_size - px) ** 2 + (cube_size - py) ** 2)
                        min_dist = min(min_dist, dist)
                    elif direction == 'y+':
                        px, py = x, y
                        tx, ty, tz = cube_size, cube_size, cube_size
                        dist = math.sqrt((cube_size - px) ** 2 + (cube_size - py) ** 2)
                        min_dist = min(min_dist, dist)
                    elif direction == 'y-':
                        px, py = x, y
                        tx, ty, tz = cube_size, cube_size, cube_size
                        dist = math.sqrt((cube_size - px) ** 2 + (cube_size - py) ** 2)
                        min_dist = min(min_dist, dist)
            else:
                dist = math.sqrt((cube_size - x) ** 2 + (cube_size - y) ** 2)
                min_dist = min(min_dist, dist)
        elif face == 'x':
            if x == 0:
                dist = math.sqrt((cube_size - y) ** 2 + (cube_size - z) ** 2)
                min_dist = min(min_dist, dist)
            else:
                dist = math.sqrt((cube_size - y) ** 2 + (cube_size - z) ** 2)
                min_dist = min(min_dist, dist)
        elif face == 'y':
            if y == 0:
                dist = math.sqrt((cube_size - x) ** 2 + (cube_size - z) ** 2)
                min_dist = min(min_dist, dist)
            else:
                dist = math.sqrt((cube_size - x) ** 2 + (cube_size - z) ** 2)
                min_dist = min(min_dist, dist)
    return min_dist