def sum_of_digits(num: int) -> int:
    """
    주어진 수의 자리수의 합을 구하는 함수
    """
    return sum(int(d) for d in str(num))

def find_smallest_constructor(n: int) -> int:
    """
    주어진 n의 분해합들 중 가장 작은 분해합 구성을 찾는 함수
    """
    max_digit_sum = 9 * len(str(n))
    start = max(1, n - max_digit_sum)

    for m in range(start, n):
        if m + sum_of_digits(m) == n:
            return m
    return 0

def main():
    """
    Main 함수
    """
    n = int(input().strip())
    result = find_smallest_constructor(n)
    print(result)

if __name__ == "__main__":
    main()