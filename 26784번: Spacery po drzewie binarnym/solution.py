import sys

data = list(map(int, sys.stdin.buffer.read().split()))
q = data[0]
it = iter(data[1:])
out_lines = []
for _ in range(q):
    a = next(it)
    b = next(it)
    da = a.bit_length()
    db = b.bit_length()
    steps = 0
    if da > db:
        diff = da - db
        a >>= diff
        steps += diff
    elif db > da:
        diff = db - da
        b >>= diff
        steps += diff
    while a != b:
        a >>= 1
        b >>= 1
        steps += 2
    out_lines.append(str(steps))
sys.stdout.write("\n".join(out_lines))