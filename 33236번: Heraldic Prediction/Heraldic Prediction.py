def main():
    import sys
    input = sys.stdin.readline
    n = int(input().strip())
    for m in range(n + 1, n + 50):
        if m % 2 == 0 and m % 30 == 26:
            print(m)
            return
        
if __name__ == "__main__":
    main()