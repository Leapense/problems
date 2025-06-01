#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    if (!(cin >> Q)) {
        return 0; // 입력이 없으면 종료
    }

    // 최대 격자 칸 수 400 (20x20)이므로 정적으로 잡아도 충분
    static int prevDP[400];
    static int currDP[400];

    for (int queryIndex = 0; queryIndex < Q; ++queryIndex) {
        int rows, cols, steps, moduloP;
        cin >> rows >> cols >> steps >> moduloP;

        // 파라미터 유효성 검사
        if (rows < 1 || rows > 20 ||
            cols < 1 || cols > 20 ||
            steps < 1 || steps > 1000 ||
            moduloP < 1 || moduloP > 1000000) {
            // 잘못된 요청이면 0으로 응답 (API라면 HTTP 400)
            cout << 0 << "\n";
            continue;
        }

        // 칸 수 N
        const int N = rows * cols;

        // steps == 1인 경우: 첫 점프만 → 모든 칸에 1가지씩
        if (steps == 1) {
            int result = N % moduloP;
            cout << result << "\n";
            continue;
        }

        // DP 초기화: 첫 점프(단계 1)
        for (int i = 0; i < N; ++i) {
            prevDP[i] = 1;
        }

        // 방향 오프셋: 위, 아래, 왼쪽, 오른쪽, 제자리
        constexpr array<int, 5> dr = { -1, +1,  0,  0, 0 };
        constexpr array<int, 5> dc = {  0,  0, -1, +1, 0 };

        // 단계 2부터 steps까지 DP 누적
        for (int stepIdx = 2; stepIdx <= steps; ++stepIdx) {
            // currDP 초기화
            for (int i = 0; i < N; ++i) {
                currDP[i] = 0;
            }

            // 각 (r, c) 칸이 목표(target)인 경우
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    int targetIdx = r * cols + c;
                    int accumulator = 0;

                    // 5방향 원소 합산
                    for (int d = 0; d < 5; ++d) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];

                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                            int fromIdx = nr * cols + nc;
                            accumulator += prevDP[fromIdx];
                            if (accumulator >= moduloP) {
                                accumulator %= moduloP;
                            }
                        }
                    }
                    currDP[targetIdx] = (accumulator % moduloP);
                }
            }

            // prevDP 갱신
            for (int i = 0; i < N; ++i) {
                prevDP[i] = currDP[i];
            }
        }

        // 최종 합산
        int64_t sumWays = 0;
        for (int i = 0; i < N; ++i) {
            sumWays += prevDP[i];
            if (sumWays >= static_cast<int64_t>(moduloP) * 1000) {
                // 너무 커질 수 있으므로 주기적 모듈로 연산
                sumWays %= moduloP;
            }
        }
        int result = static_cast<int>(sumWays % moduloP);
        cout << result << "\n";
    }

    return 0;
}
