import sys

def main():
    import sys
    import threading

    def run():
        import sys

        N = int(sys.stdin.readline())
        teams = []
        for idx in range(N):
            parts = sys.stdin.readline().strip().split()
            C = parts[0]
            P = int(parts[1])
            E = list(map(int, parts[2:8]))
            prog = P * 10
            tramp = sum(E) - max(E) - min(E)
            total = prog + tramp
            teams.append((total, idx, C))  # (총 점수, 입력 순서, 팀 코드)

        # 정렬: 총 점수 내림차순, 입력 순서 오름차순
        teams_sorted = sorted(teams, key=lambda x: (-x[0], x[1]))

        score_rank = {}
        higher_count = 0
        previous_score = None

        for team in teams_sorted:
            score = team[0]
            if score != previous_score:
                score_rank[score] = higher_count
                previous_score = score
            higher_count +=1

        # 메달리스트 선정: score_rank <=2
        medallists = []
        for team in teams:
            total = team[0]
            if score_rank[total] <=2:
                medallists.append(team)

        # 정렬: 총 점수 내림차순, 입력 순서 오름차순
        medallists_sorted = sorted(medallists, key=lambda x: (-x[0], x[1]))

        # 출력
        for team in medallists_sorted:
            print(f"{team[2]} {team[0]}")

    run()

if __name__ == "__main__":
    main()
