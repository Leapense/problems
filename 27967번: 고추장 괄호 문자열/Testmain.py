import pytest

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
            if dfs(i+1, bal+1): return True
            res.pop()
        elif c == ')':
            res.append(')')
            if dfs(i+1, bal-1): return True
            res.pop()
        else:
            res.append('(')
            if dfs(i+1, bal+1): return True
            res.pop()
            res.append(')')
            if dfs(i+1, bal-1): return True
            res.pop()
        return False

    dfs(0, 0)
    return ''.join(res)

def is_valid(seq):
    bal = 0
    for ch in seq:
        if ch == '(':
            bal += 1
        elif ch == ')':
            bal -= 1
        else:
            return False
        if bal < 0:
            return False
    return bal == 0

def test_sample1():
    inp = "GG"
    out = fill(inp)
    assert len(out) == len(inp)
    assert is_valid(out)

def test_sample2():
    inp = "(G)GG)"
    out = fill(inp)
    assert len(out) == len(inp)
    assert is_valid(out)
    for orig, repl in zip(inp, out):
        if orig in '()':
            assert orig == repl

def test_sample3():
    inp = "GG()((GG)G)G()GG)G()"
    out = fill(inp)
    assert len(out) == len(inp)
    assert is_valid(out)
    for orig, repl in zip(inp, out):
        if orig in '()':
            assert orig == repl