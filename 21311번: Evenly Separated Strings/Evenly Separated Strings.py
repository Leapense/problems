def solve():
    s = input().strip()
    positions = [[] for _ in range(26)]
    for i, ch in enumerate(s):
        positions[ord(ch) - ord('a')].append(i)

    for p in positions:
        if len(p) > 2:
            print("NO")
            return
        if len(p) == 2:
            if (p[1] - p[0]) % 2 == 0:
                print("NO")
                return
            
    print("YES")

solve()