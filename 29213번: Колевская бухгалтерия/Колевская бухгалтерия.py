def count_possible_triples(a, b, c):
    count = 0
    for A in range(a, a + c + 1):
        for Z in range(b, b + c + 1):
            R = c - (A - a) - (Z - b)
            if R >= 0 and A > Z:  # Change the equality condition to strict greater
                count += 1
    return count

a, b, c = map(int, input().split())
print(count_possible_triples(a, b, c))