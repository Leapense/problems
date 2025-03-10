#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <cctype>

using namespace std;

string toLower(const string &s)
{
    string res;
    for (char c : s)
        res.push_back(tolower(c));
    return res;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        vector<pair<string, int>> cans(n);
        for (int i = 0; i < n; i++)
        {
            cin >> cans[i].first >> cans[i].second;
        }

        sort(cans.begin(), cans.end(), [](auto &a, auto &b)
             {
            if (a.second != b.second) return a.second > b.second;
            return toLower(a.first) < toLower(b.first); });
        deque<string> d;
        bool left = true;

        d.push_back(cans[0].first);
        for (size_t i = 1; i < cans.size(); i++)
        {
            if (left)
            {
                d.push_front(cans[i].first);
                left = false;
            }
            else
            {
                d.push_back(cans[i].first);
                left = true;
            }
        }

        for (auto it = d.begin(); it != d.end(); ++it)
        {
            cout << *it;
            if (next(it) != d.end())
                cout << " ";
        }

        cout << "\n";
    }

    return 0;
}