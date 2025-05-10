import textwrap
from solution import min_guitars_needed

def _run_io(raw: str) -> str:
    raw = textwrap.dedent(raw).lstrip("\n")
    lines = raw.splitlines()
    N, M = map(int, lines[0].split())
    body = lines[1:]
    return str(min_guitars_needed(N, M, body))

def test_sample1():
    input_data = """
        4 5
        GIBSON YYYNN
        FENDER YYNNY
        EPIPHONE NNNYY
        ESP YNNNN
    """
    assert _run_io(input_data) == "2"

def test_sample2():
    input_data = """
        3 5
        GIBSON YNYYN
        FENDER NNNYY
        TAYLOR YYYYY
    """
    assert _run_io(input_data) == "1"

def test_sample3():
    input_data = """
        3 2
        AB YN
        AA YN
        BA NN
    """
    assert _run_io(input_data) == "1"

def test_sample4():
    input_data = """
        5 7
        FENDER YYNNYNN
        GIBSON YYYNYNN
        CRAFTER NNNNNYY
        EPIPHONE NNYNNNN
        BCRICH NNNYNNN
    """
    assert _run_io(input_data) == "3"

def test_sample5():
    input_data = """
        2 25
        GIBSON NNNNNNNNNNNNNNNNNNNNNNNNN
        FENDER NNNNNNNNNNNNNNNNNNNNNNNNN
    """
    assert _run_io(input_data) == "-1"