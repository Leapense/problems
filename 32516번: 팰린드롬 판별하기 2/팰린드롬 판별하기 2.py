import sys
def main():
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])
    T = data[1]

    P = 0; Q = 0; K = 0

    for i in range(N // 2):
        c1 = T[i]
        c2 = T[N - i - 1]
        if c1 != '?' and c2 != '?':
            if c1 != c2:
                print(0)
                return
        elif c1 != '?' or c2 != '?':
            P += 1
        else:
            Q += 1
    
    K = P + 26 * Q
    print(K)

if __name__ == '__main__':
    main()