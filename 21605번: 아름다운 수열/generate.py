# test_generator.py
import argparse
import random
import sys

def generate_test_case(args):
    """
    argparse로 전달받은 인자를 기반으로 N값을 결정하고 출력합니다.
    """
    subtask = args.subtask
    max_n = args.max_n

    n_min, n_max = 1, 1 # 기본값 설정

    if subtask == 1:
        # 서브태스크 1: 1 <= N <= 4
        n_min, n_max = 1, 4
    elif subtask == 2:
        # 서브태스크 2: 1 <= N <= 10
        n_min, n_max = 1, 10
    elif subtask == 3:
        # 서브태스크 3: 추가 제약 없음 (사용자 지정 최댓값 사용)
        n_min, n_max = 1, max_n
    
    # 해당 범위 내에서 무작위 정수 n 생성
    n = random.randint(n_min, n_max)
    print(n)

def main():
    """
    명령어 줄 인자를 파싱하고 테스트 케이스 생성을 호출합니다.
    """
    # 1. ArgumentParser 객체 생성
    parser = argparse.ArgumentParser(
        description="주어진 소스 코드를 위한 무작위 테스트 케이스 생성기"
    )

    # 2. 원하는 인자(argument) 추가
    parser.add_argument(
        '-s', '--subtask',
        type=int,
        choices=[1, 2, 3],
        default=3,
        help="생성할 테스트 케이스의 서브태스크 번호를 지정합니다 (기본값: 3)."
    )
    parser.add_argument(
        '--max-n',
        type=int,
        default=100000,
        help="서브태스크 3에서 사용할 N의 최댓값을 지정합니다 (기본값: 100000)."
    )

    # 3. 인자 파싱
    args = parser.parse_args()

    # 4. 파싱된 인자를 사용하여 메인 로직 실행
    generate_test_case(args)


if __name__ == "__main__":
    main()