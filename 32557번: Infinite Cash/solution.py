import sys

def bint():
    return int(sys.stdin.readline().strip(), 2)

s = bint()
d = bint()
m = bint()

day = 0
bal = m
seen = set()

while True:
    if bal == 0:
        print(bin(day + 1)[2:])
        break
    dead_in = bal.bit_length() + 1
    if dead_in <= d:
        print(bin(day + dead_in)[2:])
        break
    day += d
    bal_next = (bal >> d) + s
    if bal_next == bal or bal_next in seen:
        print("Infinite money!")
        break
    seen.add(bal)
    bal = bal_next