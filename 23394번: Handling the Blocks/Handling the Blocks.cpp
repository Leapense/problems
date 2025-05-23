#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> blocks(N);
    for (auto &p : blocks)
        cin >> p.first >> p.second;

    vector<vector<int>> color_current(K + 1);
    vector<vector<int>> color_required(K + 1);

    for (int i = 0; i < N; i++)
        color_current[blocks[i].second].push_back(blocks[i].first);

    for (int i = 1; i <= N; i++)
        color_required[blocks[i - 1].second].push_back(i);

    bool possible = true;

    for (int c = 1; c <= K; c++)
    {
        vector<int> curr = color_current[c];
        vector<int> req = color_required[c];

        sort(curr.begin(), curr.end());
        sort(req.begin(), req.end());

        if (curr != req)
        {
            possible = false;
            break;
        }
    }

    cout << (possible ? 'Y' : 'N') << endl;

    return 0;
}