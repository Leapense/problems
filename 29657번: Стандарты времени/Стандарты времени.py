def convert_time(a1, b1, c1, a2, b2, c2, h1, m1, s1):
    total_seconds = h1 * (b1 * c1) + m1 * c1 + s1

    h2 = total_seconds // (b2 * c2)
    remaining_seconds = total_seconds % (b2 * c2)
    m2 = remaining_seconds // c2
    s2 = remaining_seconds % c2

    return h2, m2, s2

a1, b1, c1 = map(int, input().strip().split())
a2, b2, c2 = map(int, input().strip().split())
h1, m1, s1 = map(int, input().strip().split())

h2, m2, s2 = convert_time(a1, b1, c1, a2, b2, c2, h1, m1, s1)
print(h2, m2, s2)