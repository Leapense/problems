import sys
import math
import io
import pytest

def sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    
    primes = [i for i, val in enumerate(is_prime) if val]
    return primes

def prime_factors(x, primes):
    factors = {}
    temp = x
    for p in primes:
        if p * p > temp:
            break
        if temp % p == 0:
            cnt = 0
            while temp % p == 0:
                cnt += 1
                temp //= p
            factors[p] = cnt
        if temp == 1:
            break
    if temp > 1:
        factors[temp] = 1
    return factors

def solve():
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    n = int(input_data[0])
    a_list = list(map(int, input_data[1:]))

    primes = sieve(31623)

    result = 0
    for a in a_list:
        factors = prime_factors(a, primes)
        exponents = list(factors.values())
        d = exponents[0]
        for exp in exponents[1:]:
            d = math.gcd(d, exp)
        min_value = 1
        for p, exp in factors.items():
            min_value *= p ** (exp // d)
        result += min_value
    sys.stdout.write(str(result))

def run_io_fun(input_data: str) -> str:
    backup_stdin = sys.stdin
    backup_stdout = sys.stdout
    try:
        sys.stdin = io.StringIO(input_data)
        out = io.StringIO()
        sys.stdout = out
        solve()
        return out.getvalue().strip()
    finally:
        sys.stdin = backup_stdin
        sys.stdout = backup_stdout

# 여러 샘플 테스트 케이스를 생성하여 결과 내역을 상세히 표시하도록 한다.
@pytest.mark.parametrize("test_input,expected_output", [
    # Sample Test Case 1
    ("5\n2 3 4 5 6\n", "18"),
    # 단일 원소: 2 -> 소인수분해 {2:1} -> 최소값 2
    ("1\n2\n", "2"),
    # 두 개의 원소: 4 (2^2, gcd=2, 최소값 2), 8 (2^3, gcd=3, 최소값 2) => 합: 4
    ("2\n4 8\n", "4"),
    # 16: 16=2^4, gcd=4, 최소값 2; 27: 27=3^3, gcd=3, 최소값 3 => 합: 5
    ("2\n16 27\n", "5"),
    # 추가 테스트: 소수가 주어지는 경우 (소인수분해 {p:1} 이므로 자기 자신)
    ("3\n7 11 13\n", "31"),  # 7+11+13=31
])

def test_solve(test_input, expected_output):
    result = run_io_fun(test_input)
    print("입력:", test_input.strip())
    print("예상 출력:", expected_output)
    print("실제 출력:", result)
    assert result == expected_output

if __name__ == "__main__":
    pytest.main([__file__])
    