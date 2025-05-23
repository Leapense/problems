def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    mode = int(data[0])
    n, a, b, c = map(int, data[1:])
    
    if mode == 1:
        # Minimal count of actors who can fit the role
        min_count = max(0, a + b + c - 2 * n)
        print(min_count)
    elif mode == 2:
        # Maximal count of actors who can fit the role
        max_count = min(a, b, c)
        print(max_count)
    else:
        print("Invalid mode")

if __name__ == "__main__":
    main()
