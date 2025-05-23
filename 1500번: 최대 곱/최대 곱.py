#!/usr/bin/env python3
import sys

def main():
    input_line = sys.stdin.read().strip().split()
    if not input_line:
        return
    
    S, K = map(int, input_line)

    x, r = divmod(S, K)

    product = (x ** (K - r)) * ((x + 1) ** r)
    print(product)

if __name__ == "__main__":
    main()