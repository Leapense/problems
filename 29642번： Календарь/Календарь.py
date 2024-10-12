import sys

def main():
    sys.setrecursionlimit(1 << 25)
    input = sys.stdin.read
    data = input().split()

    idx = 0
    n = int(data[idx])
    k = int(data[idx + 1])
    idx += 2

    a = list(map(int, data[idx:idx + n]))

    idx += n

    broken_digits = set()

    if k > 0:
        broken_digits = set(data[idx:idx + k])
    idx += k

    max_a = 100000
    bad_numbers = [0] * (max_a + 1)

    for i in range(1, max_a + 1):
        s = str(i)
        for ch in s:
            if ch in broken_digits:
                bad_numbers[i] = 1
                break

    current_sum = [0] * (max_a + 1)
    for i in range(1, max_a + 1):
        current_sum[i] = current_sum[i - 1] + bad_numbers[i]

    total = 0
    for days in a:
        if days <= max_a:
            total += current_sum[days]
        else:
            total += current_sum[max_a]

    print(total)

if __name__ == '__main__':
    main()