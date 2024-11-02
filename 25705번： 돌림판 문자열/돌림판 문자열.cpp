#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int N, M;
    string wheel, S;

    cin >> N;
    cin >> wheel;
    cin >> M;
    cin >> S;

    vector<vector<int>> dist(N, vector<int>(M + 1, INF));
    queue<pair<int, int>> q;

    int start_pos = N - 1;
    dist[start_pos][0] = 0;
    q.push({start_pos, 0});

    while (!q.empty()) {
        int pos = q.front().first;
        int len = q.front().second;
        q.pop();

        if (len == M) continue;

        int pos_next = (pos + 1) % N;
        int cost_next = dist[pos][len] + 1;

        if (S[len] == wheel[pos_next] && dist[pos_next][len + 1] > cost_next) {
            dist[pos_next][len + 1] = cost_next;
            q.push({pos_next, len + 1});
        }

        if (dist[pos_next][len] > cost_next) {
            dist[pos_next][len] = cost_next;
            q.push({pos_next, len});
        }
    }

    int min_cost = INF;
    for (int i = 0; i < N; ++i) {
        if (dist[i][M] < min_cost) {
            min_cost = dist[i][M];
        }
    }

    if (min_cost == INF) {
        cout << -1 << '\n';
    } else {
        cout << min_cost << '\n';
    }

    return 0;
}