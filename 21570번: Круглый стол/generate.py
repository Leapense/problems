import random

def generate_specific_test_cases():
    test_categories = [
        ("최소 조건 충족 (m + n = 3)", generate_min_sum_case),
        ("m과 n이 같을 때 (m == n)", generate_m_equals_n_case),
        ("n이 0일 때 (m > n, n == 0)", generate_n_is_zero_case),
        ("m이 0일 때 (m <= n)", generate_m_is_zero_case),
        ("m > n 이며, 나머지가 0일 때 (m % n == 0)", generate_m_gt_n_rem_zero_case),
        ("m > n 이며, 나머지가 0이 아닐 때 (m % n != 0)", generate_m_gt_n_rem_not_zero_case),
        ("n이 m의 정확히 두 배일 때 (n == 2 * m)", generate_n_equals_2m_case),
        ("n이 m의 두 배보다 클 때 (n > 2 * m)", generate_n_gt_2m_case),
        ("m과 2m 사이에 n이 있을 때 (m < n < 2 * m)", generate_n_between_m_and_2m_case),
        ("최대값 경계 (m 또는 n이 1000)", generate_max_values_case),
        ("일반적인 무작위 케이스", generate_random_case)
    ]

    print("C 코드 로직 검증을 위한 경계값 테스트 케이스")
    print("=" * 45)

    for description, generate_func in test_categories:
        m, n = generate_func()
        print(f"--- {description} ---")
        print(f"{m} {n}\n")

def generate_min_sum_case():
    return random.choice([(3, 0), (0, 3), (2, 1), (1, 2)])

def generate_m_equals_n_case():
    m = random.randint(2, 1000)
    return m, m

def generate_n_is_zero_case():
    m = random.randint(3, 1000)
    return m, 0

def generate_m_is_zero_case():
    n = random.randint(3, 1000)
    return 0, n

def generate_m_gt_n_rem_zero_case():
    n = random.randint(1, 499)
    k = random.randint(2, 1000 // n)
    m = k * n
    return m, n

def generate_m_gt_n_rem_not_zero_case():
    n = random.randint(2, 499)
    k = random.randint(2, 1000 // n)
    m = k * n + 1
    if m > 1000:
        m -= 2
    return m, n

def generate_n_equals_2m_case():
    m = random.randint(1, 500)
    n = 2 * m
    return m, n

def generate_n_gt_2m_case():
    m = random.randint(1, 499)
    n = random.randint(2 * m + 1, 1000)
    return m, n

def generate_n_between_m_and_2m_case():
    m = random.randint(2, 998)
    if 2 * m - 1 <= m + 1:
        m = 5
    n = random.randint(m + 1, 2 * m - 1)
    return m, n

def generate_max_values_case():
    if random.choice([True, False]):
        return 1000, random.randint(0, 1000)
    else:
        return random.randint(0, 1000), 1000

def generate_random_case():
    while True:
        m = random.randint(0, 1000)
        n = random.randint(0, 1000)
        if m + n >= 3:
            return m, n

if __name__ == "__main__":
    generate_specific_test_cases()