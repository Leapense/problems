import sys
from itertools import product
import math

def get_hand_tuple(a, b):
    if {a, b} == {1, 2}:
        return (4, 0)
    elif a == b:
        return (3, a)
    else:
        high = max(a, b)
        low = min(a, b)
        return (2, (a + b), high, low)

for line in sys.stdin:
    line = line.strip()
    if line == '0 0 0 0':
        break
    s0, s1, r0, r1 = line.split()
    
    # Generate possible values for player 1's dice
    s0_values = list(range(1, 7)) if s0 == '*' else [int(s0)]
    s1_values = list(range(1, 7)) if s1 == '*' else [int(s1)]
    player1_combos = list(product(s0_values, s1_values))
    
    # Generate possible values for player 2's dice
    r0_values = list(range(1, 7)) if r0 == '*' else [int(r0)]
    r1_values = list(range(1, 7)) if r1 == '*' else [int(r1)]
    player2_combos = list(product(r0_values, r1_values))
    
    count = 0
    total = len(player1_combos) * len(player2_combos)
    
    for (a, b) in player1_combos:
        t1 = get_hand_tuple(a, b)
        for (c, d) in player2_combos:
            t2 = get_hand_tuple(c, d)
            if t1 > t2:
                count += 1
                
    if count == 0:
        print(0)
    elif count == total:
        print(1)
    else:
        g = math.gcd(count, total)
        print(f"{count // g}/{total // g}")