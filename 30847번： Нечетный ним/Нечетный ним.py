def main():
    import sys

    try:
        # 한 줄씩 입력을 받는 방식 사용 (strip()으로 불필요한 공백 제거)
        n_line = sys.stdin.readline().strip()
        if not n_line:
            # 입력이 없으면 빈 문자열 반환 (또는 적절한 처리를 할 수 있음)
            return
        n = int(n_line)
        
        stones_line = sys.stdin.readline().strip()
        # stones_line 이 비어있을 경우를 고려하여 분리
        if not stones_line:
            stones = []
        else:
            stones = list(map(int, stones_line.split()))
        
        # 각 더미의 돌의 개수가 홀수인지 체크
        odd_count = sum(1 for x in stones if x % 2 == 1)

        # [일반 님]
        # 홀수 개의 돌을 가진 더미가 홀수개이면 nim-합은 1 → Misha 승리, 짝수면 Gleb 승리
        if odd_count % 2 == 1:
            normal_winner = "Misha"
        else:
            normal_winner = "Gleb"

        # [поддавки (misère)]
        # 일반 님과 반대로 결과가 결정됨
        if odd_count % 2 == 0:
            misere_winner = "Misha"
        else:
            misere_winner = "Gleb"

        print(normal_winner)
        print(misere_winner)
    except Exception as e:
        # 예외 발생 시 표준 에러에 출력하고 프로그램을 종료합니다.
        sys.stderr.write("Error: " + str(e))
        sys.exit(1)

if __name__ == '__main__':
    main()
