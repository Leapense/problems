#!/usr/bin/env python3

def read_input():
    r, n = map(int, input().split())
    layout = [list(input().strip()) for _ in range(r + 3)]
    return r, n, layout

def get_priority(seat):
    if seat in {'D', 'F'}:
        return 1
    if seat in {'C', 'G'}:
        return 2
    if seat in {'A', 'I'}:
        return 3
    if seat == 'E':
        return 4
    if seat in {'B', 'H'}:
        return 5
    return 100

def get_seat_side(c):
    return 'L' if c in 'ABCD' else 'R'

def seat_assignment(r, n, layout):
    seat_rows = list(range(1, r + 3))
    exit_rows = {0, r // 2 + 1, r + 2}
    passengers = [chr(ord('a') + i) for i in range(n)]
    seat_priorities = {
        'D': 1, 'F': 1, 'C': 2, 'G': 2,
        'A': 3, 'I': 3, 'E': 4, 'B': 5, 'H': 5
    }

    for p in passengers:
        exit_next_rows = [i + 1 for i in exit_rows if 0 <= i + 1 < len(layout) and '-' in layout[i + 1]]
        candidate_rows = exit_next_rows if exit_next_rows else [i for i in seat_rows if '-' in layout[i]]

        max_free = max(layout[i].count('-') for i in candidate_rows)
        filtered_rows = [i for i in candidate_rows if layout[i].count('-') == max_free]

        min_dist = float('inf')
        best_rows = []

        for i in filtered_rows:
            dist = min(abs(i - ex) for ex in exit_rows)
            if dist < min_dist:
                min_dist = dist
                best_rows = [i]
            elif dist == min_dist:
                best_rows.append(i)

        row_to_use = min(best_rows)

        seat_indices = {
            0: 'A', 1: 'B', 2: 'C',
            4: 'D', 5: 'E', 6: 'F',
            8: 'G', 9: 'H', 10: 'I'
        }

        free_seats = [(pos, seat_indices[pos]) for pos in seat_indices if layout[row_to_use][pos] == '-']
        free_seats.sort(key=lambda x: seat_priorities[x[1]])

        best_priority = seat_priorities[free_seats[0][1]]
        mode_priority_seats = [seat for seat in free_seats if seat_priorities[seat[1]] == best_priority]

        if len(mode_priority_seats) == 1:
            pos = mode_priority_seats[0][0]
        else:
            left_count = 0
            right_count = 0
            for row in layout:
                for j in [0, 1, 2, 4]:
                    if row[j] == '-':
                        left_count += 1
                for j in [6, 8, 9, 10]:
                    if row[j] == '-':
                        right_count += 1

            candidates = []
            for pos, label in mode_priority_seats:
                side = get_seat_side(label)
                candidates.append((side, pos))

            if left_count > right_count:
                left_pos = [pos for side, pos in candidates if side == 'L']
                pos = min(left_pos)
            elif right_count > left_count:
                right_pos = [pos for side, pos in candidates if side == 'R']
                pos = min(right_pos)
            else:
                left_pos = [pos for side, pos in candidates if side == 'L']
                pos = min(left_pos)

        layout[row_to_use][pos] = p

    return layout

def main():
    r, n, layout = read_input()
    result = seat_assignment(r, n, layout)
    for row in result:
        print(''.join(row))

if __name__ == "__main__":
    main()