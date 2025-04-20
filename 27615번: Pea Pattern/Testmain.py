import pytest
import importlib.util

spec = importlib.util.spec_from_file_location("pea_pattern", "Pea Pattern.py")
pea_pattern = importlib.util.module_from_spec(spec)
spec.loader.exec_module(pea_pattern)

@pytest.mark.parametrize("n,m,expected", [
    ("1", "3112", 5),
    ("1", "3113", "Does not appear"),
    ("20902", "101011213141516171829", 10),
    ("0", "0", 1),
    ("22", "2210", "Does not appear"),
])

def test_pea_pattern(n, m, expected):
    assert pea_pattern.pea_pattern_position(n, m) == expected