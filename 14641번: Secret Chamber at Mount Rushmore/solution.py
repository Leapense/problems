import sys

def solve():
    """
    '러시모어 산의 비밀의 방' 문제를 해결하는 메인 함수.
    플로이드-워셜 알고리즘을 사용하여 문자 간 도달 가능성을 미리 계산하고,
    이를 바탕으로 단어 쌍의 일치 여부를 판별한다.
    """
    try:
        input = sys.stdin.readline
        m, n = map(int, input().split())
        num_chars = 26
        reachable = [[False] * num_chars for _ in range(num_chars)]

        for i in range(num_chars):
            reachable[i][i] = True

        for _ in range(m):
            a, b = input().split()
            u, v = ord(a) - ord('a'), ord(b) - ord('a')
            reachable[u][v] = True

        for k in range(num_chars):
            for i in range(num_chars):
                for j in range(num_chars):
                    if reachable[i][k] and reachable[k][j]:
                        reachable[i][j] = True

        for _ in range(n):
            word1, word2 = input().split()
            if len(word1) != len(word2):
                print("no")
                continue
            match = True
            for i in range(len(word1)):
                char1_idx = ord(word1[i]) - ord('a')
                char2_idx = ord(word2[i]) - ord('a')
                if not reachable[char1_idx][char2_idx]:
                    match = False
                    break
            if match:
                print("yes")
            else:
                print("no")

    except (IOError, ValueError) as e:
        print(f"An error occurred: {e}", file=sys.stderr)

solve()