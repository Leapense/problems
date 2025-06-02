import sys
from typing import List

def compute_longest_value_sequence(weights: List[float], clarities: List[float]) -> int:
    n = len(weights)
    if n == 0:
        return 0
    
    dp_length: List[int] = [1] * n
    max_length: int = 1

    for i in range(n):
        current_weight = weights[i]
        current_clarity = clarities[i]

        for j in range(i):
            if current_weight > weights[j] and current_clarity < clarities[j]:
                candidate_length = dp_length[j] + 1
                if candidate_length > dp_length[i]:
                    dp_length[i] = candidate_length

        if dp_length[i] > max_length:
            max_length = dp_length[i]

    return max_length

def main() -> None:
    input_data = sys.stdin
    first_line = input_data.readline()

    if not first_line:
        return
    
    try:
        test_count = int(first_line.strip())
    except ValueError:
        return
    
    for _ in range(test_count):
        line = input_data.readline().strip()
        while line == "":
            line = input_data.readline().strip()

        try:
            n = int(line)
        except ValueError:
            continue

        weights: List[float] = []
        clarities: List[float] = []

        for _ in range(n):
            data_line = input_data.readline().split()
            weight_value = float(data_line[0])
            clarity_value = float(data_line[1])

            weights.append(weight_value)
            clarities.append(clarity_value)

        result = compute_longest_value_sequence(weights, clarities)
        print(result)

if __name__ == "__main__":
    main()