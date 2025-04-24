import subprocess, sys, os, textwrap, itertools

SOURCE = "solution.py"

def run_case(inp: str) -> list[list[int]]:
    proc = subprocess.run([sys.executable, SOURCE],
                          input=inp.encode(),
                          stdout=subprocess.PIPE,
                          check=True)
    out = proc.stdout.decode().strip().splitlines()
    return [list(map(int, line.split())) for line in out]

def check_matrix(mat, n, k):
    assert len(mat) == n
    for row in mat:
        assert len(row) == k
        for v in row:
            assert 0 <= v <= 10
    half = k // 2
    for i in range(n):
        prev, nxt = (i - 1) % n, (i + 1) % n
        win_prev = sum(mat[i][d] > mat[prev][d] for d in range(k))
        win_nxt = sum(mat[i][d] > mat[nxt][d] for d in range(k))
        assert win_prev > half
        assert win_nxt <= half

def test_sample():
    n, k = 7, 5
    mat = run_case(f"{n} {k}\n")
    check_matrix(mat, n, k)

def test_random_small():
    import random
    for n, k in itertools.product(range(4, 15), range(4, 11)):
        mat = run_case(f"{n} {k}\n")
        check_matrix(mat, n, k)

