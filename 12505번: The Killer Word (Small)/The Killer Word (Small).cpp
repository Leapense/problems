#include <bits/stdc++.h>
using namespace std;

pair<int, int> dfs(int k, string& L, vector<int> words, vector<vector<int>>& masks) {
    if (words.size() == 1) return make_pair(0, words[0]);

    map<int, vector<int>> m;
    for (int i = 0; i < words.size(); i++) {
        int mask = masks[L[k] - 'a'][words[i]];
        m[mask].push_back(words[i]);
    }

    pair<int, int> best(0, 10000);

    for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
        pair<int, int> cur = dfs(k + 1, L, (*it).second, masks);

        if (words.size() != (*it).second.size() && (*it).first == 0) {
            cur.first--;
        }

        best = min(best, cur);
    }

    return best;
}

string solve(int N, int M, vector<string>& D, string L) {
    vector<vector<int>> mask(26, vector<int>(D.size()));
    for (int c = 0; c < 26; c++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < D[i].size(); j++) {
                mask[D[i][j] - 'a'][i] |= (1 << j);
            }
        }
    }

    vector<int> v[10];

    for (int i = 0; i < D.size(); i++) {
        v[D[i].size() - 1].push_back(i);
    }

    pair<int, int> best = make_pair(0, 1000);
    for (int i = 0; i < 10; i++) {
        if (v[i].size() != 0) {
            best = min(best, dfs(0, L, v[i], mask));
        }
    }

    return D[best.second];
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;

        vector<string> D(N);

        for (int i = 0; i < N; i++) cin >> D[i];

        vector<string> L(M);

        for (int i = 0; i < M; i++) cin >> L[i];

        cout << "Case #" << t + 1 << ": ";

        for (int i = 0; i < L.size(); i++) {
            string ans = solve(N, M, D, L[i]);

            cout << ans << " ";
        }

        cout << endl;
    }

    return 0;
}