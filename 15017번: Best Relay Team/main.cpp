//=====================================================================
//   15017번:    Best Relay Team                   
//   @date:   2024-10-12              
//   @link:   https://www.acmicpc.net/problem/15017  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

struct Runner {
    string name;
    double a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Runner> runners(n);

    for (int i = 0; i < n; ++i) {
        cin >> runners[i].name >> runners[i].a >> runners[i].b;
    }

    vector<int> sorted_b(n);

    for (int i = 0; i < n; ++i) sorted_b[i] = i;

    sort(sorted_b.begin(), sorted_b.end(), [&](int x, int y) -> bool {
        if (abs(runners[x].b - runners[y].b) > 1e-9) return runners[x].b < runners[y].b;
        return x < y;
    });

    double min_time = 1e18;
    int first_runner = -1;

    vector<int> other_runners(3);

    for (int i = 0; i < n; ++i) {
        double sum_b = 0.0;
        vector<int> selected;

        for (auto j : sorted_b) {
            if (j != i) {
                sum_b += runners[j].b;
                selected.push_back(j);
                if (selected.size() == 3) break;
            }
        }

        double total_time = runners[i].a + sum_b;

        if (total_time < min_time) {
            min_time = total_time;
            first_runner = i;
            other_runners = selected;
        }
    }

    cout << fixed << setprecision(6) << min_time << "\n";
    cout << runners[first_runner].name << "\n";

    for (auto j : other_runners) {
        cout << runners[j].name << "\n";
    }

    return 0;
}