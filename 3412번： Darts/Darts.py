import sys
input = sys.stdin.read

def calculate_score(x, y):
    distance_squared = x * x + y * y
    radii_squared = [20 * 20, 40 * 40, 60 * 60, 80 * 80, 100 * 100, 120 * 120, 140 * 140, 160 * 160, 180 * 180, 200 * 200]
    
    for p in range(10, 0, -1):
        if distance_squared <= radii_squared[10 - p]:
            return p
    return 0

def main():
    data = input().splitlines()
    t = int(data[0])
    index = 1
    results = []
    
    for _ in range(t):
        n = int(data[index])
        total_score = 0
        for i in range(1, n + 1):
            x, y = map(int, data[index + i].split())
            total_score += calculate_score(x, y)
        results.append(str(total_score))
        index += n + 1
    
    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    main()