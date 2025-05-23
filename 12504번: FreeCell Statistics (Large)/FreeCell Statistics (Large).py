def main():
    import sys, math
    input_data = sys.stdin.read().split()
    t = int(input_data[0])
    index = 1
    results = []
    for case in range(1, t + 1):
        N = int(input_data[index]); PD = int(input_data[index + 1]); PG = int(input_data[index + 2])
        index += 3
        possible = True
        if (PG == 100 and PD != 100) or (PG == 0 and PD != 0):
            possible = False
        else:
            g = math.gcd(PD, 100)
            denom = 100 // g
            if denom > N:
                possible = False
        results.append("Case #{}: {}".format(case, "Possible" if possible else "Broken"))
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    main()