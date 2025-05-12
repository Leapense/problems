import sys

MASS = {"H": 1, "C": 12, "O": 16}

def molecular_mass(formula: str) -> int:
    stack: list[int | str] = []
    for ch in formula.strip():
        if ch in MASS:
            stack.append(MASS[ch])
        elif ch == '(':
            stack.append('(')
        elif ch == ')':
            group_mass = 0
            while stack and stack[-1] != '(':
                group_mass += stack.pop()
            if not stack:
                raise ValueError("Invalid formula - unmatched ')'")
            stack.pop()
            stack.append(group_mass)
        else:
            multiplier = int(ch)
            if not stack or stack[-1] == '(':
                raise ValueError("Digit without a preceding atom or group")
            last_mass = stack.pop()
            stack.append(last_mass * multiplier)
            
    total = sum(x for x in stack if isinstance(x, int))
    return total

def main() -> None:
    formula = sys.stdin.readline()
    print(molecular_mass(formula))

if __name__ == "__main__":
    main()