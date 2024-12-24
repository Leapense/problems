def main():
    import sys
    lines = sys.stdin.read().splitlines()
    pointer = 0

    T_X = lines[pointer].split()
    T = int(T_X[0])
    X = int(T_X[1])
    pointer += 1

    N = int(lines[pointer])
    pointer += 1

    available_periods = []

    for _ in range(N):
        K_i = int(lines[pointer])
        pointer += 1
        periods = set(map(int, lines[pointer].split()))
        available_periods.append(periods)
        pointer += 1

    if all(X in periods for periods in available_periods):
        print("YES")
    else:
        print("NO")

if __name__ == '__main__':
    main()