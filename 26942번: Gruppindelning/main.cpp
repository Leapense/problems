#include<bits/stdc++.h>
using namespace std;

int solve(istream& in = cin, ostream& out = cout) {
    int n;
    if (!(in >> n)) return 0;
    vector<string> name(n);
    unordered_map<string, int> id;
    for (int i = 0; i < n; ++i) {
        in >> name[i];
        id[name[i]] = i;
    }

    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    function<int(int)> find = [&](int x) { return parent[x] == x ? x : parent[x] = find(parent[x]);};
    auto unite = [&](int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[b] = a;
    };

    int m;
    in >> m;
    for (int i = 0; i < m; ++i) {
        string a, b;
        in >> a >> b;
        unite(id[a], id[b]);
    }

    unordered_set<int> comp;
    for (int i = 0; i < n; ++i) comp.insert(find(i));
    out << comp.size() << "\n";
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return solve();
}
