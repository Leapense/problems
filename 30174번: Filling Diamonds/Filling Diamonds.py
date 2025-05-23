def solve():
    t = int(input())
    results = []
    for _ in range(t):
        n = int(input())
        results.append(n)
    print("\n".join(map(str, results)))

solve()