#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> hands;

    for (int i = 1; i <= M; ++i) {
        int h1, h2;
        cin >> h1 >> h2;
        hands.emplace_back(h1, i);
        hands.emplace_back(h2, i);
    }

    sort(hands.begin(), hands.end(), [&](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        return a.first < b.first;
    });

    deque<pair<int, int>> dq;
    for (auto &p : hands) {
        dq.emplace_back(p);
    }

    vector<int> moved_participants;
    for (int step = 1; step <= N; ++step) {
        if (dq.empty()) {
            break;
        }

        pair<int, int> current = dq.front();
        dq.pop_front();
        dq.emplace_back(current);
        moved_participants.emplace_back(current.second);
    }

    if (N <= moved_participants.size()) {
        cout << moved_participants[N - 1];
    } else {
        cout << "-1";
    }

    return 0;
}