def pink_bean_raid():
    import sys
    input = sys.stdin.read
    data = input().split()

    C_U, D_U = int(data[0]), int(data[1])
    C_D, D_D = int(data[2]), int(data[3])
    C_P, D_P = int(data[4]), int(data[5])
    H = int(data[6])

    current_time = 0
    remaining_health = H

    while remaining_health > 0:
        if current_time % C_U == 0:
            remaining_health -= D_U
        if current_time % C_D == 0:
            remaining_health -= D_D
        if current_time % C_P == 0:
            remaining_health -= D_P

        if remaining_health <= 0:
            print(current_time)
            return
        
        current_time += 1

pink_bean_raid()