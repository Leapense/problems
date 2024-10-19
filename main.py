def read_input(filename):
    with open(filename, 'r') as file:
        N = int(file.readline().strip())
        image = []
        for _ in range(N):
            row = list(map(int, file.readline().strip().split()))
            image.append(row)
    return N, image

def write_output(filename, operations):
    with open(filename, 'w') as file:
        file.write(f"{len(operations)}\n")
        for op in operations:
            file.write(f"{op[0]} {op[1]} {op[2]} {op[3]}\n")

def find_xor_operations(N, image):
    operations = []
    toggled = [[0] * N for _ in range(N)]
    
    def toggle(L, R, T, B):
        for r in range(T, B):
            for c in range(L, R):
                toggled[r][c] ^= 1

    for r in range(N):
        for c in range(N):
            if image[r][c] != toggled[r][c]:
                L, R, T, B = c, c, r, r
                while R < N and image[T][R] != toggled[T][R]:
                    R += 1
                while B < N and all(image[B][k] != toggled[B][k] for k in range(L, R)):
                    B += 1
                operations.append((L, R, T, B))
                toggle(L, R, T, B)

    return operations

def main():
    for i in range(6, 7):
        input_filename = f"xor{i}.in"
        output_filename = f"xor{i}.out"
        N, image = read_input(input_filename)
        operations = find_xor_operations(N, image)
        write_output(output_filename, operations)

if __name__ == "__main__":
    main()