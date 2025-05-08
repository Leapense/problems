import pytest
from io import StringIO
from solution import main

def run_test_case(input_data, expected_output, capsys, monkeypatch):
    monkeypatch.setattr('sys.stdin', StringIO(input_data))
    main()
    captured = capsys.readouterr()
    assert captured.out.strip() == expected_output.strip()

test_suite_data = [
    (
        """4
i is 42
while i
    subtract i
print i
j is 1337
while j
    add j
print j""",
        """3
42 1337
i j
subtract add"""
    ),
    (
        """3
ans is 42
if ans is 42
    print ans
ans is 42
if ans is not 42
    print ans""",
        """-1"""
    ),
    (
        """2
ans is 42
print items
ans is 42
print ans""",
        """-1"""
    ),
    (
        """2
hello world
this is a test
hello world
this is a test""",
        """0"""
    ),
    (
        """2
hello world
test
hello world wide
test""",
        """-1"""
    ),
    (
        """1
a a
x y""",
        """-1"""
    ),
    (
        """1
a b
x x""",
        """-1"""
    ),
    (
        """3
var_A = input ( )
var_B = process ( var_A )
print var_B
temp1 = input ( )
temp2 = process ( temp1 )
print temp2""",
        """2
var_A temp1
var_B temp2"""
    ),
    (
        """2
  leading space   word
another line
  leading space   new_word
another line""",
        """1
word new_word"""
    ),
    (
        """1
Variable var
variable var""",
        """1
Variable variable"""
    ),
    (
        """2
fixed_word var1
another_fixed var2
fixed_word val1
another_fixed val2""",
        """2
var1 val1
var2 val2"""
    ),
    (
        """1
a b c
x y x""",
        """-1"""
    )
]

@pytest.mark.parametrize("input_data, expected_output", test_suite_data)
def test_fraud_checking_cases(input_data, expected_output, capsys, monkeypatch):
    run_test_case(input_data, expected_output, capsys, monkeypatch)