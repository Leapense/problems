import sys

def main():
    T, *rest = sys.stdin.read().split()
    T = int(T)
    for i in range(T):
        N = int(rest[i])
        result = 0
        power_of_three = 1
        while N > 0:
            if N % 2 == 1:
                result += power_of_three
            power_of_three *= 3
            N //= 2
        print(result)

if __name__ == "__main__":
    main()