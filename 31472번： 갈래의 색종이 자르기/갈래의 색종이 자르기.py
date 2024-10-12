import math

W = int(input().strip())

full_area = 2 * W

side_length = int(math.sqrt(full_area))

perimeter = 4 * side_length

print(perimeter)