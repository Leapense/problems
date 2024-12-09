def number_to_coords(n):
    if n == 1:
        return (0, 0)
    k = 1
    while True:
        S = 2 + 3 * k * (k - 1)
        E = 1 + 3 * k * (k + 1)
        if S <= n <= E:
            break
        k += 1
    offset = n - S
    side = offset // k
    p = offset % k
    directions = [(1, -1), (1, 0), (0, 1), (-1, 1), (-1, 0), (0, -1)]
    q, r = 0, k
    for s in range(side):
        q += directions[s][0] * k
        r += directions[s][1] * k
    q += directions[side][0] * p
    r += directions[side][1] * p
    return (q, r)

def hex_distance(a, b):
    q1, r1 = a
    q2, r2 = b
    x1, z1 = q1, r1
    y1 = -x1 - z1
    x2, z2 = q2, r2
    y2 = -x2 - z2
    return max(abs(x1 - x2), abs(y1 - y2), abs(z1 - z2))

def main():
    import sys
    for line in sys.stdin:
        a, b = map(int, line.strip().split())
        if a == 0 and b == 0:
            break
        coord_a = number_to_coords(a)
        coord_b = number_to_coords(b)
        distance = hex_distance(coord_a, coord_b)
        print(distance)

if __name__ == '__main__':
    main()