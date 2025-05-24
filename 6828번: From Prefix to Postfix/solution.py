import sys
from typing import List

_OPERATORS: set[str] = {"+", "-"}

def _is_operator(token: str) -> bool:
    return token in _OPERATORS

def _prefix_to_postfix(tokens: List[str]) -> str:
    stack: List[str] = []

    for token in reversed(tokens):
        if _is_operator(token):
            left: str = stack.pop()
            right: str = stack.pop()
            stack.append(f"{left} {right} {token}")
        else:
            stack.append(token)
        
    return stack[0]

def main() -> None:
    for raw_line in sys.stdin:
        line: str = raw_line.strip()
        if line == "0":
            break
        if not line:
            continue
        tokens: List[str] = line.split()
        print(_prefix_to_postfix(tokens))

if __name__ == "__main__":
    main()