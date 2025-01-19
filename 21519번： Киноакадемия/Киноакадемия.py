import sys

def main():
    n = int(sys.stdin.readline())
    total_a = 0
    b_diff = []
    c_diff = []

    for i in range(1, n+1):
        a, b, c = map(int, sys.stdin.readline().split())
        total_a += a
        b_diff.append((b - a, i))
        c_diff.append((c - a, i))

    b_diff_sorted = sorted(b_diff, key=lambda x: -x[0])
    c_diff_sorted = sorted(c_diff, key=lambda x: -x[0])

    max_total = -1
    res_j = res_k = -1

    for b_val, j in b_diff_sorted[:2]:
        for c_val, k in c_diff_sorted[:2]:
            if j != k:
                current = total_a + b_val + c_val
                if current > max_total:
                    max_total = current
                    res_j, res_k = j, k
    print(max_total)
    print(res_j, res_k)

if __name__ == '__main__':
    main()