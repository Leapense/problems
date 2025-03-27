#include <iostream>
#include <vector>
#include <stack>
#include "main.h"
using namespace std;
int solve(int N, int M, const vector<int> &bosses, const vector<int> &tablePersons)
{
    vector<vector<int>> children(N + 1);
    int ceo = 0;
    for (int i = 1; i <= N; i++)
    {
        int b = bosses[i - 1];
        if (b == 0)
        {
            ceo = i;
        }
        else
        {
            children[b].push_back(i);
        }
    }
    vector<bool> table(N + 1, false);
    for (auto person : tablePersons)
    {
        table[person] = true;
    }
    int count = 0;
    stack<pair<int, bool>> s;
    s.push({ceo, false});
    while (!s.empty())
    {
        auto [node, flag] = s.top();
        s.pop();
        bool newFlag = flag || table[node];
        if (table[node] && !flag)
            count++;
        for (auto child : children[node])
        {
            s.push({child, newFlag});
        }
    }
    return count;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> bosses(N);
    for (int i = 0; i < N; i++)
    {
        cin >> bosses[i];
    }
    vector<int> tablePersons(M);
    for (int i = 0; i < M; i++)
    {
        cin >> tablePersons[i];
    }
    cout << solve(N, M, bosses, tablePersons) << "\n";
    return 0;
}
#endif