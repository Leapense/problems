import io
import sys
import importlib

# 문제 풀이 모듈을 가져온다
main = importlib.import_module("main")

def run_io(inp: str) -> str:
    backup_stdin, backup_stdout = sys.stdin, sys.stdout
    sys.stdin, sys.stdout = io.StringIO(inp), io.StringIO()
    main.solve()
    output = sys.stdout.getvalue()
    sys.stdin, sys.stdout = backup_stdin, backup_stdout
    return output

def check_grid(r, c, rr, cr, rb, cb, lines):
    if (r * c) & 1:
        assert lines == ["IMPOSSIBLE"]
        return
    red, blue = set(), set()
    for i in range(r):
        for j, ch in enumerate(lines[i]):
            (red if ch == 'R' else blue).add((i, j))
    assert (rr - 1, cr - 1) in red
    assert (rb - 1, cb - 1) in blue
    assert len(red) == len(blue)
    rot = lambda x, y: (r - 1 - x, c - 1 - y)
    assert all(rot(x, y) in blue for x, y in red)

def test_sample():
    raw = """3

5 5
1 1
3 4

4 6
1 1
4 6

4 6
1 1
1 2
"""
    out = run_io(raw).rstrip("\n").split("\n")
    # 케이스 1
    assert out[0] == "IMPOSSIBLE"
    idx = 2
    # 케이스 2
    grid2 = out[idx:idx + 4]; idx += 5
    check_grid(4, 6, 1, 1, 4, 6, grid2)
    # 케이스 3
    grid3 = out[idx:idx + 4]
    check_grid(4, 6, 1, 1, 1, 2, grid3)
