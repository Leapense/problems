def rods():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    a1, a2, a3 = int(data[0]), int(data[1]), int(data[2])
    b1, b2, b3 = int(data[3]), int(data[4]), int(data[5])
    L = int(data[6])

    # Create list of rods and sort by length descending
    rods = [(a1, b1), (a2, b2), (a3, b3)]
    rods.sort(reverse=True, key=lambda x: x[0])

    needed_length = L
    total_rods_used = 0

    for length, count in rods:
        if needed_length <= 0:
            break
        if length * count >= needed_length:
            rods_needed = (needed_length + length - 1) // length
            total_rods_used += rods_needed
            needed_length = 0
        else:
            total_rods_used += count
            needed_length -= length * count

    if needed_length > 0:
        print(0)
    else:
        print(total_rods_used)

rods()