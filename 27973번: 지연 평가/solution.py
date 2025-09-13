import sys

def solve():
    it = iter(sys.stdin.buffer.read().split())
    Q = int(next(it))
    N = 1234567890123
    L = 1
    a = 1
    b = 0

    out_lines = []
    for _ in range(Q):
        op = next(it).decode()
        if op == '0':
            x = int(next(it))
            b += x
        elif op == '1':
            x = int(next(it))
            a *= x
            b *= x
        elif op == '2':
            n = int(next(it))
            L += n
        elif op == '3':
            out_lines.append(str(a * L + b))
        else:
            pass
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()