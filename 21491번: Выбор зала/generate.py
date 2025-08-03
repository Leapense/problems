import random

def generate_test_case():
    case_types = ['small', 'normal', 'large']
    weights = [0.15, 0.25, 0.6]
    chosen_type = random.choices(case_types, weights)[0]
    if chosen_type == 'small':
        AB_MIN = 1
        AB_MAX = 100
        CD_MIN = 4
        CD_MAX = 100
    elif chosen_type == 'normal':
        AB_MIN = 1
        AB_MAX = 10**6
        CD_MIN = 4
        CD_MAX = 10**6
    elif chosen_type == 'large':
        AB_MIN = 1
        AB_MAX = 10**9
        CD_MIN = 4
        CD_MAX = 10**9
    
    A = random.randint(AB_MIN, AB_MAX)
    B = random.randint(A, AB_MAX)
    C = random.randint(CD_MIN, CD_MAX)
    D = random.randint(C, CD_MAX)

    print(A, B, C, D)

if __name__ == "__main__":
    generate_test_case()