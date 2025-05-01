import pytest
from solution import process

INPUT_1 = """
4
1 SUBSCRIBE ana, carlos
1 SUBSCRIBE ana, sabrina
2 PUBLISH sabrina
3 SUBSCRIBE carlos, ana
6
1 SUBSCRIBE antonio, barbara
2 SUBSCRIBE barbara, cristina
3 SUBSCRIBE cristina, antonio
4 PUBLISH antonio
4 PUBLISH barbara
4 PUBLISH cristina
0
""".splitlines()

EXPECTED_1 = [
    "carlos",
    "antonio barbara cristina"
]

INPUT_2 = """
3
1 SUBSCRIBE a, b
2 SUBSCRIBE b, c
3 UNSUBSCRIBE a, b
0
""".splitlines()

EXPECTED_2 = [
    "a b c"
]

INPUT_3 = """
5
1 SUBSCRIBE x, y
2 PUBLISH y
2 PUBLISH x
2 PUBLISH y
3 PUBLISH x
0
""".splitlines()

EXPECTED_3 = [
    "y"
]

def test_sample_input_1():
    assert process(INPUT_1) == EXPECTED_1

def test_no_publish_all_zero():
    assert process(INPUT_2) == EXPECTED_2

def test_multiple_publishes_same_day():
    assert process(INPUT_3) == EXPECTED_3