import sys
import math

def main() -> None:
    k = int(sys.stdin.readline().strip())
    if k == 0:
        print(0)
        return
    abs_k = abs(k)
    limit = math.isqrt(abs_k)
    answer = None
    for d in range(1, limit + 1):
        if abs_k % d != 0:
            continue
        for a in (d, -d):
            if k % a != 0:
                continue
            b = k // a
            if (a + b) & 1:
                continue
            x = (a + b) // 2
            n = (b - a) // 2
            if x < 0 or n < 0:
                continue
            if answer is None or x < answer:
                answer = x
    print(answer if answer is not None else 'none')

if __name__ == '__main__':
    main()