import subprocess
import sys
import pytest

@pytest.mark.parametrize("input_s, expected", [
    # Sample 1
    ("""\
2
4
010111
111?11
110101
1100??
7
1?????
??????
??????
?????1
??????
??????
?0????
""",
     "2\nCANNOT DECIPHER\n"
    ),
    # Minimal: single letter, exact vowel
    ("""\
1
1
110101
""", "1\n"),  # only one vowel, word must have one vowel
    # Minimal: single letter, exact consonant -> no valid
    ("""\
1
1
110000
""", "0\n"),
    # Mixed with no wildcards
    ("""\
1
3
110101
110000
101101
""", "2\n"),  
    # All wildcards, length 2:
    # vs=[4,4], cs=[12,12].
    # Total no-consec-v = dp: 
    # dp0=1,dp1=0
    # i=1: dp0=1*12=12; dp1=1*4=4
    # i=2: dp0=(12+4)*12=192; dp1=12*4=48; total=240
    # zero_all_cons=12*12=144 → valid=240-144=96
    ("""\
1
2
??????
??????
""", "96\n"),
])
def test_solution(input_s, expected):
    p = subprocess.run(
        [sys.executable, "solution.py"],
        input=input_s, text=True, capture_output=True
    )
    assert p.stdout == expected