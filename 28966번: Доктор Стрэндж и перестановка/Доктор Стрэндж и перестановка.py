def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    a = list(map(int, data[1:1+n]))

    wrong_odd_positions = []
    wrong_even_positions = []

    for i in range(1, n + 1):
        if (i % 2 == 1 and a[i-1] % 2 == 0):  # 홀수 위치에서 짝수 값
            wrong_odd_positions.append(i)
        elif (i % 2 == 0 and a[i-1] % 2 == 1):  # 짝수 위치에서 홀수 값
            wrong_even_positions.append(i)
    
    if len(wrong_odd_positions) == 1 and len(wrong_even_positions) == 1:
        # 교환 후 전체 배열 검사
        odd_pos = wrong_odd_positions[0]
        even_pos = wrong_even_positions[0]
        a[odd_pos - 1], a[even_pos - 1] = a[even_pos - 1], a[odd_pos - 1]
        
        # 전체 배열이 조건을 만족하는지 검사
        valid = True
        for i in range(1, n + 1):
            if (i % 2 == 1 and a[i-1] % 2 == 0) or (i % 2 == 0 and a[i-1] % 2 == 1):
                valid = False
                break
        
        if valid:
            print(odd_pos, even_pos)
        else:
            print(-1, -1)
    else:
        print(-1, -1)

solve()