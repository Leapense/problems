#include <bits/stdc++.h>
using namespace std;

static int toMin(const string& hhmm) {
    int h = stoi(hhmm.substr(0,2));
    int m = stoi(hhmm.substr(3,2));
    return h * 60 + m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    int W = M / 7;

    struct Week { int cnt = 0; long long mins = 0; };
    unordered_map<string, vector<Week>> mp;
    mp.reserve(256);

    for (int i = 0; i < N; i++) {
        string name, s, e;
        int day;
        cin >> name >> day >> s >> e;
        int w = (day - 1) / 7;
        int dur = toMin(e) - toMin(s);
        auto &vec = mp[name];
        if ((int)vec.size() < W) vec.resize(W);
        vec[w].cnt += 1;
        vec[w].mins += dur;
    }

    vector<string> ans;
    for (auto &kv : mp) {
        const auto &weeks = kv.second;
        bool ok = true;
        if ((int)weeks.size() < W) {
            ok = false;
        } else {
            for (int w = 0; w < W; ++w) {
                if (weeks[w].cnt < 5 || weeks[w].mins < 3600) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) ans.push_back(kv.first);
    }
    sort(ans.begin(), ans.end());
    if (ans.empty()) {
        cout << -1 << '\n';
    } else {
        for (auto &s : ans) cout << s << '\n';
    }

    return 0;
}