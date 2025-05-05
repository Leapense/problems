#!/usr/bin/env python3

import sys
import threading

def main():
    input_data = sys.stdin.read().split()
    p = int(input_data[0])
    A = list(map(int, input_data[1:p+1]))
    a, b = map(int, input_data[p+1:p+3])

    if a == b:
        print(0)
        return
    
    ps = [0] * (p + 1)
    for i in range(1, p + 1):
        ps[i] = ps[i - 1] + A[i - 1]

    total_period = ps[p]
    L = b - a
    r = a % p
    ans = 0

    first_len = min(p - r, L)
    if first_len > 0:
        ans += ps[r + first_len] - ps[r]
        L -= first_len

    if L >= p:
        full_cycles = L // p
        ans += full_cycles * total_period
        L -= full_cycles * p

    if L > 0:
        ans += ps[L]
    
    print(ans)

if __name__ == "__main__":
    threading.Thread(target=main).start()