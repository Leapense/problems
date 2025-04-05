import sys
import io
import pytest

def solve():
    import sys
    input = sys.stdin.readline
    N, K = map(int, input().split())
    # 0-indexed 행 번호
    r = K - 1
    size = 1 << N  # 2^N 크기
    result = [''] * size

    # 각 열에 대해 해당하는 문자를 결정
    for c in range(size):
        letter = None
        # 상위 비트부터 확인 (N 단계부터 0단계까지)
        for i in range(N - 1, -1, -1):
            r_bit = (r >> i) & 1
            c_bit = (c >> i) & 1
            if r_bit == 0:
                # 좌상단 또는 우상단: r_bit==0 인 경우
                letter = 'J' if c_bit == 0 else 'O'
                break
            else:
                # r_bit == 1 인 경우: 좌하단 또는 우하단
                if c_bit == 0:
                    letter = 'I'
                    break
                # (r_bit, c_bit) == (1,1)인 경우는 아직 결정할 수 없으므로 계속 진행
        # 모든 단계에서 (1,1)이라면 기저 사례 N=0에서 'J'
        if letter is None:
            letter = 'J'
        result[c] = letter

    sys.stdout.write(''.join(result))

# --- pytest 테스트 케이스 --- #
def run_io_fun(input_data, func=solve):
    """
    주어진 입력 문자열을 함수에 전달하여 표준출력 결과를 반환하는 헬퍼 함수.
    """
    backup_stdin = sys.stdin
    backup_stdout = sys.stdout
    sys.stdin = io.StringIO(input_data)
    out = io.StringIO()
    sys.stdout = out
    try:
        func()
    finally:
        sys.stdin = backup_stdin
        sys.stdout = backup_stdout
    return out.getvalue()

def test_sample1():
    # 샘플 테스트 케이스 1: N=1, K=1
    input_data = "1 1\n"
    expected_output = "JO"
    assert run_io_fun(input_data) == expected_output

def test_sample2():
    # 샘플 테스트 케이스 2: N=2, K=4
    input_data = "2 4\n"
    expected_output = "IIIJ"
    assert run_io_fun(input_data) == expected_output

def test_sample3():
    # 샘플 테스트 케이스 3: N=3, K=7
    input_data = "3 7\n"
    expected_output = "IIIIIIJO"
    assert run_io_fun(input_data) == expected_output

if __name__ == '__main__':
    # 직접 실행 시 pytest를 실행하여 테스트 수행
    pytest.main()

