import textwrap
from solution import solve

def parse(out: str):
    return list(map(int, out.strip().split()))

def test_sample1():
    inp = textwrap.dedent("""\
        3
        1 1 4
        4 1 5
        7 4 3
    """)
    assert parse(solve(inp)) == [3, 5, 3]

def test_sample2():
    inp = textwrap.dedent("""\
        3
        0 0 10
        4 6 8
        6 6 6
    """)
    assert parse(solve(inp)) == [10, 7, 2]

def test_sample3():
    inp = textwrap.dedent("""\
        5
        2 6 2
        4 10 4
        5 6 6
        8 8 7
        10 2 8
    """)
    assert parse(solve(inp)) == [2, 4, 3, 6, 8]