def possible_child(trait, m_val, f_val):
    if trait == 'D':
        return 1 if (m_val or f_val) else 0
    else:
        return 1 if (m_val and f_val) else 0

def check_pair(dominance, mother, father, child):
    for i, trait in enumerate(dominance):
        m_val = int(mother[i])
        f_val = int(father[i])
        expected = possible_child(trait, m_val, f_val)
        if expected != int(child[i]):
            return False
    return True

import sys
data = sys.stdin.read().strip().splitlines()
dominance = data[0].strip()
i = 1
adults = []
while data[i] != "***":
    parts = data[i].split()
    name = parts[0]
    gender = parts[1]
    traits = parts[2]
    adults.append((name, gender, traits))
    i += 1
i += 1
juveniles = []
while data[i] != "***":
    parts = data[i].split()
    name = parts[0]
    traits = parts[1]
    juveniles.append((name, traits))
    i += 1

females = [(name, traits) for name, gender, traits in adults if gender == 'F']
males = [(name, traits) for name, gender, traits in adults if gender == 'M']

results = []
for jname, jtraits in juveniles:
    valid_pairs = []
    for m_name, m_traits in females:
        for f_name, f_traits in males:
            if check_pair(dominance, m_traits, f_traits, jtraits):
                valid_pairs.append((m_name, f_name))
    valid_pairs.sort(key=lambda x: (x[0], x[1]))
    if valid_pairs:
        pairs_str = " or ".join([f"{m}-{f}" for m, f in valid_pairs])
    else:
        pairs_str = ""
    results.append(f"{jname} by {pairs_str}")
print("\n".join(results))
