n = int(input())
positions = sorted(int(input()) for _ in range(n))

def explode(pos, direction):
    exploded, radius, last = 0, 1, pos
    while True:
        next_pos = last
        if direction == -1:
            while next_pos > 0 and positions[last] - positions[next_pos - 1] <= radius:
                next_pos -= 1
        else:
            while next_pos < n - 1 and positions[next_pos + 1] - positions[last] <= radius:
                next_pos += 1
        if next_pos == last:
            break
        exploded += abs(next_pos - last)
        last = next_pos
        radius += 1
    return exploded

max_exploded = 0
for i in range(n):
    total = 1 + explode(i, -1) + explode(i, 1)
    max_exploded = max(max_exploded, total)

print(max_exploded)