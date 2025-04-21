import subprocess
import sys

def run(input_s: str) -> str:
    p = subprocess.run([sys.executable, "타노스는 요세푸스가 밉다.py"], input=input_s, text=True, capture_output=True)
    return p.stdout.strip()


def test_sample1():
    assert run("5 4\n") == "5"

def test_sample2():
    assert run("1007 15\n") == "871"

def test_min_values():
    assert run("2 2\n") == "1"

def test_k_large():
    assert run("10 100\n") == "1"