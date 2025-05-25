#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<bool> usedSet(26, false);
    vector<vector<int>> adj(26);
    vector<bitset<26>> contains(26);

    string X, dummy, S;
    for (int i = 0; i < N; ++i)
    {
        cin >> X >> dummy >> S;
        int u = X[0] - 'A';
        usedSet[u] = true;

        if (S.size() == 1 && isupper(S[0]))
        {
            int v = S[0] - 'A';
            usedSet[v] = true;
            adj[v].push_back(u);
        }
        else if (S.size() == 1 && islower(S[0]))
        {
            int e = S[0] - 'a';
            contains[u].set(e);
        }
    }

    queue<pair<int, int>> q;

    for (int u = 0; u < 26; ++u)
    {
        for (int e = 0; e < 26; ++e)
        {
            if (contains[u].test(e))
            {
                q.emplace(u, e);
            }
        }
    }

    while (!q.empty())
    {
        auto [u, e] = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!contains[v].test(e))
            {
                contains[v].set(e);
                q.emplace(v, e);
            }
        }
    }

    for (int u = 0; u < 26; ++u)
    {
        if (!usedSet[u])
        {
            continue;
        }

        cout << char('A' + u) << " = {";
        bool first = true;
        for (int e = 0; e < 26; ++e)
        {
            if (contains[u].test(e))
            {
                if (!first)
                {
                    cout << ",";
                }
                cout << char('a' + e);
                first = false;
            }
        }

        cout << "}\n";
    }

    return 0;
}