import subprocess, pathlib, pytest, textwrap, os, sys

BIN = ["python3", str(pathlib.Path(__file__).with_name("solution.py"))]

def run_io(data: str) -> str:
    res = subprocess.run(BIN, input=data.encode(), stdout=subprocess.PIPE, check=True)
    return res.stdout.decode().strip()

@pytest.mark.parametrize("n, expected", [
    (1,  "1 0"),
    (2,  "0 2"),
    (3,  "0 3"),
    (4,  "1 3"),
    (10, "3 7"),   # 수정된 정답
])
def test_samples(n, expected):
    assert run_io(f"{n}\n") == expected