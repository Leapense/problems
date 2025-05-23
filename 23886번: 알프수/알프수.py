def check_alpsu(differences):
    # Check if there are any zeros in the differences list
    if any(d == 0 for d in differences):
        return False
    
    # First element must be positive and last element must be negative for a mountain shape
    if differences[0] < 0 or differences[-1] > 0:
        return False
    
    # Check for consecutive same signs and ensure no violations in the pattern
    for i in range(len(differences) - 1):
        if (differences[i] > 0 and differences[i + 1] > 0) or \
           (differences[i] < 0 and differences[i + 1] < 0):
            if differences[i] != differences[i + 1]:
                return False
    
    return True

def main():
    X = input().strip()
    differences = [int(X[i + 1]) - int(X[i]) for i in range(len(X) - 1)]
    
    print("ALPSOO" if check_alpsu(differences) else "NON ALPSOO")

if __name__ == "__main__":
    main()
