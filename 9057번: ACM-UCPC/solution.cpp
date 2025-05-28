// 2025-05-28, C++26 (Clang 17 이상)
// SonarQube C++ rule-set 지침을 따름
#include <bits/stdc++.h>

using namespace std;

struct Team {
    string name;
    string school;
    int solved {};
    int penalty {};
};

static constexpr int MAX_PICK = 60;

static bool rank_cmp(const Team &a, const Team &b) {
    if (a.solved != b.solved) { return a.solved > b.solved; }
    return a.penalty < b.penalty;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc {};
    cin >> tc;
    while (tc-- > 0) {
        int n {};
        cin >> n;

        vector<Team> teams(n);
        for (auto &t : teams) {
            cin >> t.name >> t.school >> t.solved >> t.penalty;
        }

        // 안전성: 혹시 모를 입력 오류에 대비
        ranges::sort(teams, rank_cmp);

        unordered_map<string, int> school_total;
        for (const auto &t : teams) { ++school_total[t.school]; }

        unordered_map<string, int> school_selected;
        vector<bool> picked(n, false);
        int picked_cnt = 0;
        string worst_team;

        auto school_limit = [&](const string &s) {
            return (school_total[s] + 1) / 2;        // ceil
        };

        auto school_cap_ok = [&](const string &s, int rank) {
            const int cur = school_selected[s];
            if (cur >= school_limit(s)) { return false; }
            if (rank <= 10)  { return cur <= 3; }
            if (rank <= 20)  { return cur <= 2; }
            if (rank <= 30)  { return cur <= 1; }
            return cur == 0;
        };

        // ---------- 1차 선발 ----------
        for (int i = 0; i < n && picked_cnt < MAX_PICK; ++i) {
            if (school_cap_ok(teams[i].school, i + 1)) {
                picked[i] = true;
                ++school_selected[teams[i].school];
                ++picked_cnt;
                worst_team = teams[i].name;
            }
        }

        // ---------- 2차 충원 ----------
        for (int i = 0; i < n && picked_cnt < min(MAX_PICK, n); ++i) {
            if (picked[i]) { continue; }
            const string &sch = teams[i].school;
            if (school_selected[sch] < school_limit(sch)) {
                picked[i] = true;
                ++school_selected[sch];
                ++picked_cnt;
                worst_team = teams[i].name;
            }
        }

        // ---------- 출력 ----------
        cout << worst_team << '\n';
    }
    return 0;
}
