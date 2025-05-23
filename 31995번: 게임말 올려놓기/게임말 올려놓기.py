def main():
    N = int(input())
    M = int(input())

    if N == 1 or M == 1:
        print(0)
        return
    
    result = 2 * (N - 1) * (M - 1)
    print(result)

if __name__ == '__main__':
    main()