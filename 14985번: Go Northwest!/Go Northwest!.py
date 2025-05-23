import sys

def count_pairs(sorted_list):
    total = 0
    current = None
    count = 0

    for x in sorted_list:
        if x == current:
            count += 1
        else:
            if count >= 2:
                total += count * (count - 1) // 2
            current = x
            count = 1
    if count >= 2:
        total += count * (count - 1) // 2
    return total

def main():
    data = sys.stdin.read().split()
    it = iter(data)
    try:
        while True:
            N = int(next(it))
            y_minus_x = []
            y_plus_x = []
            for _ in range(N):
                x = int(next(it))
                y = int(next(it))
                y_minus_x.append(y - x)
                y_plus_x.append(y + x)
            y_minus_x.sort()
            y_plus_x.sort()
            pairs_slope1 = count_pairs(y_minus_x)
            pairs_slope2 = count_pairs(y_plus_x)
            K = pairs_slope1 + pairs_slope2
            if N == 0:
                P = 0.0
            else:
                P = (2 * K) / (N * N)
            formatted_P = '%.6f' % P
            if '.' in formatted_P:
                formatted_P = formatted_P.rstrip('0').rstrip('.')
            print(formatted_P)
    except StopIteration:
        pass

main()