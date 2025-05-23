d = int(input())
p = [int(input()) for _ in range(d)]

money = 100
shares = 0

for day in range(d):
    if day < d - 1:
        if p[day + 1] > p[day]:
            buy = min(money // p[day], 100000 - shares)
            money -= buy * p[day]
            shares += buy
        elif p[day + 1] < p[day]:
            money += shares * p[day]
            shares = 0
    else:
        money += shares * p[day]
        shares = 0
print(money)