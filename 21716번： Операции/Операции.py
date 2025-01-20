from math import gcd
def parse(s):
    if '.' in s:
        integer, frac = s.split('.')
        if '(' in frac:
            non_rep, rep = frac.split('(')
            rep = rep.rstrip(')')
        else:
            non_rep, rep = frac, ''
    else:
        integer, non_rep, rep = s, '', ''
    integer = int(integer)
    if rep:
        len_rep = len(rep)
        len_non_rep = len(non_rep)
        if non_rep:
            numerator = integer * (10**len_non_rep * (10**len_rep -1)) + int(non_rep) * (10**len_rep -1) + int(rep)
            denominator = 10**len_non_rep * (10**len_rep -1)
        else:
            numerator = integer * (10**len_rep -1) + int(rep)
            denominator = 10**len_rep -1
    elif non_rep:
        len_non_rep = len(non_rep)
        numerator = integer * (10**len_non_rep) + int(non_rep)
        denominator = 10**len_non_rep
    else:
        numerator = integer
        denominator =1
    return numerator, denominator
s1 = input().strip()
s2 = input().strip()
num1, den1 = parse(s1)
num2, den2 = parse(s2)
sum_num = num1 * den2 + num2 * den1
sum_den = den1 * den2
g = gcd(sum_num, sum_den)
print(f"{sum_num//g}/{sum_den//g}")