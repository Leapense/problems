from decimal import Decimal, getcontext
import sys

getcontext().prec = 100

def decimal_to_ternary(x, precision):
    ternary_digits = []
    x = Decimal(x)
    for _ in range(precision):
        x *= 3
        digit = int(x)
        if digit == 1:
            ternary_digits.append('1')
            x -= 1
        elif digit == 2:
            ternary_digits.append('2')
            x -= 2
        else:
            ternary_digits.append('0')
        if x == 0:
            break
    return ''.join(ternary_digits)

def main():
    input = sys.stdin.read().splitlines()
    idx = 0
    T = int(input[idx])
    idx += 1
    for case in range(1, T+1):
        N = int(input[idx])
        idx += 1
        numbers = []
        for _ in range(N):
            num_str = input[idx]
            idx += 1
            numbers.append(Decimal(num_str))
        num_list = []
        for num in numbers:
            ternary = decimal_to_ternary(str(num), 20)
            first_one = ternary.find('1')
            if first_one != -1:
                round_num = first_one + 1
            else:
                round_num = 1000
            num_list.append( (round_num, float(str(num))) )
        num_list.sort()
        print(f"Case #{case}:")
        for num in num_list:
            num_str = f"{num[1]:.11f}"
            num_str = num_str.rstrip('0').rstrip('.') if '.' in num_str else num_str
            print(num_str)

if __name__ == "__main__":
    main()