import re
from collections import defaultdict

def parse_molecule(molecule):
    """분자식을 파싱하여 원자와 개수를 반환"""
    atom_counts = defaultdict(int)
    matches = re.finditer(r"(\d*)([A-Z][a-z]*)(\d*)", molecule)
    for match in matches:
        coeff = int(match.group(1)) if match.group(1) else 1
        atom = match.group(2)
        count = int(match.group(3)) if match.group(3) else 1
        atom_counts[atom] += coeff * count
    return atom_counts

def is_balanced(equation):
    """반응식이 균형이 맞는지 확인"""
    if "->" not in equation:
        return False  # 잘못된 형식
    try:
        left, right = equation.split("->")
    except ValueError:
        return False  # 형식이 올바르지 않음
    
    left_molecules = left.split("+")
    right_molecules = right.split("+")
    
    left_counts = defaultdict(int)
    right_counts = defaultdict(int)
    
    # 왼쪽 원자 개수 계산
    for molecule in left_molecules:
        molecule_counts = parse_molecule(molecule)
        for atom, count in molecule_counts.items():
            left_counts[atom] += count
    
    # 오른쪽 원자 개수 계산
    for molecule in right_molecules:
        molecule_counts = parse_molecule(molecule)
        for atom, count in molecule_counts.items():
            right_counts[atom] += count
    
    return left_counts == right_counts

def main():
    n = int(input().strip())  # 반응식 개수 입력
    results = []
    for _ in range(n):
        equation = input().strip()
        if is_balanced(equation):
            results.append("DA")
        else:
            results.append("NE")
    print("\n".join(results))

if __name__ == "__main__":
    main()
