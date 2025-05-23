def solve():
    import sys
    input = sys.stdin.readline

    N, S = map(int, input().split())
    info = [None] * (N + 1)
    for i in range(1, N + 1):
        q, v = map(int, input().split())
        info[i] = (q, v)

    pos = S
    power = 1
    direction = 1
    broken_targets = set()
    
    start_type, start_val = info[pos]
    if start_type == 1:
        if power >= start_val:
            broken_targets.add(pos)
    else:
        power += start_val
        direction *= -1
    visited = set()
    while True:
        next_pos = pos + direction * power

        if not (1 <= next_pos <= N):
            break
        state = (next_pos, power, direction)
        if state in visited:
            break

        visited.add(state)

        pos = next_pos
        loc_type, loc_val = info[pos]

        if loc_type == 1:
            if power >= loc_val:
                broken_targets.add(pos)

        else:
            power += loc_val
            direction *= -1

    print(len(broken_targets))

solve()