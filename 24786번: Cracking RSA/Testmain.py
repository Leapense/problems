import sys
import io
import pytest

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
    g, x, _ = extended_gcd(e, phi)
    if g != 1:
        raise Exception('Modular inverse does not exist')
    else:
        return x % phi
    
def factorize(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return i, n // i
    return None

def solve_rsa():
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

def run_test(input_str):
    original_stdin = sys.stdin
    original_stdout = sys.stdout
    sys.stdin = io.StringIO(input_str)
    out = io.StringIO()
    sys.stdout = out
    solve_rsa()
    sys.stdin = original_stdin
    sys.stdout = original_stdout
    return out.getvalue()

def test_sample_input1():
    input_str = "2\n33 3\n65 11\n"
    expected_output = "7\n35"
    output = run_test(input_str)
    assert output.strip() == expected_output

def test_single_case():
    input_str = "1\n33 7\n"
    expected_output = "3"
    output = run_test(input_str)
    assert output.strip() == expected_output

def test_additional_case():
    input_str = "1\n 187 7\n"
    expected_output = "23"
    output = run_test(input_str)
    assert output.strip() == expected_output

if __name__ == "__main__":
    pytest.main()