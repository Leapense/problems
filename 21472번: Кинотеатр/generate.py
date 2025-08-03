import random

def generate_test_case(num_cases=10):
    MIN_VAL = 1
    MAX_VAL = 10**9

    case_types = ['boundary', 'specific_branch', 'gcd_special', 'general_random']
    weights = [0.15, 0.20, 0.25, 0.40]

    for i in range(num_cases):
        chosen_type = random.choices(case_types, weights)[0]
        n, m = 0, 0

        if chosen_type == 'boundary':
            sub_type = random.choice(['min_min', 'max_max', 'min_max', 'min_random'])
            if sub_type == 'min_min':
                n, m = MIN_VAL, MIN_VAL
            elif sub_type == 'max_max':
                n, m = MAX_VAL, MAX_VAL
            elif sub_type == 'min_max':
                if random.random() < 0.5:
                    n, m = MIN_VAL, MAX_VAL
                else:
                    n, m = MAX_VAL, MIN_VAL
            elif sub_type == 'min_random':
                if random.random() < 0.5:
                    n, m = MIN_VAL, random.randint(MIN_VAL + 1, MAX_VAL)
                else:
                    n, m = random.randint(MIN_VAL + 1, MAX_VAL), MIN_VAL
        elif chosen_type == 'specific_branch':
            sub_type = random.choice(['n_is_1', 'm_is_1', 'n_is_2', 'm_is_2'])
            if sub_type == 'n_is_1':
                n, m = 1, random.randint(MIN_VAL, MAX_VAL)
            elif sub_type == 'm_is_1':
                n, m = random.randint(MIN_VAL, MAX_VAL), 1
            elif sub_type == 'n_is_2':
                n, m = 2, random.randint(MIN_VAL + 1, MAX_VAL)
            elif sub_type == 'm_is_2':
                n, m = random.randint(MIN_VAL + 1, MAX_VAL), 2

        elif chosen_type == 'gcd_special':
            sub_type = random.choice(['coprime', 'multiple', 'equal'])
            if sub_type == 'coprime':
                k = random.randint(2, MAX_VAL // 2)
                n, m = 2 * k, 2 * k + 2
            elif sub_type == 'multiple':
                a = random.randint(2, 10000)
                k = random.randint(2, 100)
                b = a * k
                n, m = a + 1, b + 1
            elif sub_type == 'equal':
                val = random.randint(MIN_VAL + 1, MAX_VAL)
                n, m = val, val

        else:
            n = random.randint(MIN_VAL, MAX_VAL)
            m = random.randint(MIN_VAL, MAX_VAL)
            while n == 1 or m == 1:
                n = random.randint(MIN_VAL, MAX_VAL)
                m = random.randint(MIN_VAL, MAX_VAL)
        print(n, m)

if __name__ == "__main__":
    generate_test_case(20)