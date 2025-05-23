#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int time_to_minutes(const string& s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h * 60 + m;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> trams(n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        trams[i] = time_to_minutes(s);
    }

    vector<pair<int, int>> passengers(m);

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        passengers[i] = {time_to_minutes(s), i};
    }

    vector<int> answer(m, -1);

    queue<int> q;

    int p_ptr = 0;

    for (int i = 0; i < n; ++i) {
        int tram_time = trams[i];

        while(p_ptr < m && passengers[p_ptr].first <= tram_time) {
            q.push(passengers[p_ptr].second);
            p_ptr++;
        }

        int cnt = 0;

        while(!q.empty() && cnt < k) {
            int passenger_idx = q.front();
            q.pop();

            if (answer[passenger_idx] == -1) {
                answer[passenger_idx] = i + 1;
                cnt++;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << answer[i] << "\n";
    }

    return 0;
}