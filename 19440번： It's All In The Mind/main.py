from math import gcd

def solve_case(n, m, known):
    a = [-1] * n

    for pos, val in known:
        a[pos - 1] = val
    
    for i in range(n):
        if a[i] == -1:
            if i == 0:
                a[i] = 100
            else:
                a[i] = a[i - 1]
        elif i > 0 and a[i] > a[i - 1]:
            a[i - 1] = a[i]

    numerator = a[0] + a[1]
    denominator = sum(a)

    divisor = gcd(numerator, denominator)
    return f"{numerator // divisor}/{denominator // divisor}"

def main():
    T = int(input())
    for _ in range(T):
        n, m = map(int, input().split())
        known = [tuple(map(int, input().split())) for _ in range(m)]

        print(solve_case(n, m, known))

if __name__ == "__main__":
    main()