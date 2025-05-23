import sys, bisect

def main():
    data = sys.stdin.read().split()
    it = iter(data)
    N = int(next(it))
    Q = int(next(it))
    haybales = sorted(int(next(it)) for _ in range(N))
    output = []
    for _ in range(Q):
        A = int(next(it))
        B = int(next(it))
        left = bisect.bisect_left(haybales, A)
        right = bisect.bisect_right(haybales, B)
        output.append(str(right - left))
    print('\n'.join(output))

if __name__ == '__main__':
    main()