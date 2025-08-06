import random
import sys

MAX_SIZE_DEFAULT = 2 * 1024 * 1024


def build_case():
    n = random.randint(1, 100)
    m = random.randint(1, 100)
    t_val = random.randint(1, 100)
    c_val = random.randint(1, 100)
    grid = [['0'] * m for _ in range(n)]
    for col in range(m):
        required_row = random.randint(0, n - 1)
        grid[required_row][col] = '1'
        for row in range(n):
            if grid[row][col] == '0' and random.random() < 0.3:
                grid[row][col] = '1'
    return n, m, t_val, c_val, [''.join(row) for row in grid]


def main():
    cases_requested = int(sys.argv[1]) if len(sys.argv) > 1 else 10
    max_size = int(sys.argv[2]) if len(sys.argv) > 2 else MAX_SIZE_DEFAULT
    output_lines = []
    for _ in range(cases_requested):
        n, m, t_val, c_val, strings = build_case()
        output_lines.append(f"{n} {m} {t_val} {c_val}")
        output_lines.extend(strings)
        estimated_size = sum(len(line) + 1 for line in output_lines) + len(str(cases_requested)) + 1
        if estimated_size >= max_size:
            break
    final_cases = '\n'.join(output_lines)
    print(len(final_cases.splitlines()))
    print(final_cases)


if __name__ == "__main__":
    main()