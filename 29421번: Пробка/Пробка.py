def main():
    import sys
    
    n, g, r = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))

    cycle = g + r
    current_time = 0

    for ai in a:
        phase = current_time % cycle
        if phase + ai <= g:
            depart_time = current_time + ai
        else:
            depart_time = current_time + (cycle - phase) + ai
        current_time = depart_time

    print(current_time)
    
if __name__ == "__main__":
    main()