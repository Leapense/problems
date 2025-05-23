def decimal_to_negabase(num, R):
    if num == 0:
        return "0"
    n = num
    digits = []
    while n != 0:
        remainder = n % R
        n = (n - remainder) // (-R)
        digits.append(str(remainder))
    return "".join(reversed(digits))

def negabase_to_decimal(negabase, R):
    n = 0
    power = 1
    for digit in negabase[::-1]:
        n += int(digit) * power
        power *= -R
    return n

def main():
    import sys
    data = sys.stdin.read().splitlines()
    results = []
    for line in data:
        if line.strip() == "end":
            break
        parts = line.split()
        if parts[0].startswith("to-"):
            R = int(parts[0][3:])
            num = int(parts[1])
            results.append(decimal_to_negabase(num, R))
        elif parts[0].startswith("from-"):
            R = int(parts[0][5:])
            negabase = parts[1]
            results.append(str(negabase_to_decimal(negabase, R)))
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    main()