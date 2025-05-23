from math import gcd

def solve():
    R_str = input().strip()
    int_part, decimal_part = R_str.split('.')
    R_int = int(int_part) * 100 + int(decimal_part)
    full_circle_int = 36000
    g = gcd(full_circle_int, R_int)
    answer = full_circle_int // g
    print(answer)

solve()