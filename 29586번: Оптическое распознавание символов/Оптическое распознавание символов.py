def find_most_similar_symbol(n, w, h, symbols, image):
    max_similarity = -1
    best_symbol_index = 0

    # Iterate over each symbol and compare it with the input image
    for i in range(n):
        current_similarity = 0
        for row in range(h):
            for col in range(w):
                if symbols[i][row][col] == image[row][col]:
                    current_similarity += 1

        # Update the best symbol if the current one is more similar
        if current_similarity > max_similarity:
            max_similarity = current_similarity
            best_symbol_index = i + 1  # 1-based index

    return best_symbol_index

# Read input
n, w, h = map(int, input().split())
symbols = []

# Read each symbol's grid
for _ in range(n):
    symbol = [input().strip() for _ in range(h)]
    symbols.append(symbol)

# Read the input image
image = [input().strip() for _ in range(h)]

# Get and print the most similar symbol index
result = find_most_similar_symbol(n, w, h, symbols, image)
print(result)