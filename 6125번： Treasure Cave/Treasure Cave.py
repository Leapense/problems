def solve():
    import sys
    input = sys.stdin.readline
    P, NS, T = map(int, input().split())
    tree = {}
    for _ in range(NS):
        N, B1, B2 = map(int, input().split())
        tree[N] = (B1, B2)
    res = []
    def dfs(node):
        res.append(node)
        if node == T:
            return True
        if node in tree:
            for nxt in tree[node]:
                if dfs(nxt):
                    return True
        res.pop()
        return False
    dfs(1)
    print(len(res))
    for x in res:
        print(x)

if __name__ == "__main__":
    solve()