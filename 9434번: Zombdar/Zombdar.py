def solve():
    import sys
    input = sys.stdin.readline
    
    N = int(input().strip())
    for _ in range(N):
        buffer = ""
        timestamp = 0
        while True:
            line = input()
            if not line:
                # EOF 처리(문제 상 없을 것으로 가정)
                break
            line = line.rstrip('\n')
            
            # 종료 조건 확인
            if line == "END OF CASE":
                break
            
            timestamp += 1
            buffer += line  # 버퍼에 현재 라인 추가
            
            # ';'를 발견할 때까지 처리
            while True:
                semicolon_index = buffer.find(';')
                if semicolon_index == -1:
                    break
                # 하나의 완성된 로그 추출
                entry = buffer[:semicolon_index+1]
                print(f"{timestamp}: {entry}")
                buffer = buffer[semicolon_index+1:]

solve()