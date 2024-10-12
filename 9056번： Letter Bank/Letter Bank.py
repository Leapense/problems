def is_bank(alpha, beta):
    alpha_set = set(alpha)
    beta_set = set(beta)
    for char in beta:
        if len(beta_set) < len(alpha_set):
            return "NO"
        if char not in alpha_set:
            return "NO"
        
    return "YES"

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    T = int(data[0])
    results = []
    for i in range(1, T + 1):
        alpha, beta = data[i].split()
        results.append(is_bank(alpha, beta))
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
