# test_solution.py
import subprocess
import sys
import tempfile
import os

import pytest

from io import StringIO

@pytest.mark.parametrize("input_data, expected", [
    (
        "5 2 5\n1 2 3 1 2\n1 2 3 4 5\n",
        "1\n1\n2\n4\n4\n"
    ),
    (
        "3 1 3\n1 1 1\n1 2 3\n",
        "0\n0\n0\n"
    ),
    (
        "6 3 4\n2 2 3 1 1 2\n2 4 5 6\n",
        "3\n5\n7\n9\n"
    ),
])
def run_io(input_data, expected, tmp_path):
    # 임시 파일에 소스코드 저장
    code = """
import sys
input = sys.stdin.readline

def main():
    N, K, Q = map(int, input().split())
    A = list(map(int, input().split()))
    X = list(map(int, input().split()))

    dp = [0] * (N + 1)
    res = [0] * (N + 1)

    for i in range(1, N + 1):
        if A[i-1] != K:
            dp[i] = dp[i-1] + 1
        else:
            dp[i] = 0
        res[i] = res[i-1] + dp[i]

    out = []
    for x in X:
        out.append(str(res[x]))
    sys.stdout.write("\\n".join(out))

if __name__ == "__main__":
    main()
"""
    file_path = tmp_path / "solution.py"
    file_path.write_text(code)

    # 파이썬 서브프로세스로 실행
    result = subprocess.run([sys.executable, str(file_path)],
                            input=input_data.encode(),
                            stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE)
    output = result.stdout.decode()
    assert output == expected
