#include <bits/stdc++.h>
using namespace std;

static vector<string> split_colon(const string& s) {
    vector<string> res;
    if (s.empty()) return res;
    size_t i = 0;
    while (i < s.size()) {
        size_t j = s.find(':', i);
        if (j == string::npos) j = s.size();
        res.emplace_back(s.substr(i, j - i));
        i = j + 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    if (!getline(cin, s)) return 0;

    size_t pos = s.find("::");
    vector<string> left, right;

    if (pos != string::npos) {
        string L = s.substr(0, pos);
        string R = s.substr(pos + 2);
        left = split_colon(L);
        right = split_colon(R);
    } else {
        left = split_colon(s);
    }

    int zeros = (pos != string::npos) ? 8 - int(left.size() + right.size()) : 0;
    vector<string> out;
    out.reserve(8);
    for (auto& g : left) out.emplace_back(g);
    for (int i = 0; i < zeros; ++i) out.emplace_back("0");
    for (auto& g : right) out.emplace_back(g);

    for (size_t i = 0; i < out.size(); ++i) {
        if (i) cout << ':';
        const string& g = out[i];
        for (size_t k = g.size(); k < 4; ++k) cout << '0';
        cout << g;
    }
    cout << '\n';
    return 0;
}