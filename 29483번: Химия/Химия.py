def calculate_molecular_mass(formula):
    # Atomic masses based on the problem statement
    atomic_mass = {
        'H': 1,
        'C': 12,
        'N': 14,
        'O': 16
    }
    
    total_mass = 0
    i = 0
    n = len(formula)
    
    while i < n:
        element = formula[i]
        mass = atomic_mass[element]
        i += 1
        
        # Check if next character is a digit
        if i < n and formula[i].isdigit():
            multiplier = 0
            while i < n and formula[i].isdigit():
                multiplier = multiplier * 10 + int(formula[i])
                i += 1
            total_mass += mass * multiplier
        else:
            total_mass += mass
    
    return total_mass

formula = input()
print(calculate_molecular_mass(formula))