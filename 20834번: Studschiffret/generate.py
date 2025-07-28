import random
import string

def generate_one_case(max_n, max_m):
    N = random.randint(1, max_n)
    M = random.randint(1, max_m)
    K = random.randint(1, N * M)
    alphabet = string.ascii_uppercase + string.digits
    cipher = ''.join(random.choice(alphabet) for _ in range(K))
    
    return N, M, cipher

def main():
    T = 10
    MAX_N = 1000
    MAX_M = 1000

    print(T)
    for _ in range(T):
        N, M, cipher = generate_one_case(MAX_N, MAX_M)
        print(f"{N} {M}")
        print(cipher)

if __name__ == "__main__":
    main()