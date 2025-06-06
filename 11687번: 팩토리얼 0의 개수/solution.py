import sys

def count_trailing_zeros(n: int) -> int:
    """
    주어진 n에 대해 n!의 끝자리 0의 개수를 계산한다.
    계산 방식: n을 5, 25, 125, ... 로 나누어 몫을 더한다.
    """
    total = 0
    divisor = 5

    while divisor <= n:
        total += n // divisor
        divisor *= 5

    return total

def find_smallest_n_for_zero_count(m: int) -> int:
    """
    f(N) = trailing_zeros(N!) 함수가 정확히 m이 되는 가장 작은 N을 이진 탐색으로 찾는다.
    만약 그런 N이 존재하지 않으면 -1을 반환한다.
    """
    left = 0
    right = 5 * m
    answer = -1

    while left <= right:
        mid = (left + right) // 2
        zero_count = count_trailing_zeros(mid)

        if zero_count < m:
            left = mid + 1
        else:
            right = mid - 1

    if count_trailing_zeros(left) == m:
        answer = left

    return answer

def main():
    data = sys.stdin.readline().strip()
    if not data:
        return
    
    m = int(data)
    result = find_smallest_n_for_zero_count(m)
    print(result)

if __name__ == "__main__":
    main()