def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def phi(n):
    result = n
    p = 2
    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n //= p
            result -= result // p
        p += 1
    if n > 1:
        result -= result // n
    return result

# 입력
N = int(input())

# 출력
print(phi(N))