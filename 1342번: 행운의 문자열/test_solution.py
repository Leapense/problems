import pytest
from solution import calculate_lucky_strings

def test_sample_1():
    assert calculate_lucky_strings("aabbbaa") == 1

def test_sample_2():
    assert calculate_lucky_strings("ab") == 2

def test_sample_3():
    assert calculate_lucky_strings("aaab") == 0

def test_sample_4():
    assert calculate_lucky_strings("abcdefghij") == 3628800

def test_single_character():
    assert calculate_lucky_strings("a") == 1
    assert calculate_lucky_strings("z") == 1

def test_all_same_characters():
    assert calculate_lucky_strings("aa") == 0
    assert calculate_lucky_strings("aaa") == 0
    assert calculate_lucky_strings("aaaaa") == 0

def test_string_aba():
    assert calculate_lucky_strings("aba") == 1
    assert calculate_lucky_strings("aab") == 1
    assert calculate_lucky_strings("baa") == 1

def test_string_aaabb():
    assert calculate_lucky_strings("aaabb") == 1

def test_string_abc():
    assert calculate_lucky_strings("abc") == 6

def test_string_abacaba():
    assert calculate_lucky_strings("aabc") == 6
    assert calculate_lucky_strings("abacaba") == 3

def test_long_string_some_repetition():
    assert calculate_lucky_strings("abac") == 6