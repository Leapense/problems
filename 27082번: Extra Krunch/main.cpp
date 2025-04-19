#include <bits/stdc++.h>
using namespace std;

string krunch(const string &line)
{
    bool seen[26] = {};
    string mid;
    mid.reserve(line.size());
    for (char c : line)
    {
        if (c == ' ')
        {
            mid.push_back(' ');
            continue;
        }
        if (c == '.' || c == ',' || c == '?')
        {
            mid.push_back(c);
            continue;
        }
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            continue;
        int idx = c - 'A';
        if (!seen[idx])
        {
            seen[idx] = true;
            mid.push_back(c);
        }
    }
    string out;
    out.reserve(mid.size());
    for (size_t i = 0; i < mid.size(); ++i)
    {
        char c = mid[i];
        if (c == ' ')
        {
            if (out.empty())
                continue;
            size_t j = i + 1;
            while (j < mid.size() && mid[j] == ' ')
                ++j;
            if (j == mid.size())
                break;
            if (mid[j] == '.' || mid[j] == ',' || mid[j] == '?')
                continue;
            if (!out.empty() && out.back() == ' ')
                continue;
            out.push_back(' ');
        }
        else
            out.push_back(c);
    }
    if (!out.empty() && out.back() == ' ')
        out.pop_back();
    return out;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    cout << krunch(s) << '\n';
    return 0;
}
#endif