def parse_input(input_str):
    lines = input_str.strip().split('\n')
    N, R = map(int, lines[0].split())
    arrays = {}
    idx = 1
    for _ in range(N):
        parts = lines[idx].split()
        name = parts[0]
        B = int(parts[1])
        S = int(parts[2])
        D = int(parts[3])
        bounds = []
        for i in range(D):
            L = int(parts[4 + 2*i])
            U = int(parts[5 + 2*i])
            bounds.append((L, U))
        arrays[name] = {
            'B': B,
            'S': S,
            'D': D,
            'bounds': bounds
        }
        idx += 1
    queries = []
    for _ in range(R):
        parts = lines[idx].split()
        name = parts[0]
        indexes = list(map(int, parts[1:]))
        queries.append((name, indexes))
        idx += 1
    return arrays, queries

def compute_Cs(array):
    D = array['D']
    S = array['S']
    bounds = array['bounds']
    Cs = [0] * (D + 1)
    Cs[D] = S
    for d in range(D-1, 0, -1):
        L, U = bounds[d]
        Cs[d] = Cs[d+1] * (U - L + 1)
    # C0 calculation
    C0 = array['B']
    for d in range(1, D+1):
        L = bounds[d-1][0]
        C0 -= Cs[d] * L
    Cs[0] = C0
    return Cs

def format_output(name, indexes, address):
    idx_str = ', '.join(str(x) for x in indexes)
    return f"{name}[{idx_str}] = {address}"

def main():
    import sys
    input_str = sys.stdin.read()
    arrays, queries = parse_input(input_str)
    C_dict = {}
    for name, array in arrays.items():
        C_dict[name] = compute_Cs(array)
    outputs = []
    for name, indexes in queries:
        Cs = C_dict[name]
        address = Cs[0]
        for d, idx in enumerate(indexes, start=1):
            address += Cs[d] * idx
        outputs.append(format_output(name, indexes, address))
    for out in outputs:
        print(out)

if __name__ == "__main__":
    main()