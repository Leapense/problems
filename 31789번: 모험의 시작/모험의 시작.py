def start_adventure():
    import sys
    input = sys.stdin.read
    data = input().split()

    N = int(data[0])
    X = int(data[1])
    S = int(data[2])

    index = 3

    can_defeat = False

    for _ in range(N):
        c_i = int(data[index])
        p_i = int(data[index + 1])
        index += 2

        if c_i <= X and p_i > S:
            can_defeat = True
            break

    if can_defeat:
        print("YES")
    else:
        print("NO")

start_adventure()