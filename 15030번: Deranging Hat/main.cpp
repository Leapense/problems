#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    int n = S.size();
    string T = S;
    sort(T.begin(), T.end());

    unordered_map<char, queue<int>> pos;
    for (int i = 0; i < n; i++)
    {
        pos[T[i]].push(i);
    }

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        char c = S[i];
        A[i] = pos[c].front();
        pos[c].pop();
    }

    vector<int> Q(n);
    for (int i = 0; i < n; i++)
    {
        Q[A[i]] = i;
    }

    vector<char> cur(T.begin(), T.end());
    vector<bool> used(n, false);
    vector<pair<int, int>> ops;

    auto swapIdx = [&](int i, int j)
    {
        if (cur[i] <= cur[j])
        {
            ops.push_back({j + 1, i + 1});
        }
        else
        {
            ops.push_back({i + 1, j + 1});
        }

        swap(cur[i], cur[j]);
    };

    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        int curIdx = i;
        vector<int> cycle;

        while (!used[curIdx])
        {
            used[curIdx] = true;
            cycle.push_back(curIdx);
            curIdx = Q[curIdx];
        }

        if (cycle.size() <= 1)
            continue;
        for (size_t j = 1; j < cycle.size(); j++)
        {
            swapIdx(cycle[0], cycle[j]);
        }
    }

    for (auto &p : ops)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}