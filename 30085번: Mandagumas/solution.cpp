#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, const vector<char> &ops)
{
    deque<int> dq;

    for (int i = 1; i <= N; ++i)
        dq.push_back(i);
    bool rev = false;

    for (char c : ops)
    {
        if (c == 'A')
        {
            if (!rev)
            {
                int x = dq.front();
                dq.pop_front();
                dq.push_back(x);
            }
            else
            {
                int x = dq.back();
                dq.pop_back();
                dq.push_front(x);
            }
        }
        else
        {
            rev = !rev;
        }
    }
    if (rev)
        reverse(dq.begin(), dq.end());
    return vector<int>(dq.begin(), dq.end());
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N))
        return 0;
    cin >> M;
    vector<char> ops(M);
    for (int i = 0; i < M; ++i)
        cin >> ops[i];

    auto ans = solve(N, ops);
    for (int x : ans)
        cout << x << "\n";
    return 0;
}
#endif