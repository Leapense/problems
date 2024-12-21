import sys
input = sys.stdin.readline

def solve():
    K = int(input().strip())
    C = int(input().strip())

    # states[i] = "i번째 toss를 던지기 직전"에 (게임이 안 끝난 상태로) 도달 가능한 (m, n) 집합
    states = [set() for _ in range(2*K + 1)]
    states[0].add((0, 0))

    final_scores = set()

    for i in range(2*K):
        # 이번 턴이 영희 차례인지 여부
        is_younghee = (i % 2 == 0)

        for (m, n) in states[i]:
            # 던지기 결과 0점 or 1점 두 갈래
            for gain in [0, 1]:
                if is_younghee:
                    m_next, n_next = (m + gain, n)
                    # 이제 막 (i+1)번째 toss가 끝났으므로,
                    # 영희는 i//2 + 1번, 동수는 i//2번 던진 상태
                    y_used = (i // 2) + 1  # 영희가 사용한 toss 수
                    d_used = (i // 2)      # 동수가 사용한 toss 수
                else:
                    m_next, n_next = (m, n + gain)
                    # 이제 막 (i+1)번째 toss가 끝났으므로,
                    # 영희는 (i+1)//2 번, 동수는 (i+1)//2 번 던진 상태
                    y_used = (i + 1) // 2
                    d_used = (i + 1) // 2

                # 남은 횟수
                y_left = K - y_used
                d_left = K - d_used

                # 점수 차
                diff = m_next - n_next
                if diff == 0:
                    # 동점이면 조기 종료 X, 계속 진행
                    states[i+1].add((m_next, n_next))
                    continue

                if diff > 0:
                    # 영희가 앞선 상태 → 동수가 뒤처진 상태
                    # 동수가 남은 d_left를 전부 성공해도 diff를 못 뒤집으면 종료
                    if diff > d_left:
                        final_scores.add((m_next, n_next))
                    else:
                        states[i+1].add((m_next, n_next))
                else:
                    # diff < 0 → 동수가 앞선 상태 → 영희가 뒤처진 상태
                    # 영희가 남은 y_left 전부 성공해도 -diff 못 뒤집으면 종료
                    if -diff > y_left:
                        final_scores.add((m_next, n_next))
                    else:
                        states[i+1].add((m_next, n_next))

    # 2K번 모두 던져서 (조기 종료 없이) 끝난 상태
    for (m, n) in states[2*K]:
        final_scores.add((m, n))

    # 쿼리 처리
    ans = []
    for _ in range(C):
        M, N = map(int, input().split())
        ans.append('1' if (M, N) in final_scores else '0')

    print('\n'.join(ans))

def main():
    solve()

if __name__ == "__main__":
    main()
