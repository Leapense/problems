#include <bits/stdc++.h>
using namespace std;

static vector<string> split(const string& s, char delim)
{
    vector<string> res;
    size_t i = 0, n = s.size();

    while (i <= n) {
        size_t j = s.find(delim, i);
        if (j == string::npos) j = n;
        res.push_back(s.substr(i, j - i));
        i = j + 1;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    const string DBL = "::";
    size_t pos = s.find(DBL);

    vector<string> groups;

    if (pos != string::npos) {
        string left = s.substr(0, pos);
        string right = s.substr(pos + DBL.size());
        vector<string> L = left.empty() ? vector<string>() : split(left, ':');
        vector<string> R = right.empty() ? vector<string>() : split(right, ':');

        int needZeros = 8 - (int(L.size()) + int(R.size()));
        groups.reserve(8);

        for (auto &g : L) groups.push_back(g);
        for (int i = 0; i < needZeros; i++) groups.push_back("0");
        for (auto &g : R) groups.push_back(g);
    } else {
        groups = split(s, ':');
    }

    for (auto &g : groups) {
        int pad = 4 - (int)g.size();
        g = string(pad, '0') + g;
    }

    for (int i = 0; i < 8; i++) {
        cout << groups[i] << (i + 1 < 8 ? ":" : "\n");
    }

    return 0;
}