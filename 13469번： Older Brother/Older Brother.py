import math

def is_prime_power(q):
    if q == 1:
        return False
    def smallest_prime_factor(n):
        if n % 2 == 0:
            return 2
        sqrt_n = int(math.isqrt(n)) + 1
        for i in range(3, sqrt_n, 2):
            if n % i == 0:
                return i
        return n
    
    p = smallest_prime_factor(q)
    while q % p == 0:
        q = q // p

    return q == 1

def main():
    import sys
    input = sys.stdin.read
    q_str = input().strip()
    if not q_str:
        print("no")
        return
    q = int(q_str)
    if is_prime_power(q):
        print("yes")
    else:
        print("no")
if __name__ == '__main__':
    main()