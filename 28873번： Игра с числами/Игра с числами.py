import sys
import math
input_data = sys.stdin.read().split()
a = int(input_data[0])
b = int(input_data[1])
T = (1 << 60) - 1
if b <= 0:
    print(-1)
else:
    if a == 0:
        k = (T + b - 1) // b
        print(k)
    else:
        k0 = (T + b - 1) // b
        k1 = (((1 << 60) + 1) + (-a) - 1) // (-a)
        print(min(k0, k1))