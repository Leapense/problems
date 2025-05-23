def find_prime_factors(x):
    factors = set()
    d = 2
    while d * d <= x:
        while (x % d) == 0:
            factors.add(d)
            x //= d
        d += 1
    if x > 1:
        factors.add(x)
    return factors

def find_unlike_numbers(x, l, r):
    prime_factors = find_prime_factors(x)
    unlike_numbers = []
    
    for y in range(l, r + 1):
        if all(y % p != 0 for p in prime_factors):
            unlike_numbers.append(y)
    
    return unlike_numbers

x = int(input())
l = int(input())
r = int(input())

unlike_numbers = find_unlike_numbers(x, l, r)
print(len(unlike_numbers))
print(*unlike_numbers)