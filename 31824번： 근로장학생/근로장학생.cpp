#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<string, string>> info(N);
    for (int i = 0; i < N; i++)
    {
        cin >> info[i].first >> info[i].second;
    }

    while (M--)
    {
        string S;
        cin >> S;
        string result = "";
        int len = S.size();

        for (int pos = 0; pos < len; pos++)
        {
            vector<pair<string, string>> matches;

            for (auto &p : info)
            {
                const string &Q = p.first;
                const string &A = p.second;
                if (pos + Q.size() <= S.size() && S.substr(pos, Q.size()) == Q)
                {
                    matches.push_back({Q, A});
                }
            }

            sort(matches.begin(), matches.end(), [](const pair<string, string> &a, const pair<string, string> &b)
                 { return a.first < b.first; });

            for (auto &match : matches)
            {
                result += match.second;
            }
        }

        if (result.empty())
        {
            cout << "-1\n";
        }
        else
        {
            cout << result << "\n";
        }
    }

    return 0;
}