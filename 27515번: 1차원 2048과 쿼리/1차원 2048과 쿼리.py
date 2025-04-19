import sys
input = sys.stdin.readline

Q = int(input())
S = 0
ans = []

for _ in range(Q):
    opx = input().strip()
    op = opx[0]
    x = int(opx[1:])
    if op == '+':
        S += x
    else:
        S -= x
    if S:
        ans.append(str(1 << (S.bit_length() - 1)))
    else:
        ans.append('0')

sys.stdout.write('\n'.join(ans))
