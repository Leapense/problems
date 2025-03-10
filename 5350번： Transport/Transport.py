import sys

def solve():
    input_data = sys.stdin.read().strip().split()
    t = int(input_data[0])
    index = 1
    results = []
    for _ in range(t):
        n = int(input_data[index]); W = int(input_data[index+1])
        index += 2
        items = []
        for i in range(n):
            w = int(input_data[index]); v = int(input_data[index+1])
            index += 2
            items.append((w, v))
        best = 0
        def rec(i, weight, value):
            nonlocal best
            if i == n:
                if value > best:
                    best = value
                return
            if weight + items[i][0] <= W:
                rec(i+1, weight+items[i][0], value+items[i][1])
            rec(i+1, weight, value)
        rec(0,0,0)
        results.append(str(best))
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    solve()