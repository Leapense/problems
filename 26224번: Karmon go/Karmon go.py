def solve_karmon_go(input_line):
    _, inc_0, _, mul_1, inc_1 = input_line.split()
    
    # Convert to appropriate types
    inc_0 = int(inc_0)
    mul_1 = float(mul_1)
    inc_1 = int(inc_1)
    
    # Compare inc_0 * mul_1 and inc_1
    if inc_0 * mul_1 > inc_1:
        print("Power up, Evolve")
    elif inc_0 * mul_1 < inc_1:
        print("Evolve, Power up")
    else:
        print("Whatever")

input_line = input().strip()
solve_karmon_go(input_line)