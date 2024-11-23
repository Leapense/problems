import sys

def process_data_sets(P, data_sets):
    results = []
    for S, N, indices in data_sets:
        encoded = []
        current_index = 0  # Start at index 0
        length_S = len(S)
        for k in indices:
            current_index = (current_index + k) % length_S
            encoded.append(S[current_index])
        results.append(''.join(encoded))
    return results

def main():
    input_lines = sys.stdin.read().splitlines()
    P = int(input_lines[0].strip())
    data_sets = []
    idx = 1
    for _ in range(P):
        if idx >= len(input_lines):
            break
        S = input_lines[idx].rstrip('\n')
        idx +=1
        if idx >= len(input_lines):
            N = 0
            indices = []
        else:
            N_line = input_lines[idx].strip()
            while N_line == '':
                # Skip empty lines
                idx +=1
                if idx >= len(input_lines):
                    N_line = '0'
                    break
                N_line = input_lines[idx].strip()
            N = int(N_line)
            idx +=1
            if idx >= len(input_lines):
                indices = []
            else:
                indices_line = input_lines[idx].strip()
                while indices_line == '':
                    idx +=1
                    if idx >= len(input_lines):
                        indices_line = ''
                        break
                    indices_line = input_lines[idx].strip()
                if indices_line:
                    indices = list(map(int, indices_line.split()))
                else:
                    indices = []
                idx +=1
        data_sets.append((S, N, indices))
    encoded_results = process_data_sets(P, data_sets)
    for res in encoded_results:
        print(res)

if __name__ == "__main__":
    main()
