import subprocess
import sys
import pytest

@pytest.mark.parametrize("input_s, expected", [
    ("3\n"
     "0\n"
     "1 0\n"
     "1 0 0\n"
     "0\n"
     "0 0\n"
     "0 0 1\n", "1\n"),
    ("4\n"
     "0\n"
     "1 1\n"
     "1 0 0\n"
     "1 0 0 0\n"
     "0\n"
     "0 0\n"
     "0 0 1\n"
     "1 1 1 0\n", "0\n"),
    ("4\n"
     "0\n"
     "1 0\n"
     "0 0 1\n"
     "1 1 0 0\n"
     "0\n"
     "0 1\n"
     "0 0 0\n"
     "0 1 1 1\n", "2\n"),
])
def test_solution(input_s, expected):
    # solution.py 파일을 실행하도록 경로를 맞춰 주세요.
    proc = subprocess.run(
        [sys.executable, "두 정삼각형.py"],
        input=input_s.encode(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    # 만약 stderr에 에러가 찍힌다면 이 두 줄의 주석을 해제해서 확인해 보세요:
    # print(proc.stderr.decode())
    # print("Return code:", proc.returncode)
    assert proc.stdout.decode() == expected
