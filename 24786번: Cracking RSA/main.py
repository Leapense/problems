def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def extended_gcd(a, b):
    if b == 0:
        return (a, 1, 0)
    else:
        g, x1, y1 = extended_gcd(b, a % b)
        return (g, y1, x1 - (a // b) * y1)
    
def mod_inverse(e, phi):
    g, x, y = extended_gcd(e, phi)
    if g != 1:
        raise Exception('Modular inverse does not exist')
    else:
        return x % phi
    
def factorize(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return i, n // i
    return None

def solve_rsa():
    import sys
    input_data = sys.stdin.read().split()
    t = int(input_data[0])
    results = []
    index = 1
    for _ in range(t):
        n = int(input_data[index])
        e = int(input_data[index + 1])
        index += 2

        p, q = factorize(n)
        phi = (p - 1) * (q - 1)
        d = mod_inverse(e, phi)
        results.append(str(d))
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    solve_rsa()