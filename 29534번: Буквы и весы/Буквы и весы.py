def min_cubes_needed(n, s):
    if n < len(s):
        return "Impossible"
    
    total_cubes = 0
    for char in s:
        total_cubes += ord(char) - ord('a') + 1

    return total_cubes

n = int(input().strip())
s = input().strip()

print(min_cubes_needed(n, s))