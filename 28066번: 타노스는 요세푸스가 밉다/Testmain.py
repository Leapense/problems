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

def test_random_small():
    import random
    for _ in range(20):
        n = random.randint(2, 50)
        k = random.randint(2, 10)
        arr = list(range(1, n + 1))
        cur = 0
        while len(arr) > 1:
            cnt = min(k, len(arr) - 1)
            remove = [(cur + i) % len(arr) for i in range(1, cnt + 1)]
            for idx in sorted(remove, reverse=True):
                arr.pop(idx)
            cur = (arr.index(arr[(remove[0] if remove else cur)]) + 1) % len(arr) if len(arr) > 1 else 0

        expected = str(arr[0])
        output = run(f"{n} {k}\n")
        assert output == expected