N, A, B = map(int, input().split())

x2 = (N + 1) // 2
y2 = (N + 1) // 2

x_start = max(1, x2 - (A - 1))
x_end = min(N, x2 + (A - 1))
excluded_rows = x_end - x_start + 1
available_rows = N - excluded_rows

y_start = max(1, y2 - (B - 1))
y_end = min(N, y2 + (B - 1))
excluded_cols = y_end - y_start + 1
available_cols = N - excluded_cols

total_seats = available_rows * available_cols

if total_seats == 0:
    print(0)
else:
    print(total_seats - 1)