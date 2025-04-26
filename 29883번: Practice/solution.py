import sys

data = list(map(int, sys.stdin.buffer.read().split()))
n, m = data[0], data[1]
xs = data[2:2+n]
ys = data[2+n:]
pref = [0]
for x in xs:
    pref.append(pref[-1] + x)
sums = set()
for i in range(n):
    pi = pref[i]
    for j in range(i + 1, n + 1):
        sums.add(pref[j] - pi)

out = []

for y in ys:
    out.append("JAH" if y in sums else "EI")

sys.stdout.write("\n".join(out))
