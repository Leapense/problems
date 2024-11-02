#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Update {
    int T;
    int division;
    int delta_Nb;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N; // 학급 수
        cin >> N;
        if (N == 0) break;

        vector<vector<int>> counts(N, vector<int>(1001, 0));
        vector<int> total_students(N, 0);
        vector<int> Nb(N, 0);
        vector<int> diff(N, 0);

        int total_D = 0;
        int total_students_all = 0;

        vector<Update> updates;

        for (int i = 0; i < N; ++i) {
            int Ki; // 학급 i의 학생 수
            cin >> Ki;
            total_students[i] = Ki;
            total_students_all += Ki;

            for (int j = 0; j < Ki; ++j) {
                int score;
                cin >> score;
                counts[i][score]++;
            }

            // 초기 diff_i 계산
            diff[i] = total_students[i];
            total_D += diff[i];

            // 업데이트 리스트 생성
            for (int s = 0; s <= 1000; ++s) {
                if (counts[i][s] > 0) {
                    updates.push_back({s, i, counts[i][s]});
                }
            }
        }

        // 업데이트 리스트를 점수 T 기준으로 정렬
        sort(updates.begin(), updates.end(), [](const Update &a, const Update &b) {
            return a.T < b.T;
        });

        int min_D = total_D;
        int current_T = -1;
        size_t idx = 0;
        while (idx < updates.size()) {
            int T = updates[idx].T;
            // 같은 T를 가진 업데이트들을 처리
            while (idx < updates.size() && updates[idx].T == T) {
                int i = updates[idx].division;
                int delta_Nb = updates[idx].delta_Nb;

                int old_diff = diff[i];
                Nb[i] += delta_Nb;
                diff[i] = abs(2 * Nb[i] - total_students[i]);
                total_D += diff[i] - old_diff;

                ++idx;
            }
            // 최소 차이 갱신
            if (total_D < min_D) {
                min_D = total_D;
            }
        }

        cout << min_D << '\n';
    }

    return 0;
}