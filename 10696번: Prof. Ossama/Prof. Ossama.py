def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split('\n')

    T = int(data[0])
    results = []

    for i in range(1, T + 1):
        N, X = data[i].split()
        N = int(N)
        X = int(X)

        R = N % X
        results.append(f"Case {i}: {R}")

    for result in results:
        print(result)

if __name__ == "__main__":
    main()