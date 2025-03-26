import pytest
import io
import sys

from speed_smoother import smooth_speeds, main

@pytest.mark.parametrize("t_f, t_r, speeds, expected_result", [
    # 기본 케이스 (Basic case)
    (0.2, 0.8, [5.0, 5.1, 5.9, 6.0, 5.8, 5.1], [5, 5, 6, 6, 6, 5]),
    # 0과 1 사이 값 (Values between 0 and 1)
    (0.3, 0.7, [0.5, 1.0, 1.2, 0.9, 0.1], [1, 1, 1, 1, 1]),
    # 임계값 경계 테스트 (Threshold boundary tests)
    (0.2, 0.8, [5.0, 5.2, 5.8, 6.0], [5, 5, 6, 6]), # 정확히 경계값
    (0.2, 0.8, [5.0, 5.19, 5.79, 6.0], [5, 5, 5, 6]), # 경계값 바로 아래
    (0.2, 0.8, [5.0, 5.21, 5.81, 6.0], [5, 5, 6, 6]), # 경계값 바로 위
    # 히스테리시스 (이력 현상) 테스트 (Hysteresis test)
    (0.3, 0.7, [4.0, 4.5, 4.6, 4.5, 4.8], [4, 4, 4, 4, 5]), # 4.5 -> 4 (last_display=4)
    (0.3, 0.7, [5.0, 4.8, 4.5, 4.6, 4.5], [5, 5, 5, 5, 5]), # 4.5 -> 5 (last_display=5)
    # 빈 입력 리스트 (Empty input list)
    (0.2, 0.8, [], []),
    # 음수 값 (Negative values - 현재 코드는 음수를 floor 처리)
    (0.2, 0.8, [-1.5, -0.5, 0.1], [-1, 0, 1]), # floor(-1.5)=-2, floor(-0.5)=-1. 0 < 0.1 < 1 => 1
])

def test_smooth_speeds_logic(t_f, t_r, speeds, expected_result):
    assert smooth_speeds(t_f, t_r, speeds) == expected_result

def test_main_function_io(monkeypatch, capsys):
    input_data = "0.2 0.8 5.0 5.1 5.9 6.0 5.8 5.1"
    expected_output = "5\n5\n6\n6\n6\n5\n"

    monkeypatch.setattr(sys, 'stdin', io.StringIO(input_data))
    main()

    captured = capsys.readouterr()

    assert captured.out == expected_output

def test_main_function_empty_input(monkeypatch, capsys):
    input_data = ""
    expected_output = ""
    monkeypatch.setattr(sys, 'stdin', io.StringIO(input_data))
    main()

def test_main_function_only_tf_tr(monkeypatch, capsys):
    """main 함수가 t_f, t_r만 있고 speeds가 없는 입력을 처리하는지 테스트합니다."""
    input_data = "0.3 0.7"
    expected_output = "" # speeds가 없으므로 아무것도 출력하지 않아야 함

    monkeypatch.setattr(sys, 'stdin', io.StringIO(input_data))
    main()
    captured = capsys.readouterr()
    assert captured.out == expected_output

