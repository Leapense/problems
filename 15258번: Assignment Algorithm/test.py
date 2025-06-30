import time
import tracemalloc
import matplotlib.pyplot as plt
import random


def generate_airplane(r, empty_ratio=0.5):
    seat_row_pattern = ['A', 'B', 'C', '.', 'D', 'E', 'F', '.', 'G', 'H', 'I']
    layout = []

    layout.append(['.'] * 11)  # Exit row at front

    for i in range(r):
        row = []
        for ch in seat_row_pattern:
            if ch == '.':
                row.append('.')
            else:
                if random.random() < empty_ratio:
                    row.append('-')  # Empty seat
                else:
                    row.append('#')  # Reserved seat
        layout.append(row)

        if i == r//2 - 1:
            layout.append(['.'] * 11)  # middle exit row

    layout.append(['.'] * 11)  # rear exit row
    return layout


def count_empty(layout):
    return sum(row.count('-') for row in layout)


def simulate_airplane(r, n):
    from copy import deepcopy
    passengers = min(n, 26)

    layout = generate_airplane(r)
    original = deepcopy(layout)

    return measure_time_and_memory(lambda: seat_assignment(r, passengers, layout))


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

        if not candidate_rows:
            continue  # No available seats for this passenger, skip

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
                side = 'L' if label in 'ABCD' else 'R'
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


def measure_time_and_memory(func):
    tracemalloc.start()
    start = time.perf_counter()
    func()
    end = time.perf_counter()
    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()
    elapsed_ms = (end - start) * 1000
    return elapsed_ms, peak / 1024  # ms, KB


def draw_graph():
    row_counts = [2, 4, 8, 16, 24, 32, 40, 48]  # r values (even only)
    passenger_counts = [1, 5, 10, 15, 20, 25]

    time_results = []
    mem_results = []

    for r in row_counts:
        elapsed, mem_kb = simulate_airplane(r, 20)  # fix n=20
        time_results.append(elapsed)
        mem_results.append(mem_kb)

    fig, ax1 = plt.subplots()

    ax1.set_xlabel('Seat Rows (r)')
    ax1.set_ylabel('Time (ms)', color='tab:blue')
    ax1.plot(row_counts, time_results, label='Time (ms)', color='tab:blue', marker='o')
    ax1.tick_params(axis='y', labelcolor='tab:blue')

    ax2 = ax1.twinx()
    ax2.set_ylabel('Memory (KB)', color='tab:red')
    ax2.plot(row_counts, mem_results, label='Memory (KB)', color='tab:red', marker='x')
    ax2.tick_params(axis='y', labelcolor='tab:red')

    plt.title("Time and Space Complexity vs Row Count")
    fig.tight_layout()
    plt.grid(True)
    plt.show()


if __name__ == "__main__":
    draw_graph()