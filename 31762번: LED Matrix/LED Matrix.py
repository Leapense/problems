def can_display_pattern():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    R, C, K = map(int, data[0].split())

    for i in range(1, R + 1):
        M, P = data[i].split()
        if '*' in P:
            if '-' in M:
                print("N")
                return
    print("Y")

can_display_pattern()