#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, k;
    if (!(cin >> n >> k)) return 0;

    vector<vector<string>> prefNames(n);
    for (size_t i = 0; i < n; ++i) {
        size_t q;
        cin >> q;
        prefNames[i].resize(q);
        for (auto& s : prefNames[i]) cin >> s;
    }

    size_t p;
    cin >> p;
    vector<string> rankNames(p);
    unordered_map<string, size_t> idOf;
    idOf.reserve(p * 2);
    for (size_t i = 0; i < p; ++i) {
        cin >> rankNames[i];
        idOf.emplace(rankNames[i], i);
    }

    vector<vector<size_t>> pref(n);
    pref.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        pref[i].reserve(prefNames[i].size());
        for (const auto& s : prefNames[i]) pref[i].push_back(idOf[s]);
    }

    vector<size_t> prefPtr(n, 0);
    size_t rankPtr = 0;
    vector<char> taken(p, 0);
    vector<vector<size_t>> roster(n, vector<size_t>());
    for (auto& v : roster) v.reserve(k);
    for (size_t round = 0; round < k; ++round) 
    {
        for (size_t owner = 0; owner < n; ++owner) {
            size_t pick;
            auto& vec = pref[owner];
            auto& idx = prefPtr[owner];
            while (idx < vec.size() && taken[vec[idx]]) ++idx;
            if (idx < vec.size()) {
                pick = vec[idx++];
            } else {
                while (taken[rankPtr]) ++rankPtr;
                pick = rankPtr;
            }
            taken[pick] = 1;
            roster[owner].push_back(pick);
        }
    }

    string out;
    out.reserve(n * k * 14);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < k; ++j) {
            out.append(rankNames[roster[i][j]]);
            if (j + 1 < k) out.push_back(' ');
        }

        if (i + 1 < n) out.push_back('\n');
    }
    cout << out;
    return 0;
}