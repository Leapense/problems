def solve():
    try:
        line = input()
        if not line: return None
        parts = list(map(int, line.split()))
    except (EOFError, ValueError):
        return None
    
    N, R, O, Y, G, B, V = parts
    counts = {'R': R, 'Y': Y, 'B': B}
    for color in counts:
        if counts[color] > N / 2:
            return "IMPOSSIBLE"
        
    result = []
    last_char = max(counts, key=counts.get)
    result.append(last_char)
    counts[last_char] -= 1

    for _ in range(N - 1):
        best_next_char = ''
        max_count = -1

        for color in sorted(counts.keys()):
            if color != last_char and counts[color] > max_count:
                max_count = counts[color]
                best_next_char = color

        result.append(best_next_char)
        counts[best_next_char] -= 1
        last_char = best_next_char

    if result[0] == result[-1]:
        pass

    return "".join(result)

def main():
    try:
        T_str = input()
        if not T_str: return
        T = int(T_str)
        for i in range(1, T + 1):
            solution = solve()
            if solution is not None:
                print(f"Case #{i}: {solution}")
    except (EOFError, ValueError):
        return
    
if __name__ == "__main__":
    main()