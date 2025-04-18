import sys

def sum_digits(n : int) -> int:
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s

def main():
    data = sys.stdin.buffer.read().split()
    q = int(data[0])
    queries = list(map(int, data[1:]))
    mx = max(queries)
    reachable = set()
    x = 1

    while x <= mx:
        reachable.add(x)
        x += sum_digits(x) ** 2
    out = []
    for v in queries:
        out.append(b'TAK' if v in reachable else b'NIE')
    sys.stdout.buffer.write(b'\n'.join(out) + b'\n')

if __name__ == '__main__':
    main()
