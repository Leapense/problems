import pytest
from solution import calculate_total_pillar_length

def test_sample_1():
    platforms = [
        (1,5,10),
        (3,1,5),
        (5,3,7)
    ]
    assert calculate_total_pillar_length(platforms) == 14

def test_sample_2():
    platforms = [
        (50,50,90),
        (40,40,80),
        (30,30,70),
        (20,20,60),
        (10,10,50)
    ]
    assert calculate_total_pillar_length(platforms) == 200

def test_single_platform():
    platforms = [(10,1,5)]
    assert calculate_total_pillar_length(platforms) == 20

def test_perfectly_stacked_platforms():
    platforms = [
        (10,10,20),
        (20,10,20)
    ]
    assert calculate_total_pillar_length(platforms) == 40

def test_offset_stacked_platforms():
    platforms = [
        (10,10,30),
        (20,15,25)
    ]
    assert calculate_total_pillar_length(platforms) == 40

def test_partially_supported_platform():
    platforms = [
        (10,10,20),
        (20,5,15)
    ]
    assert calculate_total_pillar_length(platforms) == 50

def test_multiple_supports_choose_highest():
    platforms = [
        (1,1,20),
        (5,5,15),
        (10,7,12)
    ]
    assert calculate_total_pillar_length(platforms) == 20

def test_no_platforms():
    platforms = []
    assert calculate_total_pillar_length(platforms) == 0

def test_platforms_side_by_side_no_support_between_them():
    platforms = [
        (10,1,5),
        (10,6,10)
    ]
    assert calculate_total_pillar_length(platforms) == 40

def test_one_platform_very_high():
    platforms = [(9999,10,20)]
    assert calculate_total_pillar_length(platforms) == 19998

def test_narrow_supporting_platform_check():
    platforms = [
        (10,5,8),
        (20,5,8)
    ]
    assert calculate_total_pillar_length(platforms) == 40

def test_pillar_at_edge_of_potential_support_not_supported():
    platforms = [
        (10,1,5),
        (20,1,3)
    ]
    assert calculate_total_pillar_length(platforms) == 40

    platforms_edge = [
        (10,1,3),
        (20,0,2)
    ]

    assert calculate_total_pillar_length(platforms_edge) == 50