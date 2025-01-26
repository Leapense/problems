import sys
from math import gcd
from itertools import product

class MiaOdds:
    def __init__(self):
        pass

    def read_input(self):
        for line in sys.stdin:
            parts = line.strip().split()
            if parts == ['0', '0', '0', '0']:
                break
            yield parts

    def score(self, dice):
        a, b = dice
        if (a, b) == (2,1) or (a, b) == (1,2):
            return (3, 0)
        if a == b:
            return (2, a)
        high, low = max(a, b), min(a, b)
        return (1, high * 10 + low)

    def compute_odds(self, s0, s1, r0, r1):
        s_options = [range(1,7)] if s0 != '*' else [range(1,7)]
        if s0 == '*':
            s0_values = range(1,7)
        else:
            s0_values = [int(s0)]
        if s1 == '*':
            s1_values = range(1,7)
        else:
            s1_values = [int(s1)]
        r0_values = range(1,7) if r0 == '*' else [int(r0)]
        r1_values = range(1,7) if r1 == '*' else [int(r1)]
        total = 0
        win = 0
        for s0_val, s1_val, r0_val, r1_val in product(s0_values, s1_values, r0_values, r1_values):
            total +=1
            p1 = self.score((s0_val, s1_val))
            p2 = self.score((r0_val, r1_val))
            if p1 > p2:
                win +=1
        if win == 0:
            return '0'
        if win == total:
            return '1'
        g = gcd(win, total)
        return f"{win//g}/{total//g}"

    def run(self):
        for parts in self.read_input():
            s0, s1, r0, r1 = parts
            print(self.compute_odds(s0, s1, r0, r1))

MiaOdds().run()
