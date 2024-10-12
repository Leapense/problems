import datetime

def rabbit(x, n, d, m, g):
    start_date = datetime.date(g, m, d)

    total_days = (x - 1) * 2 * n + n - 1

    end_date = start_date + datetime.timedelta(days=total_days)

    print(end_date.day, end_date.month, end_date.year)

x, n = map(int, input().split())
d, m, g = map(int, input().split())

rabbit(x, n, d, m, g)