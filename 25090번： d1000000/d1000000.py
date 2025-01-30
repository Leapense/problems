def main():
    import sys
    input = sys.stdin.read().split()
    idx = 0
    T = int(input[idx])
    idx += 1
    for case in range(1, T + 1):
        N = int(input[idx])
        idx += 1
        S = list(map(int, input[idx:idx + N]))
        idx += N
        S.sort()
        current = 0
        for s in S:
            if s >= current + 1:
                current += 1
        print(f"Case #{case}: {current}")

if __name__ == "__main__":
    main()