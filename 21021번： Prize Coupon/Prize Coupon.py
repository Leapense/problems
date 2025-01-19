import sys

def main():
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])
    C = list(map(int, data[1:N+1]))
    covered = [False] * N

    for i in range(N - 1, -1, -1):
        if not covered[i]:
            if i < N - 1 and C[i + 1] > 0:
                C[i + 1] -= 1
                covered[i] = True
            elif C[i] > 0:
                C[i] -= 1
                covered[i] = True
            elif i > 0 and C[i - 1] > 0:
                C[i - 1] -= 1
                covered[i] = True
    print(sum(covered))

if __name__ == '__main__':
    main()