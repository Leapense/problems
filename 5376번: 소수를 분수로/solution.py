import sys
import math

def convert_decimal_to_fraction(s: str) -> (int, int):
    assert s.startswith("0.")
    s_body = s[2:]
    if '(' in s_body:
        non_rep, rep = s_body.split('(')
        rep = rep.rstrip(')')
    else:
        non_rep = s_body
        rep = ''
    
    k = len(non_rep)
    r = len(rep)
    if r == 0:
        num = int(non_rep) if non_rep else 0
        den = 10 ** k
    else:
        full = non_rep + rep
        num_full = int(full)
        num_non = int(non_rep) if non_rep else 0
        num = num_full - num_non
        den = (10 ** (k + r) - 10 ** k)

    g = math.gcd(num, den)
    return num // g, den // g

def main():
    t = int(sys.stdin.readline().strip())
    for _ in range(t):
        s = input().strip()
        num, den = convert_decimal_to_fraction(s)
        print(f"{num}/{den}")

if __name__ == "__main__":
    main()