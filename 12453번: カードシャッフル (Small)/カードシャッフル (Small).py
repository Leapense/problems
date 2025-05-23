def main():
    import sys
    input_data = sys.stdin.read().split()
    t = int(input_data[0])
    index = 1
    results = []
    for case in range(1, t + 1):
        M = int(input_data[index]); C = int(input_data[index + 1]); W = int(input_data[index + 2])
        index += 3
        ops = []
        for _ in range(C):
            A = int(input_data[index]); B = int(input_data[index + 1])
            index += 2
            ops.append((A, B))
        pos = W
        for A, B in reversed(ops):
            if pos <= B:
                pos = A + pos - 1
            elif pos <= B + (A - 1):
                pos = pos - B
        results.append(f"Case #{case}: {pos}")
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    main()