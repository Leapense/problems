import sys
input = sys.stdin.readline

b = list(map(int, input().split()))

max_fee = 0

for a1 in range(16):
    for a2 in range(8):
        for a3 in range(6):
            for a4 in range(4):
                for a5 in range(4):
                    cnt = a1 + a2 + a3 + a4 + a5
                    diff = a1 * 1 + a2 * 2 + a3 * 3 + a4 * 4 + a5 * 5
                    if cnt == 0:
                        fee = 0
                    else:
                        if cnt <= 3 and diff > 10:
                            continue
                        if cnt >= 4 and diff > 15:
                            continue

                        fee = a1 * b[0] + a2 * b[1] + a3 * b[2] + a4 * b[3] + a5 * b[4]
                    if fee > max_fee:
                        max_fee = fee
sys.stdout.write(str(max_fee))