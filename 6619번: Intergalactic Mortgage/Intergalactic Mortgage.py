import sys
import math

def main():
    input = sys.stdin.read().splitlines()
    for line in input:
        if not line.strip():
            continue
        X, Y, N, r = map(float, line.split())
        X, Y, N = int(X), int(Y), int(N)
        if X == 0 and Y == 0 and N == 0 and r == 0.0:
            break
        
        mr = r / 100 / 12  # Monthly interest rate
        can_pay = True
        
        if X * mr >= Y:
            # Monthly payment is less or equal to interest-only payment
            can_pay = False
        elif r < 0.001:
            # Zero or nearly zero interest rate
            if Y * N * 12 < X:
                can_pay = False
        else:
            # Calculate balance using compound interest and payments
            balance = (X - Y / mr) * pow(1 + mr, N * 12) + Y / mr
            if balance > 0:
                can_pay = False
        
        if can_pay:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()
