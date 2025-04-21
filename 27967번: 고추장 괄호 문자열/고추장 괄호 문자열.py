def fill(s):
    n = len(s)
    res = []
    def dfs(i, bal):
        if bal < 0 or bal > n - i:
            return False
        if i == n:
            return bal == 0
        c = s[i]
        if c == '(':
            res.append('(')
            if dfs(i + 1, bal + 1): return True
            res.pop()
        elif c == ')':
            res.append(')')
            if dfs(i + 1, bal - 1): return True
            res.pop()
        else:
            res.append('(')
            if dfs(i + 1, bal + 1): return True
            res.pop()
            res.append(')')
            if dfs(i + 1, bal - 1): return True
            res.pop()
        return False
    
    dfs(0, 0)
    return ''.join(res)

def solve():
    _ = input().strip()
    s = input().strip()
    print(fill(s))

if __name__ == '__main__':
    solve()