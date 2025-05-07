#!/usr/bin/env python3
import sys

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    s = int(data[0], 2)
    d = int(data[1], 2)
    m = int(data[2], 2)

    death1 = m.bit_length()
    if d > death1:
        print(bin(death1)[2:])
        return
    
    M1 = (m >> d) + s
    if M1.bit_length() > d:
        print("Infinite money!")
        return 

    death2 = d + M1.bit_length()
    print(bin(death2)[2:])

if __name__ == "__main__":
    main()