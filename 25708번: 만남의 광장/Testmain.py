import sys
import io

def solve():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(N)]
    rowSum = [sum(r) for r in grid]
    colSum = [sum(grid[i][j] for i in range(N)) for j in range(M)]
    ans = -10**18
    for i in range(N):
        for k in range(i+1, N):
            A = k - i - 1
            arr = [colSum[j] - (grid[i][j] + grid[k][j]) for j in range(M)]
            best = -10**18
            best_val = -10**18
            for l in range(1, M):
                best = max(best, arr[l-1] - A * (l-1))
                candidate = best + arr[l] + A * l - A
                best_val = max(best_val, candidate)
            ans = max(ans, rowSum[i] + rowSum[k] + best_val)
    sys.stdout.write(str(ans))


if __name__ == '__main__':
    solve()


def test_sample1():
    from io import StringIO
    input_str = '4 4\n8 2 1 4\n2 3 7 4\n4 1 2 3\n5 6 9 1\n'
    expected_output = '58'
    sys.stdin = StringIO(input_str)
    sys.stdout = io.StringIO()
    solve()
    output = sys.stdout.getvalue().strip()
    assert output == expected_output

def test_sample2():
    from io import StringIO
    input_str = '3 6\n-9 -1 -3 13 -8 -14\n-6 -20 -15 0 14 4\n-6 7 18 13 14 4\n'
    expected_output = '46'
    sys.stdin = StringIO(input_str)
    sys.stdout = io.StringIO()
    solve()
    output = sys.stdout.getvalue().strip()
    assert output == expected_output

def test_sample3():
    from io import StringIO
    grid = "\n".join([" ".join(["1"] * 10) for _ in range(10)])
    input_str = f"10 10\n{grid}\n"
    expected_output = "100"
    sys.stdin = StringIO(input_str)
    sys.stdout = io.StringIO()
    solve()
    output = sys.stdout.getvalue().strip()
    assert output == expected_output
