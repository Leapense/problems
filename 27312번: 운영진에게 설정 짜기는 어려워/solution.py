import sys

def main():
    line = sys.stdin.readline().strip()
    if not line:
        return
    M, N, Q = map(int, line.split())

    a = list(map(int, sys.stdin.readline().split()))
    assert len(a) == N
    p = [1] * N
    for k in range(1, M + 1):
        i = k
        print(f"? {k} {i}")
        sys.stdout.flush()

        ans_line = sys.stdin.readline().strip()
        while ans_line == "":
            ans_line = sys.stdin.readline().strip()
        v = int(ans_line)

        if v == 1:
            p[i - 1] = 2
        else:
            p[i - 1] = 1

    print("!", *p)
    sys.stdout.flush()

if __name__ == "__main__":
    main()