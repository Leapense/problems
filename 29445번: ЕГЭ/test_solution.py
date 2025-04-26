import sys
import io
import pytest
from solution import main

def run(input_str):
    sys.stdin = io.StringIO(input_str)
    sys.stdout = io.StringIO()
    main()
    return sys.stdout.getvalue()

def test_sample1():
    assert run("3 2\n") == "1101001"

def test_sample2():
    assert run("4 6\n") == "0011001"