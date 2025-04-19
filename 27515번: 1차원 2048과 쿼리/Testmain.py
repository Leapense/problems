import subprocess

def test_sample():
    inp = '4\n+1\n+2\n+1\n-2\n'
    res = subprocess.run(
        ['python3', '1차원 2048과 쿼리.py'],
        input=inp, text=True, capture_output=True
    )
    assert res.returncode == 0, f"프로그램이 비정상 종료했습니다: {res.stderr!r}"
    assert res.stdout == '1\n2\n4\n2'
