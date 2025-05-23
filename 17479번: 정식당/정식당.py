A, B, C = map(int, input().split())

general_menu = {}
special_menu = {}
service_menu = set()

for _ in range(A):
    name, price = input().split()
    general_menu[name] = int(price)

for _ in range(B):
    name, price = input().split()
    special_menu[name] = int(price)

for _ in range(C):
    service_menu.add(input().strip())

N = int(input())
orders = [input().strip() for _ in range(N)]

general_total = 0
special_total = 0
service_count = 0

for order in orders:
    if order in general_menu:
        general_total += general_menu[order]
    elif order in special_menu:
        special_total += special_menu[order]
    elif order in service_menu:
        service_count += 1

if service_count > 1:
    print("No")
elif general_total + special_total < 50000 and service_count > 0:
    print("No")
elif general_total < 20000 and special_total > 0:
    print("No")
else:
    print("Okay")