import sys

MAX_WEIGHT = 20000

def find_balance_point(m, weights):
    if not weights:
        return 1
    
    freq = [0] * (MAX_WEIGHT + 1)

    for w in weights:
        if 0 < w <= MAX_WEIGHT:
            freq[w] += 1

    total = sum(w * freq[w] for w in range(MAX_WEIGHT + 1))
    prefix_weighted_sum = 0

    for t in range(1, MAX_WEIGHT + 2):
        current_t_weight_contribution = 0
        if t <= MAX_WEIGHT:
            current_t_weight_contribution = t * freq[t]

        if 2 * prefix_weighted_sum + current_t_weight_contribution == total:
            return t
        
        if t <= MAX_WEIGHT:
            prefix_weighted_sum += t * freq[t]

    return None

def main():
    try:
        input_data = sys.stdin.read().split()
        if not input_data:
            return
        m = int(input_data[0])
        weights = list(map(int, input_data[1:]))
    except (ValueError, IndexError):
        sys.stderr.write("Invalid input format.\n")
        return
    
    result = find_balance_point(m, weights)
    if result is not None:
        sys.stdout.write(str(result))

if __name__ == "__main__":
    main()