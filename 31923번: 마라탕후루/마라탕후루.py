def main():
    N, P, Q = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    answer = []

    for i in range(N):
        a = A[i]
        b = B[i]
        j = 0

        while a != b:
            a += P
            b += Q
            j += 1

            if j == 10000:
                print("NO")
                return

        answer.append(j)

    print("YES")
    print(" ".join(map(str, answer)))

if __name__ == "__main__":
    main()
