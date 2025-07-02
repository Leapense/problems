import sys

def solve():
    try:
        y0_str, m0_str, d0_str, t0_str, p0_str = sys.stdin.readline().split()
        y0, m0, d0 = map(int, (y0_str, m0_str, d0_str))
        t0, p0 = map(float, (t0_str, p0_str))

        y1_str, m1_str, d1_str, t1_str, p1_str = sys.stdin.readline().split()
        y1, m1, d1 = map(int, (y1_str, m1_str, d1_str))
        t1, p1 = map(float, (t1_str, p1_str))
    except (IOError, ValueError) as e:
        return 
    
    t_input = 2 * t0 - t1
    p_input = 2 * p0 - p1

    DAYS_IN_MONTH = 30
    MONTHS_IN_YEAR = 12
    DAYS_IN_YEAR = DAYS_IN_MONTH * MONTHS_IN_YEAR

    days0 = (y0 * DAYS_IN_YEAR) + ((m0 - 1) * DAYS_IN_MONTH) + (d0 - 1)
    days1 = (y1 * DAYS_IN_YEAR) + ((m1 - 1) * DAYS_IN_MONTH) + (d1 - 1)

    days_input_total = 2 * days0 - days1
    y_input = days_input_total // DAYS_IN_YEAR
    remaining_days = days_input_total % DAYS_IN_YEAR

    m_input = (remaining_days // DAYS_IN_MONTH) + 1
    d_input = (remaining_days % DAYS_IN_MONTH) + 1

    print(f"{y_input} {m_input} {d_input} {t_input:.3f} {p_input:.3f}")

if __name__ == "__main__":
    solve()