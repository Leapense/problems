#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

void solve(istream &in, ostream &out)
{
    int N, M;
    in >> N >> M;
    int S, E;
    in >> S >> E;

    vector<vector<int>> tele(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        in >> u >> v;
        tele[u].push_back(v);
        tele[v].push_back(u);
    }

    vector<int> dist(N + 1, -1);
    queue<int> q;
    dist[S] = 0;
    q.push(S);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == E)
        {
            out << dist[cur];
            return;
        }
        if (cur > 1 && dist[cur - 1] == -1)
        {
            dist[cur - 1] = dist[cur] + 1;
            q.push(cur - 1);
        }
        if (cur < N && dist[cur + 1] == -1)
        {
            dist[cur + 1] = dist[cur] + 1;
            q.push(cur + 1);
        }

        for (auto nxt : tele[cur])
        {
            if (dist[nxt] == -1)
            {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

#ifdef UNIT_TEST
#include <cassert>
int main()
{
    vector<pair<string, string>> tests = {
        {"2 0\n1 2\n", "1"},
        {"5 1\n1 5\n1 4\n", "2"},
        {"10 3\n2 5\n1 6\n1 3\n2 8\n", "3"},
        {"6 2\n1 6\n1 6\n3 5\n", "1"},
        {"100 0\n1 100\n", "99"},
        {"10 5\n2 9\n2 7\n7 9\n3 8\n1 5\n4 6\n", "2"},
        {"7 3\n3 7\n3 5\n3 6\n5 7\n", "2"},
        {"8 2\n2 8\n2 3\n5 6\n", "6"}};

    for (auto &tc : tests)
    {
        istringstream iss(tc.first);
        ostringstream oss;
        solve(iss, oss);
        if (oss.str() != tc.second)
        {
            cout << "Test failed. Input:\n"
                 << tc.first << "\nExpected:\n"
                 << tc.second << "\nGot:\n"
                 << oss.str() << "\n";

            return 1;
        }
    }

    cout << "All tests passed.\n";
    return 0;
}
#else
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
#endif