def solve():
    import sys
    input_data = sys.stdin.read().strip().split()
    T = int(input_data[0])
    idx = 1

    for _ in range(T):
        n = int(input_data[idx]); idx += 1
        C = int(input_data[idx]); idx += 1

        enemies = list(map(int, input_data[idx:idx+n]))
        idx += n

        pos = 0
        direction = 1

        total_attacks = n + 5

        for attack_count in range(total_attacks):
            enemies[pos] -= C
            if enemies[pos] <= 0:
                direction = -direction

            if attack_count < total_attacks - 1:
                next_pos = pos + direction

                if next_pos < 0 or next_pos >= n:
                    direction = -direction
                    next_pos = pos + direction

                pos = next_pos

        print(pos + 1)

solve()