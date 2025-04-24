import sys
import io

from solution import main

def run(input_data: str) -> str:
    backup_in = sys.stdin
    sys.stdin = io.StringIO(input_data)
    try:
        main()
        return sys.stdout.getvalue()
    finally:
        sys.stdin = backup_in

def test_sample1(monkeypatch, capsys):
    input_data = "5 2\n1 2 3 4 5\n"
    expected = "5\n1 2 3 4 5\n"
    out = run(input_data)
    assert out.strip() == expected.strip()

def test_sample2(monkeypatch, capsys):
    input_data = "3 1\n1 1 1\n"
    expected = "3\n0 1 2\n"
    out = run(input_data)
    assert out.strip() == expected.strip()
