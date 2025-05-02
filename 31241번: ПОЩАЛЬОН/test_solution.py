import pytest
from solution import postman

def test_sample1():
    # 예제 입력 1
    assert postman(5, 4, [90, 20, 10, 50]) == 280

def test_single_house():
    # 집이 하나뿐인 경우
    assert postman(1, 1, []) == 0

def test_two_houses_start1():
    # 2개 집, 1번에서 시작
    assert postman(2, 1, [100]) == 100

def test_two_houses_start2():
    # 2개 집, 2번에서 시작
    assert postman(2, 2, [100]) == 100

def test_three_houses_middle_start():
    # 3개 집, 중간(2번)에서 시작
    # 거리 배열 [1,2]: pos=[0,1,3]
    # 순차: 2→1 (거리1) →3 (거리3): 총 4
    assert postman(3, 2, [1, 2]) == 4

if __name__ == "__main__":
    pytest.main()