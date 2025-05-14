import sys

MAX_K_VAL = 1299709
is_prime_global = [True] * (MAX_K_VAL + 1)

def sieve_precomputation():
    """
    에라토스테네스의 체를 사용하여 MAX_K_VAL까지의 소수를 미리 계산합니다.
    is_prime_global 리스트를 수정합니다.
    """
    global is_prime_global

    is_prime_global[0] = is_prime_global[1] = False

    for i in range(2, int(MAX_K_VAL ** 0.5) + 1):
        if is_prime_global[i]:
            for multiple in range(i * i, MAX_K_VAL + 1, i):
                is_prime_global[multiple] = False

sieve_precomputation()

def get_sequence_length(k_val: int) -> int:
    """
    주어진 k_val에 대해 소수 사이 수열의 길이를 계산합니다.
    k_val이 소수이거나 1이면 0을 반환합니다.
    """
    global is_prime_global
    
    if k_val == 1:
        return 0
    
    if is_prime_global[k_val]:
        return 0
    
    p = k_val - 1
    while p >= 2 and not is_prime_global[p]:
        p -= 1
    
    q = k_val + 1
    while q <= MAX_K_VAL and not is_prime_global[q]:
        q += 1

    return q - p

def main():
    """
    메인 실행 함수: 테스트 케이스를 읽고 각 결과를 출력합니다.
    """
    num_test_cases = int(sys.stdin.readline())
    results = []
    for _ in range(num_test_cases):
        k = int(sys.stdin.readline())
        results.append(str(get_sequence_length(k)))
    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    main()