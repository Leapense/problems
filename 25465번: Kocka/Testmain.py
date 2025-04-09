def solve():
    import sys
    data = sys.stdin.read().split()
    it = iter(data)
    if not data:
        return
    N = int(next(it))
    Q = int(next(it))
    colored = {}
    out_lines = []
    INF = 10**9
    for _ in range(Q):
        typ = next(it)
        if typ == "1":
            x = int(next(it)) - 1
            y = int(next(it)) - 1
            z = int(next(it)) - 1
            c = next(it)
            colored[(x, y, z)] = c
        else:
            s = next(it)
            res = [["0"] * N for _ in range(N)]
            dist = [[INF] * N for _ in range(N)]
            for (x, y, z), c in colored.items():
                if s == "prednja":
                    i, j, d = x, y, z
                elif s == "straznja":
                    i, j, d = x, N - 1 - y, (N - 1 - z)
                elif s == "lijeva":
                    i, j, d = x, N - 1 - z, y
                elif s == "desna":
                    i, j, d = x, z, (N - 1 - y)
                else:
                    continue
                if 0 <= i < N and 0 <= j < N and d < dist[i][j]:
                    dist[i][j] = d
                    res[i][j] = c
            # Adjust rows if necessary for some rotations.
            if s in ("straznja", "lijeva"):
                for i in range(N):
                    res[i] = res[i][::-1]
            for row in res:
                out_lines.append(" ".join(row))
    sys.stdout.write("\n".join(out_lines))

import io
import sys
import pytest

def run_io_fun(input_data, func):
    backup_stdin = sys.stdin
    backup_stdout = sys.stdout
    sys.stdin = io.StringIO(input_data)
    sys.stdout = io.StringIO()

    try:
        func()
        return sys.stdout.getvalue()
    finally:
        sys.stdin = backup_stdin
        sys.stdout = backup_stdout

def test_sample_1():
    input_data = """\
2 5
2 prednja
1 1 1 1 1
1 2 2 2 5
2 straznja
2 desna
"""
    expected_output = """\
0 0
0 0
0 1
5 0
1 0
0 5"""
    output = run_io_fun(input_data, solve)
    out_lines = [line.rstrip() for line in output.strip().splitlines()]
    exp_lines = [line.rstrip() for line in expected_output.strip().splitlines()]
    assert out_lines == exp_lines

def test_sample_2():
    input_data = """\
3 5
1 2 1 2 1
1 2 2 2 2
1 2 3 2 3
2 lijeva
2 desna
"""
    expected_output = """\
0 0 0
0 1 0
0 0 0
0 0 0
0 3 0
0 0 0"""
    output = run_io_fun(input_data, solve)
    out_lines = [line.rstrip() for line in output.strip().splitlines()]
    exp_lines = [line.rstrip() for line in expected_output.strip().splitlines()]
    assert out_lines == exp_lines


def test_sample_3():
    input_data = """\
2 6
1 2 1 2 1
1 1 1 1 3
1 2 1 2 2
1 1 1 2 4
2 prednja
2 straznja
"""
    expected_output = """\
3 0
2 0
0 4
0 2"""
    output = run_io_fun(input_data, solve)
    out_lines = [line.rstrip() for line in output.strip().splitlines()]
    exp_lines = [line.rstrip() for line in expected_output.strip().splitlines()]
    assert out_lines == exp_lines

if __name__ == '__main__':
    pytest.main()