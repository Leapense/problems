#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    deque<int> deck[2];
    vector<int> ground[2];
    ground[0].reserve(60000);
    ground[1].reserve(60000);

    for (int i = 0; i < N; ++i) {
        int d, s;
        cin >> d >> s;
        deck[0].push_front(d);
        deck[1].push_front(s);
    }

    auto collect = [&](int w) {
        int o = 1 - w;
        for (auto it = ground[o].rbegin(); it != ground[o].rend(); ++it) deck[w].push_back(*it);
        ground[o].clear();
        for (auto it = ground[w].rbegin(); it != ground[w].rend(); ++it) deck[w].push_back(*it);
        ground[w].clear();
    };

    int player = 0;
    for (int t = 0; t < M; ++t) {
        if (deck[player].empty()) {
            cout << (player ? "do\n" : "su\n");
            return 0;
        }
        int card = deck[player].front();
        deck[player].pop_front();
        ground[player].push_back(card);

        int winner = -1;
        if (card == 5) winner = 0;
        else if (!ground[0].empty() && !ground[1].empty() &&
                 ground[0].back() + ground[1].back() == 5)
            winner = 1;
        if (winner != -1) collect(winner);

        player ^= 1;
    }

    if (deck[0].size() > deck[1].size()) cout << "do\n";
    else if (deck[0].size() < deck[1].size()) cout << "su\n";
    else cout << "dosu\n";
    return 0;
}