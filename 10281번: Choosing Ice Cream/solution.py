import sys
from math import gcd
from typing import Union

def calculate_minimum_throws(n: int, k: int) -> Union[int, str]:
    remaining = n
    throws = 0

    while remaining > 1:
        divisor = gcd(remaining, k)
        if divisor == 1:
            break
        remaining //= divisor
        throws += 1

    if remaining == 1:
        return throws
    return "unbounded"

def main() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    
    try:
        test_count = int(data[0])
    except (ValueError, IndexError):
        return
    
    idx = 1
    output_lines = []

    for _ in range(test_count):
        if idx + 1 >= len(data):
            break
        try:
            n_value = int(data[idx])
            k_value = int(data[idx + 1])
        except ValueError:
            n_value = 0
            k_value = 1

        idx += 2
        result = calculate_minimum_throws(n_value, k_value)
        output_lines.append(str(result))

    sys.stdout.write("\n".join(output_lines))

if __name__ == "__main__":
    main()