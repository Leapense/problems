#include <bits/stdc++.h>
using namespace std;

void solve(istream &cin, ostream &cout)
{
    string line;
    getline(cin, line); // "swi's cake is missing!"
    int N;
    cin >> N;
    vector<string> names(N);
    for (int i = 0; i < N; i++)
    {
        cin >> names[i];
    }
    int M;
    cin >> M;
    unordered_set<string> seen;
    seen.reserve(M * 2);
    for (int i = 0; i < M; i++)
    {
        string x;
        cin >> x;
        seen.insert(x);
    }

    // Rule 1: dongho
    for (auto &s : names)
    {
        if (s == "dongho")
        {
            cout << "dongho\n";
            return;
        }
    }

    // 목격되지 않은 후보들
    vector<string> unwitnessed;
    unwitnessed.reserve(N);
    for (auto &s : names)
    {
        if (!seen.count(s))
        {
            unwitnessed.push_back(s);
        }
    }

    // Rule 2: 단 한 명
    if (unwitnessed.size() == 1)
    {
        cout << unwitnessed[0] << "\n";
        return;
    }
    // Rule 3~5
    for (auto &target : {"bumin", "cake", "lawyer"})
    {
        for (auto &s : unwitnessed)
        {
            if (s == target)
            {
                cout << s << "\n";
                return;
            }
        }
    }
    // Rule 6: 사전순 최소
    sort(unwitnessed.begin(), unwitnessed.end());
    cout << unwitnessed.front() << "\n";
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
#endif